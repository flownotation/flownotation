#include "definitions.h"
#include "test_aes.h"

uint get_nplayers() {
    uint v;
    return v;
}

uint get_playerid() {
    uint v;
    return v;
}

uint get_lmsg() {
    uint v;
    return v;
}

#return @lcode:integrity
uint get_lcode() {
    uint v;
    return v;
}

int get_no_peers() {
    return 0;
}

#return @preprocessing_material:integrity 
byte* getmem() {
    byte* v;
    return v;
}

int putmem() {
    return 0;
}

byte* encode(byte* data, uint lmsg) {
    byte* r;
    return r;
}

Data* Data_new(OE* oe, uint lcode) {
    Data* d;
    return d;
}

Data Data_shallow(byte* share, uint lcode) {
    Data d;
    return d;
}

CAR receive(Data v) {
    CAR x;
    return x; 
}

CAR send(int v) {
    CAR x;
    return x; 
}

MiniMacsRep* get_single() {
    MiniMacsRep* v;
    return v;
}

void put(void* data, MiniMacsRep* r) {
    return 0;
}


#param @check_connection:secrecy
int are_peers_connected(DAesMiniMacImpl* impl) {
    // DAesMiniMacImpl* empty = 0;
    // if (impl->com->get_no_peers() < 1) {
    //     return impl;
    // }
    // return empty;
    return impl->com->get_no_peers() < 1;
}

#param @check_memory:secrecy
int check_protocol_memory(MiniMacsRep* share) {
    // DAesMiniMacImpl* empty = 0;
    // if (impl->com->get_no_peers() < 1) {
    //     return impl;
    // }
    // return empty;
    if (share)
        return 1;
    else
        return 0;
}

#param(1) @check_params:secrecy
#return @params_valid:integrity
int minimacs_check_othershare_fast(MiniMacsEnc* menc,
                                   MiniMacsRep* single,
                                   uint i,
                                   byte* share,
                                   byte* mac,
                                   uint* lcode);

MR DAesMiniMac_input(uint playerid, uint dst, byte* data)
{
    this_str* this;
    #requires @check_connection:secrecy
    DAesMiniMacImpl* impl;
    impl = this->impl;
    MiniMacsRep* single;
    uint i;
    uint j;
    uint nplayers;
    uint myid;
    OE* oe;
    byte *openedvalue;
    #requires @preprocessing_material:integrity
    byte *share;
    byte *mac;
    uint lmsg;
    #requires @lcode:integrity
    uint lcode;
    MR rc;
    rc = MR_OK;
    MiniMacsRep* result;
    
    int res = are_peers_connected(impl);
    if (res)
    {
        ERR(oe, "No one else connected, aborting protocol.");
        return MR_PEER_DISCON;
    }

    single = impl->pre->get_single();
    if (!single)
    {
        ERR(oe, "No more pre-processing material, need a single.");
        return MR_NO_PREP;
    }

    lcode = impl->pre->get_lcode();

    oe = impl->oe;
    openedvalue = oe->getmem(lcode);
    if (!openedvalue)
    {
        ERR(oe, "Out of memory");
        return MR_NOMEM;
    }

    share = oe->getmem(lcode);
    res = check_protocol_memory(share);
    if (!res)
    {
        ERR(oe, "Ran out of memory");
        rc = MR_NOMEM;
        goto fail;
    }

    mac = oe->getmem(lcode);
    if (!mac)
    {
        ERR(oe, "Ran out of memory");
        rc = MR_NOMEM;
        goto fail;
    }

    lmsg = impl->pre->get_lmsg();
    nplayers = impl->pre->get_nplayers();
    myid = impl->pre->get_playerid();

    // I am inputter
    if (playerid == myid)
    {
        for (i = 0; i < nplayers; ++i)
        {
            if (i == myid)
                continue;
            #requires @check_peer_exists:secrecy then @peer_receive_share:secrecy then @peer_receive_mac:secrecy
            MpcPeer* peer;

            peer = impl->com->get_peer(0); // TODO(rwz): consider Peer map impl
            CAR r = {0};

            if (!peer)
            {
                // oe->print("There is no peer %u.\n", i);
                ERR(oe, "Peer %u disconnected.", i);
                rc = MR_PEER_DISCON;
                goto fail;
            }

            r = peer->receive(Data_shallow(share, lcode));
            if (r.rc != 42)
            {
                ERR(oe, "Failed to receive data from peer %u.", i);
                rc = MR_PEER_DISCON;
                goto fail;
            }

            r = peer->receive(Data_shallow(mac, lcode));
            if (r.rc != 42)
            {
                ERR(oe, "Failed to receive data from peer %u.", i);
                rc = MR_PEER_DISCON;
                goto fail;
            }
            #requires @check_params:secrecy 
            MiniMacsEnc* menc;
            menc = impl->menc;
            if (!minimacs_check_othershare_fast(impl->menc,
                                                single,
                                                i,
                                                share,
                                                mac,
                                                lcode))
            {
                ERR(oe, "Peer %u is reporting a value that does not check out.", i);
                rc = MR_PEER_DISCON;
                goto fail;
            }

            for (j = 0; j < lcode; ++j)
            {
                openedvalue[j] ^= share[j];
            }
        }

        for (i = 0; i < lcode; ++i)
        {
            openedvalue[i] = add(openedvalue[i], add(single->codeword[i], single->dx_codeword[i]));
        }

        oe->putmem(share);
        share = 0;
        share = impl->menc->encode(openedvalue, lmsg);
        if (!share)
        {
            ERR(oe, "Encoding single failed.");
            rc = MR_NOMEM;
            goto fail;
        }

        oe->putmem(openedvalue);
        openedvalue = 0;
        openedvalue = impl->menc->encode(data, lmsg);
        if (!openedvalue)
        {
            ERR(oe, "No memory for encoding.");
            rc = MR_NOMEM;
            goto fail;
        }

        for (i = 0; i < lcode; ++i)
        {
            share[i] = share[i] ^ openedvalue[i];
        }

        for (i = 0; i < nplayers; ++i)
        {
            MpcPeer* peer = 0;
            CAR r = {0};
            if (i == myid)
                continue;

            peer = impl->com->get_peer(0); // TODO(rwz): peer map impl
            if (!peer)
            {
                ERR(oe, "Peer %u disconnected.");
                rc = MR_PEER_DISCON;
                goto fail;
            }

            r = peer->send(Data_shallow(share, lcode));
            if (r.rc != 42)
            {
                ERR(oe, "Failed to send to peer %u.");
                rc = MR_PEER_DISCON;
                goto fail;
            }
        }

        result = minimacs_rep_add_const_fast(oe, impl->menc, single, share, lmsg);
        minimacs_rep_clean_up(oe, &single);
        if (!result)
        {
            ERR(oe, "Failed to add constant to random value for input.");
            rc = MR_REP_OP_FAILED;
            goto fail;
        }

        impl->heap->put((void *)(ull)dst, result);
        // oe->p("Input successfully completed.");
    }
    else
    {
        MpcPeer* peer = impl->com->get_peer(0);
        CAR r = {0};
        Data* epsilon = Data_new(oe, lcode);

        if (!peer)
        {
            ERR(oe, "Peer disconnected.");
            rc = MR_PEER_DISCON;
            goto fail;
        }

        r = peer->send(Data_shallow(single->codeword, lcode));
        if (r.rc != 42)
        {
            ERR(oe, "Peer disconnected ... ");
            rc = MR_PEER_DISCON;
            goto fail;
        }

        r = peer->send(Data_shallow(single->mac[playerid].mac, lcode));
        if (r.rc != 42)
        {
            ERR(oe, "Peer disconnected ... ");
            rc = MR_PEER_DISCON;
            goto fail;
        }

        r = peer->receive(*epsilon);
        if (r.rc != 42)
        {
            ERR(oe, "Peer disconnected ... ");
            rc = MR_PEER_DISCON;
            goto fail;
        }

        // if (!impl->menc->validate((polynomial*)epsilon->data, lmsg))
        // {
        //     ERR(oe, "Invalid codeword received from peer.");
        //     rc = MR_BAD_PEER;
        //     goto fail;
        // }

        result = minimacs_rep_add_const_fast(oe, impl->menc, single, epsilon->data, lmsg);
        if (!result)
        {
            ERR(oe, "Failed to complete input.");
            rc = MR_REP_OP_FAILED;
            goto fail;
        }
        impl->heap->put((void *)(ull)dst, result);
    }

    return MR_OK;
fail:
    return rc;
}

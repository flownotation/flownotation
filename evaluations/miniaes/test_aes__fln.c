typedef int byte;
typedef int ull;
typedef int uint;
typedef struct 
{
  int x;
} rcon;
typedef struct 
{
  int x;
} CheetahSBox;
typedef struct 
{
  int x;
} MATRIX;
typedef struct 
{
  int x;
} CheetahKBox;
typedef struct 
{
  int x;
} DateTime;
typedef struct 
{
  int x;
} DerInputStream;
typedef struct 
{
  int x;
} List;
typedef struct 
{
  int x;
} CheetahDVal;
typedef struct 
{
  int x;
} RC;
typedef struct 
{
  int x;
} bedoza_mac;
typedef struct 
{
  int x;
} FD;
typedef struct 
{
  int x;
} CheetahLVal;
typedef enum 
{
  MR_OK = 0,
  MR_BAD_ARGS = 1,
  MR_HEAP_NOT_AVAIL = 2,
  MR_NOT_IMPL = 3,
  MR_PEER_DISCON = 4,
  MR_REP_OP_FAILED = 5,
  MR_BAD_PEER = 6,
  MR_NO_PREP = 7,
  MR_NOMEM = 8,
  MR_WRONG_MAC = 9
} MR;
typedef struct 
{
  byte *(*getmem)();
  int (*putmem)();
} OE;
typedef struct 
{
  int data;
} Data;
typedef struct 
{
  int rc;
} CAR;
typedef struct 
{
  byte *(*encode)(byte *data, uint lmsg);
} MiniMacsEnc;
typedef struct MiniMacsRep
{
  int codeword[32];
  int dx_codeword[32];
  struct MiniMacsRep *mac;
} MiniMacsRep;
typedef struct 
{
  void (*put)(void *data, MiniMacsRep *r);
} Map;
typedef struct 
{
  CAR (*receive)(Data v);
  CAR (*send)(Data v);
} MpcPeer;
typedef struct 
{
  int (*get_no_peers)();
  int (*get_peer)(int n);
} CArena;
typedef struct 
{
  MiniMacsRep *(*get_single)();
  uint (*get_nplayers)();
  uint (*get_playerid)();
  uint (*get_lmsg)();
  uint (*get_lcode)();
} AesPreprocessing;
typedef struct 
{
  OE *oe;
  Map *heap;
  MiniMacsEnc *menc;
  MiniMacsEnc *smenc;
  CArena *com;
  AesPreprocessing *pre;
} DAesMiniMacImpl;
typedef struct 
{
  AesPreprocessing *pre;
  DAesMiniMacImpl *impl;
} this_str;
typedef struct 
{
  byte d;
} __fln__preprocessing_materialI_byte;
typedef struct 
{
  MiniMacsRep d;
} __fln__check_memoryS_MiniMacsRep;
typedef struct 
{
  MiniMacsEnc d;
} __fln__check_paramsS_MiniMacsEnc;
typedef struct 
{
  int d;
} __fln__params_validI_int;
typedef struct 
{
  uint d;
} __fln__lcodeI_uint;
typedef struct 
{
  DAesMiniMacImpl d;
} __fln__check_connectionS_DAesMiniMacImpl;
typedef struct 
{
  MpcPeer d;
} __fln__check_peer_existsS_peer_receive_shareS_peer_receive_macS_MpcPeer;
__fln__preprocessing_materialI_byte __fln__preprocessing_materialI_byte_intg(byte x)
{
  __fln__preprocessing_materialI_byte y = {.d = x};
  return y;
}

__fln__preprocessing_materialI_byte *__fln__preprocessing_materialI_byte_intg_ptr(byte *x)
{
  __fln__preprocessing_materialI_byte tmp = {.d = *x};
  __fln__preprocessing_materialI_byte *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

byte __fln__preprocessing_materialI_byte_sec(__fln__preprocessing_materialI_byte x)
{
  return x.d;
}

byte *__fln__preprocessing_materialI_byte_sec_ptr(__fln__preprocessing_materialI_byte *x)
{
  return &x->d;
}

__fln__check_memoryS_MiniMacsRep __fln__check_memoryS_MiniMacsRep_intg(MiniMacsRep x)
{
  __fln__check_memoryS_MiniMacsRep y = {.d = x};
  return y;
}

__fln__check_memoryS_MiniMacsRep *__fln__check_memoryS_MiniMacsRep_intg_ptr(MiniMacsRep *x)
{
  __fln__check_memoryS_MiniMacsRep tmp = {.d = *x};
  __fln__check_memoryS_MiniMacsRep *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

MiniMacsRep __fln__check_memoryS_MiniMacsRep_sec(__fln__check_memoryS_MiniMacsRep x)
{
  return x.d;
}

MiniMacsRep *__fln__check_memoryS_MiniMacsRep_sec_ptr(__fln__check_memoryS_MiniMacsRep *x)
{
  return &x->d;
}

__fln__check_paramsS_MiniMacsEnc __fln__check_paramsS_MiniMacsEnc_intg(MiniMacsEnc x)
{
  __fln__check_paramsS_MiniMacsEnc y = {.d = x};
  return y;
}

__fln__check_paramsS_MiniMacsEnc *__fln__check_paramsS_MiniMacsEnc_intg_ptr(MiniMacsEnc *x)
{
  __fln__check_paramsS_MiniMacsEnc tmp = {.d = *x};
  __fln__check_paramsS_MiniMacsEnc *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

MiniMacsEnc __fln__check_paramsS_MiniMacsEnc_sec(__fln__check_paramsS_MiniMacsEnc x)
{
  return x.d;
}

MiniMacsEnc *__fln__check_paramsS_MiniMacsEnc_sec_ptr(__fln__check_paramsS_MiniMacsEnc *x)
{
  return &x->d;
}

__fln__params_validI_int __fln__params_validI_int_intg(int x)
{
  __fln__params_validI_int y = {.d = x};
  return y;
}

__fln__params_validI_int *__fln__params_validI_int_intg_ptr(int *x)
{
  __fln__params_validI_int tmp = {.d = *x};
  __fln__params_validI_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

int __fln__params_validI_int_sec(__fln__params_validI_int x)
{
  return x.d;
}

int *__fln__params_validI_int_sec_ptr(__fln__params_validI_int *x)
{
  return &x->d;
}

__fln__lcodeI_uint __fln__lcodeI_uint_intg(uint x)
{
  __fln__lcodeI_uint y = {.d = x};
  return y;
}

__fln__lcodeI_uint *__fln__lcodeI_uint_intg_ptr(uint *x)
{
  __fln__lcodeI_uint tmp = {.d = *x};
  __fln__lcodeI_uint *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

uint __fln__lcodeI_uint_sec(__fln__lcodeI_uint x)
{
  return x.d;
}

uint *__fln__lcodeI_uint_sec_ptr(__fln__lcodeI_uint *x)
{
  return &x->d;
}

__fln__check_connectionS_DAesMiniMacImpl __fln__check_connectionS_DAesMiniMacImpl_intg(DAesMiniMacImpl x)
{
  __fln__check_connectionS_DAesMiniMacImpl y = {.d = x};
  return y;
}

__fln__check_connectionS_DAesMiniMacImpl *__fln__check_connectionS_DAesMiniMacImpl_intg_ptr(DAesMiniMacImpl *x)
{
  __fln__check_connectionS_DAesMiniMacImpl tmp = {.d = *x};
  __fln__check_connectionS_DAesMiniMacImpl *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

DAesMiniMacImpl __fln__check_connectionS_DAesMiniMacImpl_sec(__fln__check_connectionS_DAesMiniMacImpl x)
{
  return x.d;
}

DAesMiniMacImpl *__fln__check_connectionS_DAesMiniMacImpl_sec_ptr(__fln__check_connectionS_DAesMiniMacImpl *x)
{
  return &x->d;
}

__fln__check_peer_existsS_peer_receive_shareS_peer_receive_macS_MpcPeer __fln__check_peer_existsS_peer_receive_shareS_peer_receive_macS_MpcPeer_intg(MpcPeer x)
{
  __fln__check_peer_existsS_peer_receive_shareS_peer_receive_macS_MpcPeer y = {.d = x};
  return y;
}

__fln__check_peer_existsS_peer_receive_shareS_peer_receive_macS_MpcPeer *__fln__check_peer_existsS_peer_receive_shareS_peer_receive_macS_MpcPeer_intg_ptr(MpcPeer *x)
{
  __fln__check_peer_existsS_peer_receive_shareS_peer_receive_macS_MpcPeer tmp = {.d = *x};
  __fln__check_peer_existsS_peer_receive_shareS_peer_receive_macS_MpcPeer *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

MpcPeer __fln__check_peer_existsS_peer_receive_shareS_peer_receive_macS_MpcPeer_sec(__fln__check_peer_existsS_peer_receive_shareS_peer_receive_macS_MpcPeer x)
{
  return x.d;
}

MpcPeer *__fln__check_peer_existsS_peer_receive_shareS_peer_receive_macS_MpcPeer_sec_ptr(__fln__check_peer_existsS_peer_receive_shareS_peer_receive_macS_MpcPeer *x)
{
  return &x->d;
}

uint get_nplayers()
{
  uint v;
  return v;
}

uint get_playerid()
{
  uint v;
  return v;
}

uint get_lmsg()
{
  uint v;
  return v;
}

__fln__lcodeI_uint get_lcode()
{
  uint v;
  return __fln__lcodeI_uint_intg(v);
}

int get_no_peers()
{
  return 0;
}

__fln__preprocessing_materialI_byte *getmem()
{
  byte *v;
  return __fln__preprocessing_materialI_byte_intg_ptr(v);
}

int putmem()
{
  return 0;
}

byte *encode(byte *data, uint lmsg)
{
  byte *r;
  return r;
}

Data *Data_new(OE *oe, uint lcode)
{
  Data *d;
  return d;
}

Data Data_shallow(byte *share, uint lcode)
{
  Data d;
  return d;
}

CAR receive(Data v)
{
  CAR x;
  return x;
}

CAR send(int v)
{
  CAR x;
  return x;
}

MiniMacsRep *get_single()
{
  MiniMacsRep *v;
  return v;
}

void put(void *data, MiniMacsRep *r)
{
  return 0;
}

int are_peers_connected(__fln__check_connectionS_DAesMiniMacImpl *impl)
{
  DAesMiniMacImpl* impl__fln_p = __fln__check_connectionS_DAesMiniMacImpl_sec_ptr(impl);
  return impl__fln_p->com->get_no_peers() < 1;
}

int check_protocol_memory(__fln__check_memoryS_MiniMacsRep *share)
{
  MiniMacsRep* share__fln_p = __fln__check_memoryS_MiniMacsRep_sec_ptr(share);
  if (share__fln_p)
    return 1;
  else
    return 0;

}

int minimacs_check_othershare_fast(MiniMacsEnc *menc, MiniMacsRep *single, uint i, byte *share, byte *mac, uint *lcode);
MR DAesMiniMac_input(uint playerid, uint dst, byte *data)
{
  this_str *this;
  __fln__check_connectionS_DAesMiniMacImpl *impl;
  impl = __fln__check_connectionS_DAesMiniMacImpl_intg_ptr(this->impl);
  MiniMacsRep *single;
  uint i;
  uint j;
  uint nplayers;
  uint myid;
  OE *oe;
  byte *openedvalue;
  byte *share__fln_1;
  byte *mac;
  uint lmsg;
  __fln__lcodeI_uint lcode;
  MR rc;
  rc = MR_OK;
  MiniMacsRep *result;
  int res = are_peers_connected(impl);
  if (res)
  {
    ERR(oe, "No one else connected, aborting protocol.");
    return MR_PEER_DISCON;
  }

  single = impl->d.pre->get_single();
  if (!single)
  {
    ERR(oe, "No more pre-processing material, need a single.");
    return MR_NO_PREP;
  }

  lcode = impl->d.pre->get_lcode();
  oe = impl->d.oe;
  openedvalue = oe->getmem(__fln__lcodeI_uint_sec(lcode));
  if (!openedvalue)
  {
    ERR(oe, "Out of memory");
    return MR_NOMEM;
  }

  share = oe->getmem(__fln__lcodeI_uint_sec(lcode));
  res = check_protocol_memory(share);
  if (!res)
  {
    ERR(oe, "Ran out of memory");
    rc = MR_NOMEM;
    goto fail;
  }

  mac = oe->getmem(__fln__lcodeI_uint_sec(lcode));
  if (!mac)
  {
    ERR(oe, "Ran out of memory");
    rc = MR_NOMEM;
    goto fail;
  }

  lmsg = impl->d.pre->get_lmsg();
  nplayers = impl->d.pre->get_nplayers();
  myid = impl->d.pre->get_playerid();
  if (playerid == myid)
  {
    for (i = 0; i < nplayers; ++i)
    {
      if (i == myid)
        continue;

      __fln__check_peer_existsS_peer_receive_shareS_peer_receive_macS_MpcPeer *peer;
      peer = __fln__check_peer_existsS_peer_receive_shareS_peer_receive_macS_MpcPeer_intg_ptr(impl->d.com->get_peer(0));
      CAR r = {0};
      if (!peer)
      {
        ERR(oe, "Peer %u disconnected.", i);
        rc = MR_PEER_DISCON;
        goto fail;
      }

      r = peer->d.receive(Data_shallow(share, __fln__lcodeI_uint_sec(lcode)));
      if (r.rc != 42)
      {
        ERR(oe, "Failed to receive data from peer %u.", i);
        rc = MR_PEER_DISCON;
        goto fail;
      }

      r = peer->d.receive(Data_shallow(mac, __fln__lcodeI_uint_sec(lcode)));
      if (r.rc != 42)
      {
        ERR(oe, "Failed to receive data from peer %u.", i);
        rc = MR_PEER_DISCON;
        goto fail;
      }

      __fln__check_paramsS_MiniMacsEnc *menc;
      menc = __fln__check_paramsS_MiniMacsEnc_intg_ptr(impl->d.menc);
      if (!minimacs_check_othershare_fast(impl->d.menc, single, i, share, mac, __fln__lcodeI_uint_sec(lcode)))
      {
        ERR(oe, "Peer %u is reporting a value that does not check out.", i);
        rc = MR_PEER_DISCON;
        goto fail;
      }

      for (j = 0; j < __fln__lcodeI_uint_sec(lcode); ++j)
      {
        openedvalue[j] ^= share[j];
      }

    }

    for (i = 0; i < __fln__lcodeI_uint_sec(lcode); ++i)
    {
      openedvalue[i] = add(openedvalue[i], add(single->codeword[i], single->dx_codeword[i]));
    }

    oe->putmem(share);
    share = 0;
    share = impl->d.menc->encode(openedvalue, lmsg);
    if (!share)
    {
      ERR(oe, "Encoding single failed.");
      rc = MR_NOMEM;
      goto fail;
    }

    oe->putmem(openedvalue);
    openedvalue = 0;
    openedvalue = impl->d.menc->encode(data, lmsg);
    if (!openedvalue)
    {
      ERR(oe, "No memory for encoding.");
      rc = MR_NOMEM;
      goto fail;
    }

    for (i = 0; i < __fln__lcodeI_uint_sec(lcode); ++i)
    {
      share[i] = share[i] ^ openedvalue[i];
    }

    for (i = 0; i < nplayers; ++i)
    {
      MpcPeer *peer = 0;
      CAR r = {0};
      if (i == myid)
        continue;

      peer = __fln__check_peer_existsS_peer_receive_shareS_peer_receive_macS_MpcPeer_intg_ptr(impl->d.com->get_peer(0));
      if (!peer)
      {
        ERR(oe, "Peer %u disconnected.");
        rc = MR_PEER_DISCON;
        goto fail;
      }

      r = peer->d.send(Data_shallow(share, __fln__lcodeI_uint_sec(lcode)));
      if (r.rc != 42)
      {
        ERR(oe, "Failed to send to peer %u.");
        rc = MR_PEER_DISCON;
        goto fail;
      }

    }

    result = minimacs_rep_add_const_fast(oe, impl->d.menc, single, share, lmsg);
    minimacs_rep_clean_up(oe, &single);
    if (!result)
    {
      ERR(oe, "Failed to add constant to random value for input.");
      rc = MR_REP_OP_FAILED;
      goto fail;
    }

    impl->d.heap->put((void *) ((ull) dst), result);
  }
  else
  {
    MpcPeer *peer = impl->d.com->get_peer(0);
    CAR r = {0};
    Data *epsilon = Data_new(oe, __fln__lcodeI_uint_sec(lcode));
    if (!peer)
    {
      ERR(oe, "Peer disconnected.");
      rc = MR_PEER_DISCON;
      goto fail;
    }

    r = peer->d.send(Data_shallow(single->codeword, __fln__lcodeI_uint_sec(lcode)));
    if (r.rc != 42)
    {
      ERR(oe, "Peer disconnected ... ");
      rc = MR_PEER_DISCON;
      goto fail;
    }

    r = peer->d.send(Data_shallow(single->mac[playerid].mac, __fln__lcodeI_uint_sec(lcode)));
    if (r.rc != 42)
    {
      ERR(oe, "Peer disconnected ... ");
      rc = MR_PEER_DISCON;
      goto fail;
    }

    r = peer->d.receive(*epsilon);
    if (r.rc != 42)
    {
      ERR(oe, "Peer disconnected ... ");
      rc = MR_PEER_DISCON;
      goto fail;
    }

    result = minimacs_rep_add_const_fast(oe, impl->d.menc, single, epsilon->data, lmsg);
    if (!result)
    {
      ERR(oe, "Failed to complete input.");
      rc = MR_REP_OP_FAILED;
      goto fail;
    }

    impl->d.heap->put((void *) ((ull) dst), result);
  }

  return MR_OK;
  fail:
  return rc;

}


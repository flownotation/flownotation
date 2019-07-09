#ifndef TEST_AES_H
#define TEST_AES_H

typedef int byte;
typedef int ull;
typedef int uint;
typedef struct { int x; } rcon;
typedef struct { int x; } CheetahSBox;
typedef struct { int x; } MATRIX;
typedef struct { int x; } CheetahKBox;
typedef struct { int x; } DateTime;
typedef struct { int x; } DerInputStream;
typedef struct { int x; } List;
typedef struct { int x; } CheetahDVal;
typedef struct { int x; } RC;
typedef struct { int x; } bedoza_mac;
typedef struct { int x; } FD;
typedef struct { int x; } CheetahLVal;

typedef enum {
    // operation successful
    MR_OK = 0,

    // argument is invalid
    MR_BAD_ARGS = 1,

    // heap value not set
    MR_HEAP_NOT_AVAIL = 2,

    // Not implemented
    MR_NOT_IMPL = 3,

    // Peer has left
    MR_PEER_DISCON = 4,

    // xor or and failed
    MR_REP_OP_FAILED = 5,

    // Wrong peer
    MR_BAD_PEER = 6,

    // ran out of preprocessing material
    MR_NO_PREP = 7,

    // Out of memory
    MR_NOMEM = 8,

    // Cheate or comm. error detected
    MR_WRONG_MAC = 9,
} MR;

typedef struct {
    byte* (*getmem)();
    int (*putmem)();
} OE;

typedef struct {
    int data;
} Data;

typedef struct {
    int rc;
} CAR;

typedef struct {
    byte* (*encode)(byte* data, uint lmsg);
} MiniMacsEnc;

typedef struct MiniMacsRep {
    int codeword[32];
    int dx_codeword[32];
    struct MiniMacsRep* mac;
} MiniMacsRep;

typedef struct {
    void (*put)(void* data, MiniMacsRep* r);
} Map;

typedef struct { 
    CAR (*receive)(Data v);
    CAR (*send)(Data v);
} MpcPeer;

typedef struct {
    int (*get_no_peers)();
    int (*get_peer)(int n);
} CArena;

typedef struct {
    MiniMacsRep* (*get_single)();
    uint (*get_nplayers)();
    uint (*get_playerid)();
    uint (*get_lmsg)();
    uint (*get_lcode)();
} AesPreprocessing;

typedef struct
{
    OE* oe;
    Map* heap;
    MiniMacsEnc* menc;
    MiniMacsEnc* smenc;
    CArena* com;
    AesPreprocessing* pre;
} DAesMiniMacImpl;

typedef struct {
    AesPreprocessing* pre;
    DAesMiniMacImpl* impl;
} this_str;

#endif
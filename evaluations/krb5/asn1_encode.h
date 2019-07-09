#ifndef __ASN1_ENCODE_H__
#define __ASN1_ENCODE_H__

// #include "k5-int.h"
// #include "asn1buf.h"
#include "../../src/pycparser/utils/fake_libc_include/stdio.h"
#include "../../src/pycparser/utils/fake_libc_include/errno.h"
#include "../../src/pycparser/utils/fake_libc_include/limits.h"        /* For INT_MAX */
#include "../../src/pycparser/utils/fake_libc_include/stdlib.h"

// ------------ FLN Added ----------
#define krb5_octet int
#define krb5_error_code int
typedef struct {
    int x;
} asn1buf;
#define ENOMEM 0
void abort() { return; }
void assert() { return; }
// void* LOADPTR(void* val, const struct ptr_info* info) { return val; }
// ---------------------------------

/*
 * If KRB5_MSGTYPE_STRICT is defined, then be strict about checking
 * the msgtype fields.  Unfortunately, there old versions of Kerberos
 * don't set these fields correctly, so we have to make allowances for
 * them.
 */
/* #define KRB5_MSGTYPE_STRICT */

/*
 * If KRB5_GENEROUS_LR_TYPE is defined, then we are generous about
 * accepting a one byte negative lr_type - which is not sign
 * extended. Prior to July 2000, we were sending a negative lr_type as
 * a positve single byte value - instead of a signed integer. This
 * allows us to receive the old value and deal
 */

#define KRB5_GENEROUS_LR_TYPE

typedef krb5_octet asn1_octet;
typedef krb5_error_code asn1_error_code;

typedef enum { PRIMITIVE = 0x00, CONSTRUCTED = 0x20 } asn1_construction;

typedef enum { UNIVERSAL = 0x00, APPLICATION = 0x40,
               CONTEXT_SPECIFIC = 0x80, PRIVATE = 0xC0 } asn1_class;

typedef int asn1_tagnum;
#define ASN1_TAGNUM_CEILING INT_MAX
#define ASN1_TAGNUM_MAX (ASN1_TAGNUM_CEILING-1)

/* This is Kerberos Version 5 */
#define KVNO 5

/* Universal Tag Numbers */
#define ASN1_BOOLEAN            1
#define ASN1_INTEGER            2
#define ASN1_BITSTRING          3
#define ASN1_OCTETSTRING        4
#define ASN1_NULL               5
#define ASN1_OBJECTIDENTIFIER   6
#define ASN1_ENUMERATED         10
#define ASN1_UTF8STRING         12
#define ASN1_SEQUENCE           16
#define ASN1_SET                17
#define ASN1_PRINTABLESTRING    19
#define ASN1_IA5STRING          22
#define ASN1_UTCTIME            23
#define ASN1_GENERALTIME        24
#define ASN1_GENERALSTRING      27

/* Kerberos Message Types */
#define ASN1_KRB_AS_REQ         10
#define ASN1_KRB_AS_REP         11
#define ASN1_KRB_TGS_REQ        12
#define ASN1_KRB_TGS_REP        13
#define ASN1_KRB_AP_REQ         14
#define ASN1_KRB_AP_REP         15
#define ASN1_KRB_SAFE           20
#define ASN1_KRB_PRIV           21
#define ASN1_KRB_CRED           22
#define ASN1_KRB_ERROR          30


typedef struct {
    asn1_class asn1class;
    asn1_construction construction;
    asn1_tagnum tagnum;

    /* When decoding, stores the leading and trailing lengths of a tag.  Used
     * by store_der(). */
    size_t tag_len;
    size_t tag_end_len;
} taginfo;

/* These functions are referenced by encoder structures.  They handle the
 * encoding of primitive ASN.1 types. */
asn1_error_code k5_asn1_encode_bool(asn1buf *buf, intmax_t val,
                                    size_t *len_out);
asn1_error_code k5_asn1_encode_int(asn1buf *buf, intmax_t val,
                                   size_t *len_out);
asn1_error_code k5_asn1_encode_uint(asn1buf *buf, uintmax_t val,
                                    size_t *len_out);
asn1_error_code k5_asn1_encode_bytestring(asn1buf *buf,
                                          unsigned char *const *val,
                                          size_t len, size_t *len_out);
asn1_error_code k5_asn1_encode_bitstring(asn1buf *buf,
                                         unsigned char *const *val,
                                         size_t len, size_t *len_out);
asn1_error_code k5_asn1_encode_generaltime(asn1buf *buf, time_t val,
                                           size_t *len_out);

/* These functions are referenced by encoder structures.  They handle the
 * decoding of primitive ASN.1 types. */
asn1_error_code k5_asn1_decode_bool(const unsigned char *asn1, size_t len,
                                    intmax_t *val);
asn1_error_code k5_asn1_decode_int(const unsigned char *asn1, size_t len,
                                   intmax_t *val);
asn1_error_code k5_asn1_decode_uint(const unsigned char *asn1, size_t len,
                                    uintmax_t *val);
asn1_error_code k5_asn1_decode_generaltime(const unsigned char *asn1,
                                           size_t len, time_t *time_out);
asn1_error_code k5_asn1_decode_bytestring(const unsigned char *asn1,
                                          size_t len, unsigned char **str_out,
                                          size_t *len_out);
asn1_error_code k5_asn1_decode_bitstring(const unsigned char *asn1, size_t len,
                                         unsigned char **bits_out,
                                         size_t *len_out);

/*
 * An atype_info structure specifies how to map a C object to an ASN.1 value.
 *
 * We wind up with a lot of load-time relocations being done, which is
 * a bit annoying.  Be careful about "fixing" that at the cost of too
 * much run-time performance.  It might work to have a master "module"
 * descriptor with pointers to various arrays (type descriptors,
 * strings, field descriptors, functions) most of which don't need
 * relocation themselves, and replace most of the pointers with table
 * indices.
 *
 * It's a work in progress.
 */

enum atype_type {
    /* For bounds checking only.  By starting with 2, we guarantee that
     * zero-initialized storage will be recognized as invalid. */
    atype_min = 1,
    /* Use a function table to handle encoding or decoding.  tinfo is a struct
     * fn_info *. */
    atype_fn = 2,
    /* C object is a pointer to the object to be encoded or decoded.  tinfo is
     * a struct ptr_info *. */
    atype_ptr = 3,
    /* C object to be encoded or decoded is at an offset from the original
     * pointer.  tinfo is a struct offset_info *. */
    atype_offset = 4,
    /*
     * Indicates a sequence field which may or may not be present in the C
     * object or ASN.1 sequence.  tinfo is a struct optional_info *.  Must be
     * used within a sequence, although the optional type may be nested within
     * offset, ptr, and/or tag types.
     */
    atype_optional = 5,
    /*
     * C object contains an integer and another C object at specified offsets,
     * to be combined and encoded or decoded as specified by a cntype_info
     * structure.  tinfo is a struct counted_info *.
     */
    atype_counted = 6,
    /* Sequence.  tinfo is a struct seq_info *. */
    atype_sequence = 7,
    /*
     * Sequence-of, with pointer to base type descriptor, represented as a
     * null-terminated array of pointers (and thus the "base" type descriptor
     * is actually an atype_ptr node).  tinfo is a struct atype_info * giving
     * the base type.
     */
    atype_nullterm_sequence_of = 8,
    atype_nonempty_nullterm_sequence_of = 9,
    /* Tagged version of another type.  tinfo is a struct tagged_info *. */
    atype_tagged_thing = 10,
    /* Boolean value.  tinfo is NULL (size field determines C type width). */
    atype_bool = 11,
    /* Signed or unsigned integer.  tinfo is NULL. */
    atype_int = 12,
    atype_uint = 13,
    /*
     * Integer value taken from the type info, not from the object being
     * encoded.  tinfo is a struct immediate_info * giving the integer value
     * and error code to return if a decoded object doesn't match it (or 0 if
     * the value shouldn't be checked on decode).
     */
    atype_int_immediate = 14,
    /* Unused except for bounds checking.  */
    atype_max = 15
};

struct atype_info {
    enum atype_type type;
    size_t size;                /* Used for sequence-of processing */
    const void *tinfo;          /* Points to type-specific structure */
};

struct fn_info {
    asn1_error_code (*enc)(asn1buf *, const void *, taginfo *, size_t *);
    asn1_error_code (*dec)(const taginfo *, const unsigned char *, size_t,
                           void *);
    int (*check_tag)(const taginfo *);
    void (*free_func)(void *);
};

struct ptr_info {
    void *(*loadptr)(const void *);
    void (*storeptr)(void *, void *);
    const struct atype_info *basetype;
};

struct offset_info {
    unsigned int dataoff : 9;
    const struct atype_info *basetype;
};

struct optional_info {
    int (*is_present)(const void *);
    void (*init)(void *);
    const struct atype_info *basetype;
};

struct counted_info {
    unsigned int dataoff : 9;
    unsigned int lenoff : 9;
    unsigned int lensigned : 1;
    unsigned int lensize : 5;
    const struct cntype_info *basetype;
};

struct tagged_info {
    unsigned int tagval : 16, tagtype : 8, construction : 6, implicit : 1;
    const struct atype_info *basetype;
};

struct immediate_info {
    intmax_t val;
    asn1_error_code err;
};

/* A cntype_info structure specifies how to map a C object and count (length or
 * union distinguisher) to an ASN.1 value. */

enum cntype_type {
    cntype_min = 1,

    /*
     * Apply an encoder function (contents only) and wrap it in a universal
     * primitive tag.  The C object must be a char * or unsigned char *.  tinfo
     * is a struct string_info *.
     */
    cntype_string = 2,

    /*
     * The C object is a DER encoding (with tag), to be simply inserted on
     * encode or stored on decode.  The C object must be a char * or unsigned
     * char *.  tinfo is NULL.
     */
    cntype_der = 3,

    /* An ASN.1 sequence-of value, represtened in C as a counted array.  struct
     * atype_info * giving the base type, which must be of type atype_ptr. */
    cntype_seqof = 4,

    /* An ASN.1 choice, represented in C as a distinguisher and union.  tinfo
     * is a struct choice_info *. */
    cntype_choice = 5,

    cntype_max = 6
};

struct cntype_info {
    enum cntype_type type;
    const void *tinfo;
};

struct string_info {
    asn1_error_code (*enc)(asn1buf *, unsigned char *const *, size_t,
                           size_t *);
    asn1_error_code (*dec)(const unsigned char *, size_t, unsigned char **,
                           size_t *);
    unsigned int tagval : 5;
};

struct choice_info {
    const struct atype_info **options;
    size_t n_options;
};

struct seq_info {
    const struct atype_info **fields;
    size_t n_fields;
    /* Currently all sequences are assumed to be extensible. */
};

/**** Functions for freeing C objects based on type info ****/

static void free_atype_ptr(const struct atype_info *a, void *val);
static void free_sequence(const struct seq_info *seq, void *val);
static void free_sequence_of(const struct atype_info *eltinfo, void *val,
                             size_t count);
static void free_cntype(const struct cntype_info *a, void *val, size_t count);

#endif
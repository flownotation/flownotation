/* -*- mode: c; c-basic-offset: 4; indent-tabs-mode: nil -*- */
/* lib/krb5/asn.1/asn1_encode.c */
/*
 * Copyright 1994, 2008 by the Massachusetts Institute of Technology.
 * All Rights Reserved.
 *
 * Export of this software from the United States of America may
 *   require a specific license from the United States Government.
 *   It is the responsibility of any person or organization contemplating
 *   export to obtain such a license before exporting.
 *
 * WITHIN THAT CONSTRAINT, permission to use, copy, modify, and
 * distribute this software and its documentation for any purpose and
 * without fee is hereby granted, provided that the above copyright
 * notice appear in all copies and that both that copyright notice and
 * this permission notice appear in supporting documentation, and that
 * the name of M.I.T. not be used in advertising or publicity pertaining
 * to distribution of the software without specific, written prior
 * permission.  Furthermore if you modify this software you must label
 * your software as modified software and not distribute it in such a
 * fashion that it might be confused with the original M.I.T. software.
 * M.I.T. makes no representations about the suitability of
 * this software for any purpose.  It is provided "as is" without express
 * or implied warranty.
 */

/* -*- mode: c; c-basic-offset: 4; indent-tabs-mode: nil -*- */
/* lib/krb5/asn.1/asn1_encode.h */
/*
 * Copyright 1994, 2008 by the Massachusetts Institute of Technology.
 * All Rights Reserved.
 *
 * Export of this software from the United States of America may
 *   require a specific license from the United States Government.
 *   It is the responsibility of any person or organization contemplating
 *   export to obtain such a license before exporting.
 *
 * WITHIN THAT CONSTRAINT, permission to use, copy, modify, and
 * distribute this software and its documentation for any purpose and
 * without fee is hereby granted, provided that the above copyright
 * notice appear in all copies and that both that copyright notice and
 * this permission notice appear in supporting documentation, and that
 * the name of M.I.T. not be used in advertising or publicity pertaining
 * to distribution of the software without specific, written prior
 * permission.  Furthermore if you modify this software you must label
 * your software as modified software and not distribute it in such a
 * fashion that it might be confused with the original M.I.T. software.
 * M.I.T. makes no representations about the suitability of
 * this software for any purpose.  It is provided "as is" without express
 * or implied warranty.
 */
#include "asn1_encode.h"
/*
 * Free a C object according to a type description.  Do not free pointers at
 * the first level; they may be referenced by other fields of a sequence, and
 * will be freed by free_atype_ptr in a second pass.
 */
#param(1) @freebase:secrecy
#return @freeptr:secrecy
const struct atype_info* free_atype(const struct atype_info *a, void *val)
{
    // ---- FLN Added -----
    #requires @freebase:secrecy .then @freeptr:secrecy
    const struct atype_info* x;
    #requires @freebase:secrecy
    const struct atype_info* y;
    #requires @freecn:secrecy
    const struct cntype_info* c;
    #requires @freeseq:secrecy
    const struct seq_info* s;
    // --------------------
    switch (a->type) {
    case atype_fn: {
        const struct fn_info *fn = a->tinfo;
        if (fn->free_func != NULL)
            fn->free_func(val);
        break;
    }
    case atype_sequence:
        s = a->tinfo;
        free_sequence(s, val);
        break;
    case atype_ptr: {
        const struct ptr_info *ptrinfo = a->tinfo;
        void *ptr = LOADPTR(val, ptrinfo);
        if (ptr != NULL) {
            // ---- FLN Added -----
            x = ptrinfo->basetype;
            // --------------------
            free_atype(x, ptr);
            free_atype_ptr(x, ptr);
        }
        break;
    }
    case atype_offset: {
        const struct offset_info *off = a->tinfo;
        assert(off->basetype != NULL);
        // ---- FLN Added -----
        y = off->basetype;
        // --------------------
        free_atype(y, (char *)val + off->dataoff);
        break;
    }
    case atype_optional: {
        const struct optional_info *opt = a->tinfo;
        // ---- FLN Added -----
        y = opt->basetype;
        // --------------------
        free_atype(y, val);
        break;
    }
    case atype_counted: {
        const struct counted_info *counted = a->tinfo;
        void *dataptr = (char *)val + counted->dataoff;
        size_t count;
        if (load_count(val, counted, &count) == 0) {
            c = counted->basetype;
            free_cntype(c, dataptr, count);
        }
        break;
    }
    case atype_nullterm_sequence_of:
    case atype_nonempty_nullterm_sequence_of: {
        size_t count = get_nullterm_sequence_len(val, a->tinfo);
        free_sequence_of(a->tinfo, val, count);
        break;
    }
    case atype_tagged_thing: {
        const struct tagged_info *tag = a->tinfo;
        // ---- FLN Added -----
        y = tag->basetype;
        // --------------------
        free_atype(y, val);
        break;
    }
    case atype_bool:
    case atype_int:
    case atype_uint:
    case atype_int_immediate:
        break;
    default:
        abort();
    }
    return x;
}

#param(1) @freeptr:secrecy
static void free_atype_ptr(const struct atype_info *a, void *val)
{
    // ---- FLN Added -----
    #requires @freeptr:secrecy
    const struct atype_info* x;
    // --------------------
    switch (a->type) {
    case atype_fn:
    case atype_sequence:
    case atype_counted:
    case atype_nullterm_sequence_of:
    case atype_nonempty_nullterm_sequence_of:
    case atype_bool:
    case atype_int:
    case atype_uint:
    case atype_int_immediate:
         break;
    case atype_ptr: {
        const struct ptr_info *ptrinfo = a->tinfo;
        void *ptr = LOADPTR(val, ptrinfo);
        free(ptr);
        STOREPTR(NULL, ptrinfo, val);
        break;
    }
    case atype_offset: {
        const struct offset_info *off = a->tinfo;
        assert(off->basetype != NULL);
        // ---- FLN Added -----
        x = off->basetype;
        // --------------------
        free_atype_ptr(x, (char *)val + off->dataoff);
        break;
    }
    case atype_optional: {
        const struct optional_info *opt = a->tinfo;
        // ---- FLN Added -----
        x = opt->basetype;
        // --------------------
        free_atype_ptr(x, val);
        break;
    }
    case atype_tagged_thing: {
        const struct tagged_info *tag = a->tinfo;
        // ---- FLN Added -----
        x = tag->basetype;
        // --------------------
        free_atype_ptr(x, val);
        break;
    }
    default:
        abort();
    }
}

#param(1) @freecn:secrecy
static void free_cntype(const struct cntype_info *c, void *val, size_t count)
{
    // ---- FLN Added -----
    #requires @freebase:secrecy .then @freeptr:secrecy
    const struct atype_info* x;
    // --------------------
    switch (c->type) {
    case cntype_string:
    case cntype_der:
        free(*(char **)val);
        *(char **)val = NULL;
        break;
    case cntype_seqof: {
        const struct atype_info *a = c->tinfo;
        const struct ptr_info *ptrinfo = a->tinfo;
        void *seqptr = LOADPTR(val, ptrinfo);
        free_sequence_of(ptrinfo->basetype, seqptr, count);
        free(seqptr);
        STOREPTR(NULL, ptrinfo, val);
        break;
    }
    case cntype_choice: {
        const struct choice_info *choice = c->tinfo;
        if (count < choice->n_options) {
            // ---- FLN Added -----
            x = choice->options[count];
            // --------------------
            free_atype(x, val);
            free_atype_ptr(x, val);
        }
        break;
    }
    default:
        abort();
    }
}

#param(1) @freeseq:secrecy
static void free_sequence(const struct seq_info *seq, void *val)
{
    size_t i;
    // ---- FLN Added -----
    #requires @freebase:secrecy .then @freeptr:secrecy
    const struct atype_info* x;
    x = seq->fields;
    // --------------------
    for (i = 0; i < seq->n_fields; i++)
        free_atype(x[i], val);
    for (i = 0; i < seq->n_fields; i++)
        free_atype_ptr(x[i], val);
}

#param(1) @freebase:secrecy
static void free_sequence_of(const struct atype_info *eltinfo, void *val, size_t count)
{
    void *eltptr;

    assert(eltinfo->size != 0);
    // ---- FLN Added -----
    #requires @freebase:secrecy .then @freeptr:secrecy
    const struct atype_info* x;
    x = eltinfo;
    // --------------------
    while (count-- > 0) {
        eltptr = (char *)val + count * x->size;
        free_atype(x, eltptr);
        free_atype_ptr(x, eltptr);
    }
}

/**** Functions for decoding objects based on type info ****/

/* Return nonzero if t is an expected tag for an ASN.1 object of type a. */
static int
check_atype_tag(const struct atype_info *a, const taginfo *t)
{
    switch (a->type) {
    case atype_fn: {
        const struct fn_info *fn = a->tinfo;
        assert(fn->check_tag != NULL);
        return fn->check_tag(t);
    }
    case atype_sequence:
    case atype_nullterm_sequence_of:
    case atype_nonempty_nullterm_sequence_of:
        return (t->asn1class == UNIVERSAL && t->construction == CONSTRUCTED &&
                t->tagnum == ASN1_SEQUENCE);
    case atype_ptr: {
        const struct ptr_info *ptrinfo = a->tinfo;
        return check_atype_tag(ptrinfo->basetype, t);
    }
    case atype_offset: {
        const struct offset_info *off = a->tinfo;
        return check_atype_tag(off->basetype, t);
    }
    case atype_optional: {
        const struct optional_info *opt = a->tinfo;
        return check_atype_tag(opt->basetype, t);
    }
    case atype_counted: {
        const struct counted_info *counted = a->tinfo;
        switch (counted->basetype->type) {
        case cntype_string: {
            const struct string_info *string = counted->basetype->tinfo;
            return (t->asn1class == UNIVERSAL &&
                    t->construction == PRIMITIVE &&
                    t->tagnum == string->tagval);
        }
        case cntype_seqof:
            return (t->asn1class == UNIVERSAL &&
                    t->construction == CONSTRUCTED &&
                    t->tagnum == ASN1_SEQUENCE);
        case cntype_der:
            /*
             * We treat any tag as matching a stored DER encoding.  In some
             * cases we know what the tag should be; in others, we truly want
             * to accept any tag.  If it ever becomes an issue, we could add
             * optional tag info to the type and check it here.
             */
            return 1;
        case cntype_choice:
            /*
             * ASN.1 choices may or may not be extensible.  For now, we treat
             * all choices as extensible and match any tag.  We should consider
             * modeling whether choices are extensible before making the
             * encoder visible to plugins.
             */
            return 1;
        default:
            abort();
        }
    }
    case atype_tagged_thing: {
        const struct tagged_info *tag = a->tinfo;
        /* NOTE: Doesn't check construction bit for implicit tags. */
        if (!tag->implicit && t->construction != tag->construction)
            return 0;
        return (t->asn1class == tag->tagtype && t->tagnum == tag->tagval);
    }
    case atype_bool:
        return (t->asn1class == UNIVERSAL && t->construction == PRIMITIVE &&
                t->tagnum == ASN1_BOOLEAN);
    case atype_int:
    case atype_uint:
    case atype_int_immediate:
        return (t->asn1class == UNIVERSAL && t->construction == PRIMITIVE &&
                t->tagnum == ASN1_INTEGER);
    default:
        abort();
    }
}

/* Add a null pointer to the end of a sequence.  ptr is consumed on success
 * (to be replaced by *ptr_out), left alone on failure. */
static asn1_error_code
null_terminate(const struct atype_info *eltinfo, void *ptr, size_t count,
               void **ptr_out)
{
    const struct ptr_info *ptrinfo = eltinfo->tinfo;
    void *endptr;

    assert(eltinfo->type == atype_ptr);
    ptr = realloc(ptr, (count + 1) * eltinfo->size);
    if (ptr == NULL)
        return ENOMEM;
    endptr = (char *)ptr + count * eltinfo->size;
    STOREPTR(NULL, ptrinfo, endptr);
    *ptr_out = ptr;
    return 0;
}

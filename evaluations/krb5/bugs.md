# Sequencing requirements for freeing data structures

The mutually-calling functions free_atype and free_atype_ptr, allow for the safe freeing of a data structure based on its "type description" (a C enumeration built for Kerberos).

This is a secrecy requirement because we specify restrictions of what can access the atype_info based on what type description it is, and whether it is a pointer type.

## Annotations
```
#param(1) @freebase:secrecy
static void free_atype(const struct atype_info *a, void *val)
```
```
#requires @freebase:secrecy .then @freeptr:secrecy
const struct atype_info* x;
#requires @freebase:secrecy
const struct atype_info* y;
```
```
#param(1) @freeptr:secrecy
static void free_atype_ptr(const struct atype_info *a, void *val)
```
```
#requires @freeptr:secrecy
const struct atype_info* x;
```

## Helper Functions
None

## Error Messages
```
evaluations/krb5/asn1_encode__fln.c: In function ‘free_sequence’:
evaluations/krb5/asn1_encode__fln.c:681:16: warning: passing argument 1 of ‘free_atype’ from incompatible pointer type [-Wincompatible-pointer-types]
     free_atype(seq->fields[i], val);
                ^~~
evaluations/krb5/asn1_encode__fln.c:473:13: note: expected ‘__fln__freebaseS_const_struct_atype_info * {aka struct <anonymous> *}’ but argument is of type ‘const struct atype_info *’
 static void free_atype(__fln__freebaseS_const_struct_atype_info *a, void *val)
             ^~~~~~~~~~
```
```
evaluations/krb5/asn1_encode__fln.c:696:20: warning: passing argument 1 of ‘free_atype_ptr’ from incompatible pointer type [-Wincompatible-pointer-types]
     free_atype_ptr(eltinfo, eltptr);
                    ^~~~~~~
evaluations/krb5/asn1_encode__fln.c:568:13: note: expected ‘__fln__freeptrS_const_struct_atype_info * {aka struct <anonymous> *}’ but argument is of type ‘const struct atype_info *’
 static void free_atype_ptr(__fln__freeptrS_const_struct_atype_info *a, void *val)
             ^~~~~~~~~~~~~~
```

## Fix
```
+ x = ptrinfo->basetype;
+ free_atype(x, ptr);
+ free_atype_ptr(x, ptr);
- free_atype(ptrinfo->basetype, ptr);
- free_atype_ptr(ptrinfo->basetype, ptr);
```

## References
None

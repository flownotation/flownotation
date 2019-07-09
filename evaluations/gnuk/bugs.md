# Main bug fix [1]:
https://salsa.debian.org/gnuk-team/gnuk/gnuk/commit/c73bb0548e1c5a252081f2ad93b4ea9bed470252

## Annotations:
```
#param(2) @check_valid_ptr:integrity
static void copy_do_1(uint16_t tag, const uint8_t *do_data, int with_tag)
```

## Helper functions:
```
#return @check_valid_ptr:integrity
const uint8_t *check_do_ptr(const uint8_t *do_ptr) // Checks that do_ptr is not null
```

## Error Message:
```
evaluations/gnuk/openpgp-do_snip__fln.c: In function ‘rw_kdf’:
evaluations/gnuk/openpgp-do_snip__fln.c:310:22: error: passing argument 2 of ‘copy_do_1’ from incompatible pointer type [-Werror=incompatible-pointer-types]
       copy_do_1(tag, do_ptr[1], with_tag);
                      ^~~~~~
evaluations/gnuk/openpgp-do_snip__fln.c:231:13: note: expected ‘const __fln__check_valid_ptrI_uint8_t * {aka const struct <anonymous> *}’ but argument is of type ‘const uint8_t * {aka const int *}’
 static void copy_do_1(uint16_t tag, const __fln__check_valid_ptrI_uint8_t *do_data, int with_tag)
             ^~~~~~~~~
```

## Fix:
```
- copy_do_1(tag, do_ptr[NR_DO_KDF], with_tag);
+ copy_do_1(tag, check_do_ptr(do_ptr[NR_DO_KDF]), with_tag);
```



# Checking memcpy size requirement [2]

`memcpy` `size_t n` parameter length is not checked to be positive. As a result a negative
integer could be passed in that will be interpreted as an unsigned integer and will result
in a page fault.

## Annotations
```
#requires @check_len:integrity
int len;
```

## Helper Functions
```
#return @check_len:integrity
int assign_len(int old, int new) // Checks that new is positive
```

## Error Messages
```
evaluations/gnuk/openpgp-do_snip__fln.c:296:9: error: incompatible types when assigning to type ‘__fln__check_lenI_int {aka struct <anonymous>}’ from type ‘int’
     len = do_data__fln_p[0] + 1;
         ^
```
```
evaluations/gnuk/openpgp-do_snip__fln.c:301:9: error: incompatible types when assigning to type ‘__fln__check_lenI_int {aka struct <anonymous>}’ from type ‘uint8_t {aka int}’
     len = do_data__fln_p[0];
         ^
```

## Fix
```
- len = do_data[0] + 1;
+ int tmp = do_data[0] + 1;
+ len = assign_len(len, tmp);
```
```
- len = do_data[0];
+ int tmp = do_data[0];
+ len = assign_len(len, tmp);
```

## References
None



# Encoding an Invariant [3]

/* KDF DO can be changed only when no keys are registered.  */
```no_prvkey_sig -> no_prvkey_dec -> no_prvkey_aut```

## Annotations
```
#requires @no_prvkey_sig:integrity .then @no_prvkey_dec:integrity .then @no_prvkey_aut:integrity
int no_key_invar;
```

## Helper Functions
```
#return @no_prvkey_sig:integrity
int check_prvkey_sig(int no_key_invar, uint8_t prvkey_sig)
```
```
#param(1) @no_prvkey_sig:integrity
#return @no_prvkey_dec:integrity
int check_prvkey_dec(int no_key_invar, uint8_t prvkey_dec)
```
```
#param(1) @no_prvkey_dec:integrity
#return @no_prvkey_aut:integrity
int check_prvkey_aut(int no_key_invar, uint8_t prvkey_aut)
```
```
#param @no_prvkey_aut:integrity
int prvkey_aut_to_bool(int no_key_invar)
```

## Error Messages


## Fix
```
- if (do_ptr[NR_DO_PRVKEY_SIG] || do_ptr[NR_DO_PRVKEY_DEC] || do_ptr[NR_DO_PRVKEY_AUT])
-    return 0;
+ if (prvkey_aut_to_bool(check_prvkey_aut(check_prvkey_dec(check_prvkey_sig(no_key_invar,do_ptr[NR_DO_PRVKEY_SIG]),do_ptr[NR_DO_PRVKEY_DEC]),do_ptr[NR_DO_PRVKEY_AUT])))
+ { } else { return 0;}
```

## References
None

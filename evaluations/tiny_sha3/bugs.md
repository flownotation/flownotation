
# Possible API sequencing bugs (1)

Modeled sequence of ```sha3_ctx_t``` structure states; uninit -> init -> updated -> final
with then statements (less to write).

## Annotations
```
#requires @sha3_uninit:secrecy .then @sha3_init:secrecy .then @sha3_updated:secrecy
sha3_ctx_t* sha3;
```
```
#param(1) @sha3_uninit:secrecy
#return @sha3_init:secrecy
sha3_ctx_t* sha3_init(sha3_ctx_t *c, int mdlen)
```
```
#param(1) @sha3_init:secrecy
#return @sha3_updated:secrecy
sha3_ctx_t* sha3_update(sha3_ctx_t *c, const void *data, size_t len)
```
```
#param(2) @sha3_updated:secrecy
int sha3_final(void *md, sha3_ctx_t *c)
```

## Helper Functions
None

## Error Messages
N/A

## Fix
N/A

## References
None



# Possible API sequencing bugs (2)

Modeled sequence of ```sha3_ctx_t``` structure states; uninit -> init -> updated -> final
with gate functions (closer to original code)Possible API sequencing bugs.

## Annotations
```
#requires @sha3_uninit:secrecy
sha3_ctx_t sha3;
#requires @sha3_init:secrecy
sha3_ctx_t* sha3_2;
#requires @sha3_updated:secrecy
sha3_ctx_t* sha3_3;
```
```
#param(1) @sha3_uninit:secrecy
#return @sha3_init_check:integrity
int sha3_init(sha3_ctx_t *c, int mdlen)
```
```
#param(1) @sha3_init:integrity
#return @sha3_update_check:integrity
int sha3_update(sha3_ctx_t *c, const void *data, size_t len)
```
```
#param(2) @sha3_updated:integrity
int sha3_final(void *md, sha3_ctx_t *c)
```

## Helper Functions
```
#param(1) @sha3_init_check:integrity
#return @sha3_init:integrity
sha3_ctx_t* gate_init(int b, sha3_ctx_t *c)
```
```
#param(1) @sha3_update_check:integrity
#return @sha3_init:integrity
sha3_ctx_t* gate_update(int b, sha3_ctx_t *c)
```

## Error Messages
```
evaluations/tiny_sha3/sha3a__fln.c: In function ‘sha3’:
evaluations/tiny_sha3/sha3a__fln.c:589:13: error: incompatible type for argument 1 of ‘sha3_init’
   sha3_init(sha3, mdlen);
             ^~~~
evaluations/tiny_sha3/sha3a__fln.c:522:29: note: expected ‘__fln__sha3_uninitS_sha3_ctx_t * {aka struct <anonymous> *}’ but argument is of type ‘__fln__sha3_uninitS_sha3_ctx_t {aka struct <anonymous>}’
 __fln__sha3_init_checkI_int sha3_init(__fln__sha3_uninitS_sha3_ctx_t *c, __fln__len_checkedI_int mdlen)
                             ^~~~~~~~~
```
```
evaluations/tiny_sha3/sha3a__fln.c:590:15: error: incompatible type for argument 1 of ‘sha3_update’
   sha3_update(sha3, in, inlen);
               ^~~~
evaluations/tiny_sha3/sha3a__fln.c:542:31: note: expected ‘__fln__sha3_initI_sha3_ctx_t * {aka struct <anonymous> *}’ but argument is of type ‘__fln__sha3_uninitS_sha3_ctx_t {aka struct <anonymous>}’
 __fln__sha3_update_checkI_int sha3_update(__fln__sha3_initI_sha3_ctx_t *c, const void *data, size_t len)
                               ^~~~~~~~~~~
```
```
evaluations/tiny_sha3/sha3a__fln.c:591:18: error: incompatible type for argument 2 of ‘sha3_final’
   sha3_final(md, sha3);
                  ^~~~
evaluations/tiny_sha3/sha3a__fln.c:569:5: note: expected ‘__fln__sha3_updatedI_sha3_ctx_t * {aka struct <anonymous> *}’ but argument is of type ‘__fln__sha3_uninitS_sha3_ctx_t {aka struct <anonymous>}’
 int sha3_final(void *md, __fln__sha3_updatedI_sha3_ctx_t *c)
     ^~~~~~~~~~
```

## Fix
```
- sha3_init(sha3, mdlen);
- sha3_update(sha3, in, inlen);
- sha3_final(md, sha3);
+ sha3_2 = gate_init(sha3_init(&sha3, mdlen), &sha3);
+ sha3_3 = gate_update(sha3_update(sha3_2, in, inlen), sha3_2);
+ sha3_final(md, sha3_3);
```

## References
None



# Added len check functions for avoiding zero-length messages

Done with the gate method.

## Annotations
```
#param(2) @len_checked:integrity
int sha3_init(sha3_ctx_t *c, int mdlen)
```
```
#param(4) @len_checked:integrity
void *sha3(const void *in, size_t inlen, void *md, int mdlen)
```
```
#param(3) @len_checked:integrity
void shake_out(sha3_ctx_t *c, void *out, size_t len)
```

## Helper Functions
```
#param @len_unchecked:integrity
#return @len_check:integrity
int check_len_non_zero(size_t len) 
```
```
#param(1) @len_check:integrity
#param(2) @len_unchecked:integrity
#return @len_checked:integrity
size_t gate_non_zero_len(int b, size_t len)
```

## Error Messages
N/A

## Fix
N/A

## References
None

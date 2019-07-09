#ifndef OBLIV_RAM_OH
#define OBLIV_RAM_OH

#include "../../src/pycparser/utils/fake_libc_include/stdbool.h"
#include "copy.h"

#ifndef ORAM_DEFAULT_TYPE
#define ORAM_DEFAULT_TYPE ORAM_TYPE_SQRT
#endif

typedef struct oram oram;
typedef enum {ORAM_TYPE_AUTO, ORAM_TYPE_SQRT, ORAM_TYPE_CIRCUIT, ORAM_TYPE_LINEAR} oram_type;

typedef void (* block_access_function)(OcCopy *, void * oram_block, void * external_block) ;

void oram_set_default_type(oram_type);

oram * oram_new(oram_type, OcCopy * cpy, size_t);
oram * oram_from_array(oram_type, OcCopy * cpy, size_t, void *);
void oram_free(oram *);

size_t oram_size(oram *);

 bool oram_read(void *, oram *,  size_t) ;
 bool oram_write(oram *, void *,  size_t) ;
 bool oram_apply(oram *, void *, block_access_function,  size_t) ;

#endif
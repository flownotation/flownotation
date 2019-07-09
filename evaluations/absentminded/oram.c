#include "oram.h"
// #include "oram_sqrt/sqrtoram.oh"
// #include "oram_ckt/circuit_oram.oh"

struct oram {
	oram_type mode;
	size_t size;
	OcCopy * cpy;
	void * data;
};

static void * element(OcCopy* cpy,void * arr, int x)  {
	return x*cpy->eltsize+(char*)arr;
}

oram_type default_oram_type = ORAM_DEFAULT_TYPE;

void oram_set_default_type(oram_type new_type) {
	default_oram_type = new_type;
}

void oram_init(oram* o, oram_type mode, OcCopy * cpy, size_t size, void * src) {
	o->size = size;
	o->cpy = cpy;
	if (mode == ORAM_TYPE_AUTO) {
		o->mode = default_oram_type;
	} else {
		o->mode = mode;	
	}
	if (o->mode == ORAM_TYPE_LINEAR) {
		o->data = calloc(o->size, o->cpy->eltsize);
		if (src != NULL) {
			ocCopyN(o->cpy, o->data, src, size);
		}

	} else if (o->mode == ORAM_TYPE_CIRCUIT) {
		o->data = ckt_initialize(cpy, size);
		if (src != NULL) {
			for(size_t ii = 0; ii < o->size; ii++) {
				oram_write(o, element(o->cpy, src, ii), ii);
			}
		}

	} else {
		if (src == NULL) {
			void * blank = calloc(size * o->cpy->eltsize, sizeof(uint8_t));
			o->data = ocSqrtOramNew(o->cpy, blank, size);
			free(blank);
		} else {
			o->data = ocSqrtOramNew(o->cpy, src, size);
		}
	}
}

oram * oram_new(oram_type mode, OcCopy * cpy, size_t size) {
	oram * ram = malloc(sizeof(oram));
	oram_init(ram, mode, cpy, size, NULL);
	return ram;
}

oram * oram_from_array(oram_type mode, OcCopy * cpy, size_t size, void * src) {
	oram * ram = malloc(sizeof(oram));
	oram_init(ram, mode, cpy, size, src);
	return ram;
}

void oram_free(oram* o) {
	if (o->mode == ORAM_TYPE_LINEAR) {
		free(o->data);
	} else if (o->mode == ORAM_TYPE_CIRCUIT) {
		ckt_release(o->data);
	} else {
		ocSqrtOramRelease(o->data);
	}

	o->size = 0;
	o->data = NULL;
	free(o);
}

size_t oram_size(oram * o) {
	return o->size;
}

 bool oram_read(void * output, oram * o,  size_t index)  {
	 bool success = false;

	if (o->mode == ORAM_TYPE_LINEAR) {
		for (size_t ii = 0; ii < o->size; ii++) {
			 if (ii == index) {
				ocCopy(o->cpy, output, element(o->cpy, o->data, ii));
				success = true;
			}
		}

	} else if (o->mode == ORAM_TYPE_CIRCUIT) {
		 if ((index < o->size) & (index >= 0)) {
			ckt_read(o->data, index % o->size, output);
			success = true;
		}

	} else {
		 if ((index < o->size) & (index >= 0)) {
			ocSqrtOramReadObliv(o->data, index % o->size, output);
			success = true;
		}
	}

	return success;
}

 bool oram_write(oram * o, void * input,  size_t index)  {
	 bool success = false;

	if (o->mode == ORAM_TYPE_LINEAR) {
		for (size_t ii = 0; ii < o->size; ii++) {
			 if (ii == index) {
				ocCopy(o->cpy, element(o->cpy, o->data, ii), input);
				success = true;
			}
		}

	} else if (o->mode == ORAM_TYPE_CIRCUIT) {
		 if ((index < o->size) & (index >= 0)) {
			ckt_write(o->data, index % o->size, input);
			success = true;
		}

	} else {
		 if ((index < o->size) & (index >= 0)) {
			ocSqrtOramWriteObliv(o->data, input, index % o->size);
			success = true;
		}
	}

	return success;
}

 bool oram_apply(oram * o, void * input, block_access_function fn,  size_t index)  {
	 bool success = false;

	if (o->mode == ORAM_TYPE_LINEAR) {
		for (size_t ii = 0; ii < o->size; ii++) {
			 if (ii == index) {
				fn(o->cpy, element(o->cpy, o->data, ii), input);
				success = true;
			}
		}

	} else if (o->mode == ORAM_TYPE_CIRCUIT) {
		 if ((index < o->size) & (index >= 0)) {
			ckt_apply(o->data, index % o->size, fn, input);
			success = true;
		}

	} else {
		 if ((index < o->size) & (index >= 0)) {
			ocSqrtOramAccessObliv(o->data, index % o->size, fn, input);
			success = true;
		}
	}

	return success;
}

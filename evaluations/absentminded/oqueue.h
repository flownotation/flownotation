#ifndef OBLIV_QUEUE
#define OBLIV_QUEUE

#include "copy.h"
//#include "oram.oh"

/********************************************************************************
 * This implements an O(log(n)) oblivious queue, as descriped in the paper:
 * 
 * Zahur, S. & Evans, D. (2013). Circuit Structures for Improving Efficiency of
 * Security and Privacy Tools. IEEE Symposium on Security and Privacy 2013.
 ********************************************************************************/

typedef struct oqueue oqueue;

oqueue *oqueue_new_static(OcCopy *cpy, size_t n);
oqueue *oqueue_static_from_array(OcCopy *cpy, size_t n, void *src);

void oqueue_free(oqueue *);

bool oqueue_empty(oqueue *);
bool oqueue_full(oqueue *);
bool oqueue_push(oqueue *, void *);
bool oqueue_pop(void *, oqueue *);

struct oqueue
{
	oqueue *child;
	OcCopy *cpy;
	size_t layer_index;
	size_t copymult;
	bool dynamic_sizing;
	uint8_t head;
	uint8_t tail;
	uint32_t current_elements;
	uint8_t push_time;
	uint8_t pop_time;
	void *data;
};

/********************************************************************************
 * The following implements a ring queue atop Sqrt ORAM; it is left here for
 * purposes of comparison only, and should not be used in practice, as the log(n)
 * queue above is much faster.
 ********************************************************************************/

/*typedef struct oring_queue oring_queue;

oring_queue * oring_queue_new(size_t size, size_t);
void oring_queue_free(oring_queue *);

 bool oring_queue_empty(oring_queue *);
 bool oring_queue_empty_obliv(oring_queue *) ;
 bool oring_queue_full(oring_queue *);
 bool oring_queue_full_obliv(oring_queue *) ;
void oring_queue_push(oring_queue *,  uint32_t *);
void oring_queue_push_obliv(oring_queue *,  uint32_t *) ;
void oring_queue_pop( uint32_t *, oring_queue *);
void oring_queue_pop_obliv( uint32_t *, oring_queue *) ;*/

#endif
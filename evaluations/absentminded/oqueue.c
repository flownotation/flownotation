#include "../../src/pycparser/utils/fake_libc_include/math.h"
#include "oqueue.h"

static void *element(OcCopy *cpy, void *arr, int x)
{
	return x * cpy->eltsize + (char *)arr;
}

#return @oqueue_empty:integrity 
bool oqueue_empty(oqueue *layer)
{
	return (layer->current_elements == 0);
}

#return @oqueue_not_empty:integrity 
bool oqueue_full(oqueue *layer)
{
	if (layer->child == NULL)
	{
		return (layer->tail == 6);
	}
	else
	{
		return (layer->tail == 6 & oqueue_full(layer->child));
	}
}

#param @oqueue_check_child:secrecy 
#return @oqueue_has_child:integrity 
oqueue* has_child(oqueue *layer) {
	oqueue* empty = NULL;
	if (layer->child != NULL) {
		return layer;
	}
	return empty;
}

#param @oqueue_has_child:integrity
#return @oqueue_push_ready:integrity 
oqueue* is_push_time(oqueue *layer) {
	oqueue* empty = NULL;
	if (layer->push_time == 1) {
		return layer;
	}
	return empty;
}

#param @oqueue_push_ready:secrecy 
oqueue* tail_is_full(oqueue *layer) {
	oqueue* empty = NULL;
	if (layer->tail >= 5) {
		return layer;
	}
	return empty;
}

bool oqueue_push(oqueue *layer, void *input)
{
	#requires @oqueue_check_child:secrecy then @oqueue_has_child:integrity then @oqueue_push_ready:integrity
	oqueue* layer;
	// #requires :integrity @oqueue_has_child
	oqueue* layer1;
	// #requires :integrity @oqueue_push_ready
	oqueue* layer2;
	bool success = false;
	{	
		// Does this layer have a child?
		layer1 = has_child(layer);
		if (layer1)
		{
			// Is it time to push?
			layer2 = is_push_time(layer1);
			if (layer)
			{
				// Is the current layer full?
				layer = tail_is_full(layer2);
				if (layer)
				{
					// If so, push down two blocks to the next layer
					if (oqueue_push(layer->child, element(layer->cpy, layer->data, 3 * layer->copymult)))
					{
						ocCopyN(layer->cpy, element(layer->cpy, layer->data, 3 * layer->copymult), element(layer->cpy, layer->data, 5 * layer->copymult), layer->copymult);
						// Move the tail pointer backwards
						layer->tail -= 2;
					}
				}
				// Since it's time to push, we will push and then it will no longer
				// be time to push
				layer->push_time = 0;
			}
			else
			{
				// If it's not time to push, then next time it will be time to push
				layer->push_time++;
			}
		}
	}
	// layer->tail is the position of the last element 
	if (layer->tail < 6)
	{
		for (uint8_t ii = 0; ii < 6; ii++)
		{
			// Add the input only at the tail (oblivious)
			if (ii == layer->tail)
			{
				ocCopyN(layer->cpy, element(layer->cpy, layer->data, ii * layer->copymult), input, layer->copymult);
				success = true;
				layer->current_elements++;
			}
		}
		// Move the tail pointer forward
		layer->tail++;
	}
	return success;
}

#param @oqueue_not_empty:secrecy 
#return @oqueue_pop_ready:integrity
oqueue* is_pop_time(oqueue* layer) {
	oqueue* empty = NULL;
	if (layer->pop_time == 0) {
		return layer;
	}
	return empty;
}

#param @oqueue_pop_ready:secrecy 
#return @oqueue_not_has_child:integrity
oqueue* not_has_child(oqueue *layer) {
	oqueue* empty = NULL;
	if (layer->child == NULL) {
		return layer;
	}
	return empty;
}

#param @oqueue_not_has_child:secrecy
oqueue* head_ge_two(oqueue* layer) {
	oqueue* empty = NULL;
	if (layer->head >= 2) {
		return layer;
	}
	return empty;
}

#param(2) @oqueue_not_empty:secrecy
bool oqueue_pop(void *output, oqueue *layer)
{
	bool success = false;

	{
		layer = is_pop_time(layer);
		if (layer)
		{
			layer = not_has_child(layer);
			if (layer)
			{
				layer = head_ge_two(layer);
				if (layer)
				{
					for (uint8_t ii = 0; ii < 4; ii++)
					{
						ocCopyN(layer->cpy, element(layer->cpy, layer->data, ii * layer->copymult), element(layer->cpy, layer->data, (ii + 2) * layer->copymult), layer->copymult);
					}
					layer->head -= 2;
					layer->tail -= 2;
				}
			}
			else
			{
				if (layer->head >= 2)
				{
					ocCopyN(layer->cpy, element(layer->cpy, layer->data, 0), element(layer->cpy, layer->data, 2 * layer->copymult), layer->copymult);
					layer->head -= 2;
					if (~oqueue_pop(element(layer->cpy, layer->data, 1 * layer->copymult), layer->child))
					{
						for (uint8_t ii = 1; ii < 4; ii++)
						{
							ocCopyN(layer->cpy, element(layer->cpy, layer->data, ii * layer->copymult), element(layer->cpy, layer->data, (ii + 2) * layer->copymult), layer->copymult);
						}
						layer->tail -= 2;
					}
				}
			}
			layer->pop_time = 1;
		}
		else
		{
			layer->pop_time--;
		}
	}

	if (layer->head < 3 & layer->head != layer->tail)
	{
		for (uint8_t ii = 0; ii < 3; ii++)
		{
			if (ii == layer->head)
			{
				ocCopyN(layer->cpy, output, element(layer->cpy, layer->data, ii * layer->copymult), layer->copymult);
				success = true;
				layer->current_elements--;
			}
		}
		layer->head++;
	}
	return success;
}

#return @oqueue_empty:integrity
oqueue *oqueue_new_static(OcCopy *cpy, size_t n)
{
	size_t queue_size = 0;
	size_t layer_index = 0;
	oqueue *result;
	// #requires :integrity {.push_time:int, .tail:int} @push_ready
	oqueue* this_layer;
	this_layer = NULL;
	oqueue *last_layer = NULL;

	while (queue_size < n)
	{
		this_layer = malloc(sizeof(oqueue));
		this_layer->layer_index = layer_index;
		this_layer->head = 0;
		this_layer->tail = 0;
		this_layer->current_elements = 0;
		this_layer->push_time = 0;
		this_layer->pop_time = 0;
		this_layer->dynamic_sizing = false;
		this_layer->child = NULL;

		this_layer->copymult = pow(2, layer_index);
		this_layer->cpy = cpy;
		this_layer->data = calloc(this_layer->cpy->eltsize * this_layer->copymult * 6, sizeof(uint8_t));

		if (last_layer == NULL)
		{
			result = this_layer;
		}
		else
		{
			last_layer->child = this_layer;
		}
		last_layer = this_layer;

		queue_size += 3 * pow(2, layer_index);
		layer_index++;
	}

	return result;
}

//TODO make this work in O(N) instead of O(NlogN)
oqueue *oqueue_static_from_array(OcCopy *cpy, size_t n, void *src)
{
	oqueue *result = oqueue_new_static(cpy, n);

	for (size_t ii = 0; ii < n; ii++)
	{
		oqueue_push(result, element(cpy, src, ii));
	}

	return result;
}

#param @oqueue_empty:secrecy
void oqueue_free(oqueue *layer)
{
	if (layer->child != NULL)
	{
		oqueue_free(layer->child);
	}
	free(layer->data);
	free(layer);
}

int main() {

}
// #include <.oh>
#include "oqueue.h"
#include "test_generic.h"

static const char TESTNAME[] = "oqueue";

char* get_test_name() {
	return TESTNAME;
}

char* get_supplementary_options_string() {
	return NULL;
}

struct option* get_long_options() {
	return NULL;
}

void print_supplementary_help() {}

void test_main(void*varg) {

	{

		int testEls = 378;

		oqueue * testQueue = oqueue_new_static(&ocCopyInt, testEls);

		bool success = true;

		for (int ii = 0; ii <testEls; ii ++) {
			 int input = feedOblivInt(ii, ii % 2);
			 bool pushed = oqueue_push(testQueue, &input);
			bool tempBool;
			revealOblivBool(&tempBool, pushed, 0);
			success &= tempBool;
		}

		for (int ii = 0; ii <testEls; ii ++) {
			 int output;
			 bool popped = oqueue_pop(&output, testQueue);
			int temp;
			revealOblivInt(&temp, output, 0);
			bool tempBool;
			revealOblivBool(&tempBool, popped, 0);
			success &= (temp == ii && tempBool);
		}

		oqueue_free(testQueue);

		fprintf(stderr, "Test Item: %-70s %s\n", "oqueue - push/pop 378 ordered elements", (success)?STATUS_SUCCESS:STATUS_FAILURE);

	}

	{

		int testEls = 189;

		oqueue * testQueue = oqueue_new_static(&ocCopyInt, testEls);

		bool success = true;

		for (int ii = 0; ii <testEls*2; ii ++) {
			 int input = feedOblivInt(ii, ii % 2);
			 bool pushed = oqueue_push(testQueue, &input);
			bool tempBool;
			revealOblivBool(&tempBool, pushed, 0);
			success &= tempBool;
		}

		 int input = feedOblivInt(12345, 0);
		 bool pushed = oqueue_push(testQueue, &input);
		bool tempBool;
		revealOblivBool(&tempBool, pushed, 0);
		success &= !tempBool;

		for (int ii = 0; ii <testEls*2; ii ++) {
			 int output;
			 bool popped = oqueue_pop(&output, testQueue);
			int temp;
			revealOblivInt(&temp, output, 0);
			bool tempBool;
			revealOblivBool(&tempBool, popped, 0);
			success &= (temp == ii && tempBool);
		}

		oqueue_free(testQueue);

		fprintf(stderr, "Test Item: %-70s %s\n", "oqueue - push/pop 378 ordered elements with undersized queue", (success)?STATUS_SUCCESS:STATUS_FAILURE);

	}

	{

		int testEls = 200;
		int testOps = 4000;

		uint32_t testBuffer[201];
		uint32_t testBufferHead = 0;
		uint32_t testBufferTail = 0;

		oqueue * testQueue = oqueue_new_static(&ocCopyInt, testEls);

		 uint32_t otemp;
		 bool opSuccess;
		bool success = true;
		bool tempBool;
		uint32_t thisVal;
		uint32_t temp;
		 uint32_t rnd;
		uint32_t srnd;

		for (int ii = 0; ii < testOps; ii ++) {
			// for some reason, ocBroadcast doesn't work.
			rnd = feedOblivInt(rand(), ii % 2);
			revealOblivBool(&srnd, rnd, 0);

			if (testBufferHead == testBufferTail) {
				// queue is empty; push				
				testBuffer[testBufferTail] = srnd;
				if (testBufferTail < 200) {
					testBufferTail ++;
				} else {
					testBufferTail = 0;
				}
				otemp = feedOblivInt(srnd, ii % 2);
				opSuccess = oqueue_push(testQueue, &otemp);
				revealOblivBool(&tempBool, opSuccess, 0);
				if (!tempBool) fprintf(stderr,"FAILURE at %d:1\n", ii);
				success &= tempBool;
			} else {
				bool queue_full = (testBufferTail + 1) == testBufferHead || (testBufferTail == 200 && testBufferHead == 0);
				if (queue_full) {
					// queue is full; pop
					thisVal = testBuffer[testBufferHead];
					if (testBufferHead < 200) {
						testBufferHead ++;
					} else {
						testBufferHead = 0;
					}
					opSuccess = oqueue_pop(&otemp, testQueue);
					revealOblivInt(&temp, otemp, 0);
					revealOblivBool(&tempBool, opSuccess, 0);
					if (!(tempBool && (temp == thisVal))) fprintf(stderr,"FAILURE at %d:2\n", ii);
					success &= tempBool && (temp == thisVal);
				} else {
					if (srnd %2 > 0) {
						testBuffer[testBufferTail] = srnd;
						if (testBufferTail < 200) {
							testBufferTail ++;
						} else {
							testBufferTail = 0;
						}
						otemp = feedOblivInt(srnd, ii % 2);
						opSuccess = oqueue_push(testQueue, &otemp);
						revealOblivBool(&tempBool, opSuccess, 0);
						if (!tempBool) fprintf(stderr,"FAILURE at %d:3\n", ii);
						success &= tempBool;
					} else {
						thisVal = testBuffer[testBufferHead];
						if (testBufferHead < 200) {
							testBufferHead ++;
						} else {
							testBufferHead = 0;
						}
						opSuccess = oqueue_pop(&otemp, testQueue);
						revealOblivInt(&temp, otemp, 0);
						revealOblivBool(&tempBool, opSuccess, 0);
						success &= tempBool && (temp == thisVal);
						if (!tempBool) fprintf(stderr,"FAILURE at %d:4.1\n", ii);
						if (temp != thisVal) fprintf(stderr,"FAILURE at %d:4.2\n", ii);
					}
				}	
			}
		}

		oqueue_free(testQueue);

		fprintf(stderr, "Test Item: %-70s %s\n", "oqueue - 4000 random operations on empty 200 element queue", (success)?STATUS_SUCCESS:STATUS_FAILURE);

	}

	{

		int testEls = 200;
		int testOps = 4000;

		uint32_t testBuffer[201];
		uint32_t testBufferHead = 0;
		uint32_t testBufferTail = 0;

		oqueue * testQueue = oqueue_new_static(&ocCopyInt, testEls);

		 uint32_t otemp;
		 bool opSuccess;
		bool success = true;
		bool tempBool;
		uint32_t thisVal;
		uint32_t temp;
		 uint32_t rnd;
		uint32_t srnd;

		for (int ii = 0; ii < testEls; ii ++) {
			// for some reason, ocBroadcast doesn't work.
			rnd =feedOblivInt(rand(), ii % 2);
			revealOblivBool(&srnd, rnd, 0);

			testBuffer[testBufferTail] = srnd;
			if (testBufferTail < 200) {
				testBufferTail ++;
			} else {
				testBufferTail = 0;
			}
			otemp = feedOblivInt(srnd, ii % 2);
			opSuccess = oqueue_push(testQueue, &otemp);
			revealOblivBool(&tempBool, opSuccess, 0);
			success &= tempBool;
		}

		for (int ii = 0; ii < testOps; ii ++) {
			// for some reason, ocBroadcast doesn't work.
			rnd =feedOblivInt(rand(), ii % 2);
			revealOblivBool(&srnd, rnd, 0);

			if (testBufferHead == testBufferTail) {
				// queue is empty; push				
				testBuffer[testBufferTail] = srnd;
				if (testBufferTail < 200) {
					testBufferTail ++;
				} else {
					testBufferTail = 0;
				}
				otemp = feedOblivInt(srnd, ii % 2);
				opSuccess = oqueue_push(testQueue, &otemp);
				revealOblivBool(&tempBool, opSuccess, 0);
				success &= tempBool;
			} else {
				bool queue_full = (testBufferTail + 1) == testBufferHead || (testBufferTail == 200 && testBufferHead == 0);
				if (queue_full) {
					// queue is full; pop
					thisVal = testBuffer[testBufferHead];
					if (testBufferHead < 200) {
						testBufferHead ++;
					} else {
						testBufferHead = 0;
					}
					opSuccess = oqueue_pop(&otemp, testQueue);
					revealOblivInt(&temp, otemp, 0);
					revealOblivBool(&tempBool, opSuccess, 0);
					success &= tempBool && (temp == thisVal);
				} else {
					if (srnd %2 > 0) {
						testBuffer[testBufferTail] = srnd;
						if (testBufferTail < 200) {
							testBufferTail ++;
						} else {
							testBufferTail = 0;
						}
						otemp = feedOblivInt(srnd, ii % 2);
						opSuccess = oqueue_push(testQueue, &otemp);
						revealOblivBool(&tempBool, opSuccess, 0);
						success &= tempBool;
					} else {
						thisVal = testBuffer[testBufferHead];
						if (testBufferHead < 200) {
							testBufferHead ++;
						} else {
							testBufferHead = 0;
						}
						opSuccess = oqueue_pop(&otemp, testQueue);
						revealOblivInt(&temp, otemp, 0);
						revealOblivBool(&tempBool, opSuccess, 0);
						success &= tempBool && (temp == thisVal);
					}
				}	
			}
		}

		oqueue_free(testQueue);

		fprintf(stderr, "Test Item: %-70s %s\n", "oqueue - 4000 random operations on full 200 element queue", (success)?STATUS_SUCCESS:STATUS_FAILURE);

	}

	{

		int testEls = 189;

		oqueue * testQueue = oqueue_new_static(&ocCopyInt, testEls);

		bool success = true;

		 bool testQueueFullness = oqueue_empty(testQueue);
		bool tempBool;
		revealOblivBool(&tempBool, testQueueFullness, 0);
		success &= (tempBool == true);

		for (int ii = 0; ii <testEls; ii ++) {
			 int input = feedOblivInt(ii, ii % 2);
			oqueue_push(testQueue, &input);
			testQueueFullness = oqueue_empty(testQueue);
			revealOblivBool(&tempBool, testQueueFullness, 0);
			success &= (tempBool == false);
		}

		for (int ii = 0; ii <testEls; ii ++) {
			testQueueFullness = oqueue_empty(testQueue);
			revealOblivBool(&tempBool, testQueueFullness, 0);
			success &= (tempBool == false);
			 int output;
			oqueue_pop(&output, testQueue);
		}

		testQueueFullness = oqueue_empty(testQueue);
		revealOblivBool(&tempBool, testQueueFullness, 0);
		success &= (tempBool == true);

		oqueue_free(testQueue);

		fprintf(stderr, "Test Item: %-70s %s\n", "oqueue - oqueue_empty", (success)?STATUS_SUCCESS:STATUS_FAILURE);

	}

	{

		int testEls = 189;

		oqueue * testQueue = oqueue_new_static(&ocCopyInt, testEls);

		bool success = true;

		 bool testQueueFullness;
		bool tempBool;
		

		for (int ii = 0; ii <testEls*2; ii ++) {
			testQueueFullness = oqueue_full(testQueue);
			revealOblivBool(&tempBool, testQueueFullness, 0);
			success &= (tempBool == false);
			 int input = feedOblivInt(ii, ii % 2);
			oqueue_push(testQueue, &input);
		}

		testQueueFullness = oqueue_full(testQueue);
		revealOblivBool(&tempBool, testQueueFullness, 0);
		success &= (tempBool == true);

		oqueue_free(testQueue);

		fprintf(stderr, "Test Item: %-70s %s\n", "oqueue - oqueue_full", (success)?STATUS_SUCCESS:STATUS_FAILURE);

	}

}
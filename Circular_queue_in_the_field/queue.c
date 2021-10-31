#include "queue.h"
#include <stdlib.h>

/* creates a new queue with a given size */
queue_t* create_queue(int capacity) {
 queue_t* new_queue = (queue_t*) malloc(sizeof(queue_t));
 new_queue -> numbers= capacity;
 new_queue -> size =0;
 new_queue -> writeln = 0;
 new_queue -> read =-1;
 new_queue -> data =(void**)malloc (sizeof(void*)*capacity);
    return new_queue;

}
/* gets number of stored elements */
int get_queue_size(queue_t *queue) {
    return (queue -> size);
}

/* deletes the queue and all allocated memory */
void delete_queue(queue_t *queue) {
    free (queue -> data);
    free (queue);
}

/*
 * inserts a reference to the element into the queue
 * returns: true on success; false otherwise
 */
bool push_to_queue(queue_t *queue, void *data) {
    if (queue -> size == queue -> numbers) {
        return 0;
    }
    queue -> data[queue -> writeln] = data;
    queue -> writeln+=1;
    queue -> size+=1;
    if (queue-> writeln == queue ->numbers ) {
        queue -> writeln =0;
    }
    return 1;
}

/*
 * gets the first element from the queue and removes it from the queue
 * returns: the first element on success; NULL otherwise
 */
void* pop_from_queue(queue_t *queue) {
    if (queue -> size == 0) {
        return  NULL;
    }
    queue -> size--;
    queue -> read++;
    if (queue ->read == queue -> numbers) {
        queue -> read =0;
    }
    return queue->data[queue -> read];
}

/*
 * gets idx-th element from the queue
 * returns the element that will be popped after idx calls of the pop_from_queue()
 * returns: the idx-th element on success; NULL otherwise
 */
void* get_from_queue(queue_t *queue, int idx) {
    _Bool i1 = (queue -> read > queue -> writeln) && (idx >=queue -> writeln) && (idx<=queue->read);
    _Bool i2 = (queue -> read < queue -> writeln) && ((idx >=queue -> writeln) || (idx <=queue -> read) ) ;
    if (idx >=queue -> numbers || idx <0 || i1 || i2 || queue ->size ==0) {
        return NULL;
    } else {
        return  queue->data[idx] ;
    }
}


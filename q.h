//include header file for TCB
#include "tcb.h"
//creates an empty queue, pointed to by the variable head.
void InitQueue(TCB_t** header)
{
	// write your code here
  header = (TCB_t*)malloc(sizeof(TCB_t))
}

//adds an element at the end of the queue
void AddQueue(TCB_t ** header, TCB_t * item)
{
	// you need to deal with prev and next
	// pointers of the item and given header
	// write your code here
}

// Moves the header pointer to the next element in the queue.
void RotateQueue(TCB_t **header)
{
	// write your code here
}

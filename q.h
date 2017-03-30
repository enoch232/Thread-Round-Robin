//include header file for TCB
#include "tcb.h"
//creates an empty queue, pointed to by the variable head.
void InitQueue(TCB_t** header)
{
	// write your code here
  *header = NULL;

}

//adds an element at the end of the queue
void AddQueue(TCB_t ** header, TCB_t * item)
{
	// you need to deal with prev and next
	// pointers of the item and given header
	// write your code here
  printf("add\n");
  // TCB_t* node = (TCB_t*)malloc(sizeof(TCB_t));
  if ((*header) == NULL){
    printf("it's NULL\n");
    *header = item;
    item->next = item;
    item->prev = item;
  }else{
    printf("it's not NULL\n");
    item->prev = (*header)->prev;
    item->next = (*header);
    (*header)->prev->next = item;
    (*header)->prev = item;
  }
}

// Moves the header pointer to the next element in the queue.
void RotateQueue(TCB_t **header)
{
  *header = (*header)->next;

	// write your code here
}

//include header file for TCB
#include "tcb.h"
//creates an empty queue, pointed to by the variable head.
void InitQueue(TCB_t** header)
{
	// write your code here
  *header = NULL;
  printf("Header set null\n");
  // header = (TCB_t**)malloc(sizeof(TCB_t));
  // (*header)->next = NULL;
  // (*header)->prev = NULL;
}

//adds an element at the end of the queue
void AddQueue(TCB_t ** header, TCB_t * item)
{
	// you need to deal with prev and next
	// pointers of the item and given header
	// write your code here
  // TCB_t* node = (TCB_t*)malloc(sizeof(TCB_t));
  if (*header == NULL){
    printf("Header is Null\n");

    *header = item;
    item->next = item;
    item->prev = item;
    printf("item: %d\n", item->number);
  }else{
    printf("Header is not Null\n");
    item->prev = (*header)->prev;
    item->next = (*header);
    (*header)->prev->next = item;
    (*header)->prev = item;
    printf("item: %d\n", item->number);
  }
}

// Moves the header pointer to the next element in the queue.
void RotateQueue(TCB_t **header)
{
	// write your code here
}

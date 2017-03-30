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
  //header points to the global. item is the new object.
  if ((*header) == NULL){
    //point the header to the new item
    *header = item;
    // set it so that when there is only one element (after header is pointing), it will point to itself.
    item->next = item;
    // set it so that the previous also point to itself when there is only one element.
    item->prev = item;
  }else{
    // if there are more than zero, use the saved global's previous value to the new object's previous. This basically points to the very first element that was added to the queue.
    item->prev = (*header)->prev;
    // this part basically points new object's next pointer to the very first element that was added to the queue.
    item->next = (*header);
    // updating header so that it points to the correct one. This is essential for the circular linked list to work.
    (*header)->prev->next = item;
    // Again, set the previous of the saved header's to point to new object.
    (*header)->prev = item;
  }
}

// Moves the header pointer to the next element in the queue.
void RotateQueue(TCB_t **header)
{
  // move to the next.
  *header = (*header)->next;

	// write your code here
}

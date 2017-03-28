//include header file to support queuing functions
#include <q.h>
extern TCB_t * execution_q;

void create_thread(void (*function)(void *))
{
	void * stackp;
	TCB_t * tcb;
	// write your code below
	//allocate a stack (via malloc) of a certain size (choose 8192)
	//allocate a TCB (via malloc)
	//call init_TCB with appropriate arguments (stack size 8192)
	//call AddQueue to add this TCB into the execution queue which is a global header pointer
}

void run()
{
    ucontext_t parent;                                     // get a place to store the main context
    getcontext(&parent);
    // write your code below
    // use swapcontext() to start executing first thread element in execution queue
}

void yield()
{
	//rotate the execution queue
	//swap the context, from previous thread element to the thread pointed to by execution queue
}

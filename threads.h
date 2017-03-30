//include header file to support queuing functions
#include "q.h"
extern TCB_t * execution_q;

void create_thread(void (*function)(void *))
{
	void * stackp;
	// void * stackp2;
	TCB_t * tcb;
	// write your code below
	//allocate a stack (via malloc) of a certain size (choose 8192)
	stackp = malloc(8192);
	//allocate a TCB (via malloc)


	tcb = (TCB_t*)malloc(sizeof(TCB_t));
	//call init_TCB with appropriate arguments (stack size 8192)
	init_TCB(tcb,(void*)&function, stackp, 8192);
	tcb->number = tcb;
	printf("new one: %x\n", tcb);
	//call AddQueue to add this TCB into the execution queue which is a global header pointer
	AddQueue(&execution_q, tcb);

}

void run()
{
    ucontext_t parent;                                     // get a place to store the main context
    getcontext(&parent);
    // write your code below
    // use swapcontext() to start executing first thread element in execution queue
		swapcontext(&parent, &execution_q->context);
}

void yield()
{
	//rotate the execution queue
	RotateQueue(&execution_q);
	//swap the context, from previous thread element to the thread pointed to by execution queue
	swapcontext(&execution_q->prev->context, &execution_q->context);
}

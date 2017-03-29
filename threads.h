//include header file to support queuing functions
#include "q.h"
extern TCB_t * execution_q;

void create_thread(void (*function)(void *))
{
	void * stackp;
	TCB_t * tcb;
	TCB_t * tcb2;
	TCB_t * tcb3;
	// write your code below
	//allocate a stack (via malloc) of a certain size (choose 8192)
	stackp = malloc(8192);
	//allocate a TCB (via malloc)


	tcb = malloc(sizeof(tcb));
	//call init_TCB with appropriate arguments (stack size 8192)
	init_TCB(tcb,(void*)&function, stackp, 8192);
	tcb->number = 3;
	AddQueue(&execution_q, tcb);



	tcb2 = malloc(sizeof(tcb2));
	//call init_TCB with appropriate arguments (stack size 8192)
	init_TCB(tcb2,(void*)&function, stackp, 8192);

	tcb2->number = 5;
	AddQueue(&execution_q, tcb2);



	tcb3 = malloc(sizeof(tcb3));
	//call init_TCB with appropriate arguments (stack size 8192)
	init_TCB(tcb3,(void*)&function, stackp, 8192);
	tcb3->number = 8;
	AddQueue(&execution_q, tcb);
	printf("%d -> %d -> %d", execution_q->number, execution_q->next->number, execution_q->next->next->number);
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

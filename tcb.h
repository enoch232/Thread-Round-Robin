#include "ucontext.h"

//TCB structure
typedef struct TCB_t {
     struct TCB_t     *next;
     struct TCB_t     *prev;
     ucontext_t      context;
     int number;
} TCB_t;


void init_TCB (TCB_t *tcb, void *function, void *stackP, int stack_size)
{
    memset(tcb, '\0', sizeof(TCB_t));
    // you have to get parent context with getcontext()
    // write your code here
    getcontext(&tcb->context);
    tcb->context.uc_stack.ss_sp = stackP;
    tcb->context.uc_stack.ss_size = (size_t) stack_size;
    // need to cook the context with makecontext()
    // write your code here
    printf("context building\n");
    makecontext(&tcb->context,(void*)&function, 0);
    printf("context built\n");
}

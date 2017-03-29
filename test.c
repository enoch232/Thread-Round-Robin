/*
Author: Enoch Ko
*/
#define _XOPEN_SOURCE 600
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "threads.h"

TCB_t * execution_q;            //Global execution queue

void function1()          //First thread will run on this function
{
	int i=0;
	for(i=0;i<4;i++)
	{
		printf("Task 1 is running\n");
		sleep(2);    //Delay of 2 sec
		// write your code below
		//yield to pause currently executing thread temporarily & allow other threads to execute

	}
}

void function2()
{
    // write your code below
}

void function3()
{
    // write your code below
}

int main()
{


    // Initialize execution queue
		InitQueue(&execution_q);


    // Create threads to run on functions 1, 2 and 3
		create_thread((void*)&function1);
		// create_thread((void*)&function2);
		// create_thread((void*)&function3);

    // run the execution queue
		return 0;
}

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
		//pass to the next one.
		yield();

	}
}

void function2()
{
    // write your code below
		int j=0;
		for(j=0;j<4;j++)
		{
			printf("Task 2 is running\n");
			sleep(2);    //Delay of 2 sec
			// write your code below
			//yield to pause currently executing thread temporarily & allow other threads to execute
			yield();

		}
}

void function3()
{
    // write your code below
		int k=0;
		for(k=0;k<4;k++)
		{
			printf("Task 3 is running\n");
			sleep(2);    //Delay of 2 sec
			// write your code below
			//yield to pause currently executing thread temporarily & allow other threads to execute
			yield();

		}
}

void main()
{


    // Initialize execution queue
		InitQueue(&execution_q);

    // Create threads to run on functions 1, 2 and 3
		create_thread(function1);
		create_thread(function2);
		create_thread(function3);
		// start
		run();

}

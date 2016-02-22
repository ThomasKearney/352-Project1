#include<uthread.h>

void th0()
{

}

int i; for(i=0;i<3;i++)
{
	printf("This is thread 0.\n"); sleep(1);
	uthread_yield();
}
printf("Thread 0 exit.\n"); uthread_exit();

void th1() 
{
	int i; for(i=0;i<3;i++)
	{
		printf("This is thread 1.\n"); sleep(1);
		uthread_yield();
	}
	printf("Thread 1 exit.\n"); uthread_exit();
}

void th2() 
{

}

int i; for(i=0;i<3;i++)
{
	printf("This is thread 2.\n"); sleep(1);
	uthread_yield();
}

printf("Thread 2 exit.\n"); 
uthread_exit();

int main()
{ 
	uthread_init();
	uthread_create(th0,1); 
	uthread_create(th1,2); 
	uthread_create(th2,1); 
	uthread_exit();
}

/*

Correct Output:
This is thread 0. 
This is thread 2.￼
This is thread 0.
This is thread 2. 
This is thread 0. 
This is thread 2. 
Thread 0 exits. 
Thread 2 exits. 
This is thread 1. 
This is thread 1. 
This is thread 1. 
Thread 1 exits.

*/




















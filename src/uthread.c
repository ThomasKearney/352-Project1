#include <stdio.h>

/*
In this project, you are required to develop a user-level thread library called uthread. The thread library should create user-level threads 
(upon request from some user application code), map the user-level threads to a kernel thread following the many-to-one mapping model, schedule t
he mapping based on the user-level thread priority numbers (i.e., when the kernel thread becomes available, the user thread with highest 
priority should be mapped to it; when there are multiple highest-priority user threads, the thread at the head of the priority ready queue 
should be selected for mapping), and support inter-thread message passing.
*/

/***** Global Variables ******/

// thread struct
struct thread 
{
	int priority;
	void (*func)();
};

struct thread a;

// the queue
struct thread que[100];
// que pointer
struct thread* que_pointer;

// helper methods to pop, pull, and shift queue

// if param right is 1 then shift right, otherwise shift left
void shift(struct thread* p, int right)
{
	struct thread* save;
	int i = 0;

	if(!right)
	{
		for(i = 0; i < 99; i++)
		{
			*(p + i) = *(p + i + 1);
		}
	}
	else
	{
		for(i = 0; i < 99; i++)
		{
			*(p + i + 1) = *(p + i);
		}
	}
}

struct thread pop(struct thread* p)
{
	shift(p, 0);
	struct thread ret = *p;
	return ret;
}

void push(struct thread* p, struct thread push_thread)
{
	shift(p,1);
	*p = push_thread;
}


/*
This function has to be called before any other functions of 
the uthread library can be called. It initializes the uthread system. 
For example, it may establish and initialize a ready queue and 
other data structures.
*/
void system_init()
{
	que_pointer = que;	
}

/*
The calling thread requests the thread library to create a new user-level 
thread that runs the function func(), which is specified as the first 
argument of this function. A context of this new user thread should be 
properly created and stored on the priority ready queue, based on the 
thread priority number, which is specified as the second argument of this 
function. The ready queue should be a priority queue that sorts all ready 
threads based on their priorities. The smaller is a priority number, the 
higher is the priority. This function returns the unique ID (which must be 
a non-negative integer) of the new thread on success, and -1 otherwise. To 
simplify the implementation, let us assume the total number of user threads 
is no more than 100 at any time; so the ID of a thread could be in the range of 
{0, 1, 􏰀, 99}.
*/
int uthread_create(void (*func)(), int priority)
{
	
	// DELETE LATER!
	return 0;
}

/*
The calling thread requests to yield the kernel thread to another 
user-level thread with the same or higher priority. If each ready 
thread has lower priority than this calling thread, the calling thread 
will continue its running; otherwise, the kernel thread is yielded to 
a ready thread with the highest priority.
*/
void uthread_yield()
{
	
}


/*

This function is called when the calling user-level thread terminates 
its execution. In respond to this call, if no ready user thread in the 
system, the whole process terminates; otherwise, a ready user thread 
with the highest priority should be mapped to the kernel thread to run.
*/
void uthread_exit()
{
	
}

/*
The calling thread requests to send a message pointed to by 
argument content to the thread with ID tid. The third argument, 
size, specifies the size of the message. If there is no 
user thread with ID tid, the function returns -1; otherwise 0 
is returned. Note that, this sending operation is non-blocking.
*/
int uthread_send(int tid, void* content, int size)
{
	
	// DELETE LATER
	return 0;
}

/*
The calling thread requests to retrieve a message sent by 
a thread of ID tid. If there is no message from tid available, 
the calling thread is blocked (i.e., it should be put into 
a waiting queue to wait to be moved back to the ready queue 
until the thread with ID tid sends a message to it). When 
returning from this function, the starting address of the 
retrieved message should be saved in *content, which is a 
variable of type void*, and the function returns an integer 
which is the size of the retrieved message. In the case of 
failure, the function returns -1. Note that, once a message 
has been retrieved, it is consumed and cannot be retrieved again.
*/
int uthread_recv(int tid, void** content)
{

	// DELETE LATER
	return 0;
}


int main()
{
	/* code */
	return 0;
}




















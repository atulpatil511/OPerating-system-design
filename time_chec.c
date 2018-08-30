#pragma GCC push_options
#pragma GCC optimize ("O0")
#include <sys/time.h>
#include <stdlib.h>
#define ITERATION 10000

int do_nothing()
{

return(5);
}
int main()
{

	struct timeval system_call,procedure_call;
	int i,k;
	time_t t1,t2,t3,t4,total_time;
	gettimeofday(&procedure_call,NULL);
	t1=procedure_call.tv_usec;
	printf("The first time stamp is %ld\n",t1);	
	for(i=0;i<ITERATION;i++)
	{
	k=do_nothing();
	}
	gettimeofday(&procedure_call,NULL);
	t2=procedure_call.tv_usec;
	printf("The second time stamp is %ld\n",t2);
	total_time=t2-t1;
	printf("Total time is %ld\n",total_time);

 	gettimeofday(&system_call,NULL);
	t3=system_call.tv_usec;
	printf("The first time stamp of system call is %ld\n",t3);
	for(i=0;i<ITERATION;i++)
	{
	k=getpid();
	}
	gettimeofday(&system_call,NULL);
	t4=system_call.tv_usec;
	printf("The second time stamp of system call is %ld\n",t4);
	total_time=t4-t3;
	printf("Total time is %ld\n",total_time);
}

#pragma GCC pop_options	

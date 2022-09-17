#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int sum,msum,csum;
void *runner(void *param);

int main (int agrc, char* argv[]){
	pthread_t tid;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_create(&tid, &attr, runner, argv[1]);
	pthread_join(tid, NULL);
	
	sum = atoi(argv[1]);
	printf("SUM : %d\n", sum);
	
	for(int i = 0; i <= sum; i++){
		msum += i;
	}	

	printf("CSUM - MSUM : %d\n", csum - msum);
	printf("MSUM : %d, CSUM %d", msum, csum);
	return 0;
}
void *runner(void *param){
	int upper = 2*atoi(param);
	csum = 0;

	if(upper > csum){
		for(int i = 0; i <= upper; i++){
			csum += i;
		}
		pthread_exit(0);
	}
}

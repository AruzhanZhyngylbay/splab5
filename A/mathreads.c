// your code goes here
#include <stdio.h>
#include <pthread.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int a=500,b=50;
int rAdd,rSub,rMul,rDev;

void* add(void * p){
	rAdd=a+b;
	pthread_exit(NULL);
}

void* sub(void * o){
	rSub=a-b;
	pthread_exit(NULL);
}

void* mul(void * i){
	rMul=a*b;
	pthread_exit(NULL);
}

void* dev(void * u){
	rDev=a/b;
	pthread_exit(NULL);
}

int main(int argc, char* argv[]){
	if (argc > 2){
		a=atoi(argv[1]);
		b=atoi(argv[2]);
	}

	pthread_t tAdd, tSub, tMul, tDev;

	pthread_create(&tAdd, NULL, add, NULL);

	pthread_join(tAdd, NULL);

	printf("Adding: ");
	printf("%d+%d=%d\n", a, b, rAdd);

	pthread_create(&tSub, NULL, sub, NULL);
	pthread_join(tSub, NULL);
	printf("Subtracting: ");
	printf("%d-%d=%d\n", a, b, rSub);

	pthread_create(&tMul, NULL, mul, NULL);
	pthread_join(tMul, NULL);
	printf("Multiplying: ");
	printf("%d*%d=%d\n", a, b, rMul);

	pthread_create(&tDev, NULL, dev, NULL);
	pthread_join(tDev, NULL);
	printf("Dividing: ");
	printf("%d/%d=%d\n", a, b, rDev);

	pthread_exit(NULL);
}

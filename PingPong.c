#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void* ping(void* arg) {
	int* i = (int*)arg;    //cast a void pointer to an int pointer

	while (*i < 13) {         //print 13 times
		printf("Ping\n");
		sleep(1);
		(*i)++;             //increment the i pointer
	}
	return i;               //return the incremented value
}
void pong() {
	int i = 0;
	while (i < 5) {           // loop iterator
		printf("Pong\n");   // prints pong
		sleep(2);
		i++;
	}
}
int main() {
	pthread_t thread1;      //create thread variable
	int val = 0;            //variable to pass through thread
	int *ret;               //catch return from the thread
	//create thread and perform Ping
	pthread_create(&thread1, NULL, ping, &val); //passs thread, ping , and address
	pong();                 //print pong
	//return i from thread1 and print it
	pthread_join(thread1, (void *)&ret);
	printf("Ping count: %d\n", *ret);    //print val passed through thread1
	return 0;
}
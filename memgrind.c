#include <stdio.h>
#include <sys/time.h>
#include "mymalloc.h"

int main() {
    struct timeval start, end;

	double sum=0;
	double avg=0;
	for(int a=0; a<50; a++){
   	// Get the start time
    	gettimeofday(&start, NULL);
	for(int i = 0; i < 120; i++) {
        	char *ptr = malloc(1);  // Allocate 1 byte of memory
        	free(ptr);  // Release the memory
    	}

    	// Get the end time
    	gettimeofday(&end, NULL);

    	// Calculate and print the elapsed time
    	long seconds = end.tv_sec - start.tv_sec;
    	long microseconds = end.tv_usec - start.tv_usec;
    	double elapsed = seconds + microseconds*1e-6;
	sum += elapsed;
	}
	avg = sum/50;
    	printf("Performance Test #1 - Average time elapsed: %.6f seconds.\n", avg);
	sum=0;
	avg=0;

	for(int a=0; a<50; a++){
	gettimeofday(&start, NULL);
	char *ptrArray[50];  // Array to store 120 pointers
    	for(int i = 0; i < 30; i++) {
        	ptrArray[i] = malloc(1);  // Allocate 1 byte of memory and store the address
    	}
    	for(int i = 0; i < 30; i++) {
        	free(ptrArray[i]);  // Release the memory
    	}
    	for(int i = 0; i < 30; i++) {
        	ptrArray[i] = malloc(1);  // Allocate 1 byte of memory and store the address
    	}
    	for(int i = 0; i < 30; i++) {
        	free(ptrArray[i]);  // Release the memory
    	}
    	for(int i = 0; i < 30; i++) {
        	ptrArray[i] = malloc(1);  // Allocate 1 byte of memory and store the address
    	}
    	for(int i = 0; i < 30; i++) {
        	free(ptrArray[i]);  // Release the memory
     	}
    	for(int i = 0; i < 30; i++) {
        	ptrArray[i] = malloc(1);  // Allocate 1 byte of memory and store the address
    	}

    	for(int i = 0; i < 30; i++) {
       		free(ptrArray[i]);  // Release the memory
	}
	gettimeofday(&end, NULL);
	long seconds = end.tv_sec - start.tv_sec;
        long microseconds = end.tv_usec - start.tv_usec;
        double elapsed = seconds + microseconds*1e-6;
	sum += elapsed;
        }
        avg = sum/50;
        printf("Performance Test #2 - Average time elapsed: %.6f seconds.\n", avg);
        sum=0;
        avg=0;

	for(int a=0; a<50; a++){
	gettimeofday(&start, NULL);
	char *ptrArray3[120];  // Array to store 120 pointers
    	int allocated[120] = {0};  // Initialize the memory allocation status array
    	int loc = 0;  // Current location

    	for(int i = 0; i < 120; i++) {
        	if(loc == 0 || (rand() % 2 == 0 && loc < 120)) {
            	// Allocate 1 byte of memory and store the address
            	//printf("alloc loc=%d\n", loc);
            	ptrArray3[loc] = malloc(1);
            	allocated[loc] = 1;
            	loc++;
        } else {
           	 // Release the memory
            	loc--;
            	//printf("free loc=%d\n", loc);
            	free(ptrArray3[loc]);
            	allocated[loc] = 0;
        	}
    	}
    	// Clean up any unreleased memory
    	for(int i = 0; i < 120; i++) {
        	if(allocated[i] == 1) {
            		free(ptrArray3[i]);
        	}
    	}
	gettimeofday(&end, NULL);
        long seconds = end.tv_sec - start.tv_sec;
        long microseconds = end.tv_usec - start.tv_usec;
        double elapsed = seconds + microseconds*1e-6;
	sum += elapsed;
        }
        avg = sum/50;
        printf("Performance Test #3 - Average time elapsed: %.6f seconds.\n", avg);
        sum=0;
        avg=0;

	for(int a=0; a<50; a++){
	gettimeofday(&start, NULL);
	char *ptrArray4[10];
	for(int i=0; i<5; i++){
		ptrArray4[i] = malloc(1);
		ptrArray4[i+1] = malloc(1);
	}
	for(int i=0; i<6; i++){
		free(ptrArray4[i]);
	}
	gettimeofday(&end, NULL);
        long seconds = end.tv_sec - start.tv_sec;
        long microseconds = end.tv_usec - start.tv_usec;
        double elapsed = seconds + microseconds*1e-6;
	sum += elapsed;
        }
        avg = sum/50;
        printf("Performance Test #4 - Average time elapsed: %.6f seconds.\n", avg);
        sum=0;
        avg=0;

	for(int a=0; a<50; a++){
	gettimeofday(&start, NULL);
	char* array5[30];
	for(int i=0; i<5; i++){
		array5[i] = malloc(1+rand()%4);
	}
	for(int j=0; j<5; j++){
		free(array5[j]);
	}
	gettimeofday(&end, NULL);
        long seconds = end.tv_sec - start.tv_sec;
        long microseconds = end.tv_usec - start.tv_usec;
        double elapsed = seconds + microseconds*1e-6;
	sum += elapsed;
        }
        avg = sum/50;
        printf("Performance Test #5 - Average time elapsed: %.6f seconds.\n", avg);

	return 0;
}


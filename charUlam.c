#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Array.h"


unsigned short isPrime(unsigned int num, Array array) {
	if (num == 1) {
		return 0;
	}

	unsigned int a = 0;
    unsigned int prime = array.array[a];
	while (prime && prime <= sqrt(num)) {
		if (num % prime == 0) {
			return 0;
		}
		a++;
    prime = array.array[a];
	}
	return 1;
}

void printCharAsBinary(unsigned char num, FILE * f) {
	int k, c;
	for (c = 7; c >= 0; c--) {
		k = num >> c;
		if (k & 1)
			fprintf(f, "X");
		else
			fprintf(f, " ");
	}
}

int main(int argc, char * argv[])
{

	Array a;
	initArray(&a, 5);
  insertArray(&a, 2);

	FILE * fp;
	fp = fopen ("output.txt", "w");
	if (fp == NULL) {
		exit(1);
	}

	unsigned int val = atoi(argv[1]);
	if (val % 2 != 1) {
		printf("Size of spiral must be odd.\n");
		exit(1);
	}

	unsigned int curRow, curCol;
	curRow = curCol = val/2;
	unsigned int numTimes = 0;
	unsigned int distanceCtr = 0;
	unsigned int distance = 1;
	unsigned short direction = 1; //1 = right, 2 = up, 3 = left, 4 = down.
	unsigned int i, j;

	unsigned char ** ulamSpiral = malloc (sizeof *ulamSpiral * val);
	if (ulamSpiral) {
		for (i = 0 ; i < val ; i++) {
			ulamSpiral[i] = malloc(sizeof *ulamSpiral[i] * val/8+1);
		}
	}

	int k;
	for (k = 0 ; k < val ; k++) {
		for (j = 0 ; j < val/8 + 1 ; j++) {
			ulamSpiral[k][j] = 0;
		}
	}

	for (i = 1 ; i <= pow(val, 2) ; i++) {
		if (isPrime(i, a)) {
			insertArray(&a, i);
			ulamSpiral[curRow][curCol/8] = ulamSpiral[curRow][curCol/8] | 128 >> curCol % 8;
		}

		if (numTimes == 2) {
			distance++;
			numTimes = 0;
		}

		if (direction == 1) {
			curCol++;
		} else if (direction == 2) {
			curRow--;
		} else if (direction == 3) {
			curCol--;
		} else if (direction == 4) {
			curRow++;
		}

		distanceCtr++;
		if (distanceCtr == distance) {
			distanceCtr = 0;
			numTimes++;
			if (direction == 4) {
				direction = 1;
			} else {
				direction++;
			}
		}
	}

	for (k = 0 ; k < val ; k++) {
		for (j = 0 ; j < val/8 + 1 ; j++) {
			printCharAsBinary(ulamSpiral[k][j], fp);
		}
		fprintf(fp, "\n");
	}

	freeArray(&a);

	return 0;
}

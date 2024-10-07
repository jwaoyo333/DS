//2022428313 øÏ¡§¡÷
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int front = 0;
int rear = 1;
int number = 0;
int max = 0;

void addQ(int * queue , int input) {
	rear = (rear + 1) % max;
	if (rear == front) {
		printf("queue full : cannot add.\n");
		exit(0);
	}

	queue[rear] = input;
	number++;
	return;
}

int deleteQ(int * queue) {
	if (front == rear) {
		printf("queue empty: cannot delete\n");
		exit(0);
	}
	
	front = (front + 1) % max;
	number--;
	return queue[front];
}

void printqueue(int* queue) {
	printf("Circular queue: ");
	if (rear <= front) {
		rear += max;
		for (int i = front; i < rear; i++) {
			if (i >= max) {
				printf("%d ", queue[i % max]);
			}
			else {
				printf("%d ", queue[i]);
			}
		}
	}else {
		for (int i = front; i < rear; i++) {
			printf("%d ", queue[i]);
		}
	}
	printf("\n");
	return;
}

int main(void) {

	int num = 0;
	FILE* fp = fopen("in1.txt", "r");
	fscanf(fp, "%d", &num);
	printf("Queue size : %d", num);
	int* queue = (int*)malloc(sizeof(int) * num);
	char input = NULL;
	int inputnum = 0;
	int output = 0;
	while (!feof(fp)) {
		fscanf(fp, "%c", &input);
		if (input == 'a') {
			fscanf(fp, "%d", &inputnum);
			addQ(queue, inputnum);
			printqueue(queue);
		}
		else if (input == 'd') {
			deleteQ(queue);
			printqueue(queue);
		}
	}

	return 0;
}
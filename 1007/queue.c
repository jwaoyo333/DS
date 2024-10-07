//2022428313 우정주
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>

int front = 0;
int rear = 0;
int max = 0;
int number = 0;

void addQ(int* queue, int input) {
	rear = (rear + 1) % max;
	if (rear == front) {
		printf("queue full : cannot add.\n");
		exit(0);
	}

	queue[rear] = input;
	number++;
	return;
}

int deleteQ(int* queue) {
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
	if (rear < front) {
		int sub = rear + max;
		for (int i = front+1; i < sub+1; i++) {
			if (i >= max) {
				printf("%d ", queue[i % max]);
			}
			else {
				printf("%d ", queue[i]);
			}
		}
	}
	else if (rear == front&&number == 0) {
		printf("queue is empty\n");
	}
	else if (rear == front && number == max-1) {
		int sub = rear + max;
		for (int i = front; i < sub; i++) {
			if (i >= max) {
				printf("%d ", queue[i % max]);
			}
			else {
				printf("%d ", queue[i]);
			}
		}
	}
	else {
		for (int i = front+1; i < rear+1; i++) {
			printf("%d ", queue[i]);
		}
	}
	printf("\n");
	return;
}

int main(void) {

	int num = 0;
	FILE* fp = fopen("in3.txt", "r");
	fscanf(fp, "%d", &num);
	printf("Queue size : %d\n", num);
	int* queue = (int*)calloc(num,sizeof(int));
	char input = NULL;
	int inputnum = 0;
	int output = 0;
	max = num;
	while (!feof(fp)) {
		fgetc(fp);
		fscanf(fp, "%c", &input);
		if (input == 'a') {
			fgetc(fp);
			fscanf(fp, "%d", &inputnum);
			addQ(queue, inputnum);
			printqueue(queue);
		}
		else if (input == 'd') {
			deleteQ(queue);
			printqueue(queue);
		}
	}
	free(queue);
	fclose(fp);
	return 0;
}

//2022428313 우정주
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>

int front = 0;
int rear = 0;
int max = 0;
int number = 0;

void addQ(int* queue, int input) { // 큐에 input값을 추가하는 함수
	rear = (rear + 1) % max;
	if (rear == front) {
		printf("queue full : cannot add.\n");
		exit(0);
	}

	queue[rear] = input;
	number++;
	return;
}

int deleteQ(int* queue) { // 큐에서 맨 앞에 있는 값을 제거하는 함수
	if (front == rear) {
		printf("queue empty: cannot delete\n");
		exit(0);
	}

	front = (front + 1) % max;
	number--;
	return queue[front];
}

void printqueue(int* queue) { // 큐를 출력하는 함수
	printf("Circular queue: ");
	if (rear < front) { //rear가 front보다 작으면 이미 max를 한 번찍고 넘어간 거임
		int sub = rear + max; // rear에 max를 더해 최대 실행 횟수를 정함
		for (int i = front+1; i < sub+1; i++) {
			if (i >= max) {
				printf("%d ", queue[i % max]);
			}
			else {
				printf("%d ", queue[i]);
			}
		}
	}
	else if (rear == front&&number == 0) { // number를 활용하여 queue가 비어있을 때를 구분
		printf("queue is empty\n");
	}
	else if (rear == front && number == max-1) { // number를 활용하여 큐가 꽉 차있을 때를 구분
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
	else { // 일반적인 rear가 front보다 큰 경우에는 순차적으로 출력하면 됨
		for (int i = front+1; i < rear+1; i++) { 
			printf("%d ", queue[i]);
		}
	}
	printf("\n");
	return;
}

int main(void) {

	int num = 0;
	FILE* fp = fopen("in.txt", "r");
	fscanf(fp, "%d", &num);
	printf("Queue size : %d\n", num);
	int* queue = (int*)calloc(num,sizeof(int));
	char input = NULL;
	int inputnum = 0;
	int output = 0;
	max = num;
	while (!feof(fp)) { // fp가 끝날 때까지 반복
		fgetc(fp);
		fscanf(fp, "%c", &input);
		if (input == 'a') { // a일 경우
			fgetc(fp); // 띄어쓰기 제거
			fscanf(fp, "%d", &inputnum); // 뒤에 오는 정수를 읽어줌
			addQ(queue, inputnum);
			printqueue(queue);
		}
		else if (input == 'd') { // d일 경우
			deleteQ(queue); // delete 실행후
			printqueue(queue); // 변화된 큐값 출력
		}
	}
	free(queue);
	fclose(fp);
	return 0;
}

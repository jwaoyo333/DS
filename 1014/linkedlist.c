
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct node {
	int num;
	struct node* next;
}; // 기본적인 노드 구조체

typedef struct node NODE; 
typedef NODE* Link;

Link createNode(int num) { // 노드를 생성하는 함수
	Link newone = (NODE*)malloc(sizeof(NODE)); // 새 노드를 동적할당으로 만든 뒤, 값을 대입후 return
	newone->num = num;
	newone->next = NULL;

	return newone; 
}

Link appendNode(Link head, Link cur) { 
	Link nextnode = head;
	if (!head) {
		head = cur;
		return head;
	}
	while (nextnode->next) {
		nextnode = nextnode->next;
		nextnode->next = cur;
	}
	return head;
}

Link addNode(Link head, Link cur) { // 맨 앞에 노드를 추가하는 함수
	cur->next = head; // head를 두 번째 노드로, cursor 노드를 head로 만든 뒤 head를 return
	head = cur;

	return head;
}

Link deleteNode(Link head, int key) { // key값을 기반으로 노드를 제거하는 함수, Insert, Add 함수도 안에 포함되어 있음(main함수에서 비교로직을 실행하면 비효율적이라 생각했기 때문)
	Link crt = head, prev= head;
	Link nextnode = crt->next;
	if(key<crt->num){  // key값이 헤드 값보다 작을 경우
		Link newnode = createNode(key);
		head = addNode(head, newnode); // addNode를 통해 바로 처리 후 리턴
		return head;
	}
	if (crt->num == key) { // key값이 헤드 노드와 같을 경우
		head = crt->next;
		free(crt); // head를 제거하는 제거 로직을 실행
		return head;
	}

	while (crt != NULL && crt->num <= key) { // 마지막 노드까지 그 값을 봐야하기에 node->next가 아닌, node가 Null일 경우로. 다만, crt->num이 앞으로 올 경우 참조에러가 발생하기에 crt 조건을 앞으로
		if (crt->num == key) { // key값과 일치하는 걸 찾을 경우 제거 실행
			prev->next = crt->next;
			free(crt);
			return head;
		}

		prev = crt;
		crt = crt->next;
	}
	
	// 서치에 실패했을 때의 경우의 수는 두 가지임. 맨 마지막 노드까지 검사했거나 or 중간에 끝났거나. 마지막 노드까지 검사했을 경우 crt가 NULL이라 쓸모없는 입력이 일어나지만, 코드가 길어지는 것보다는 낫다고 판단했기에 통합

	Link newnode = createNode(key);
	newnode->next = crt;
	prev->next = newnode;

	return head;
}

void printList(Link head) {// linked list를 순회하며 출력하는 함수
	Link crt = head;
	printf("list : ");
	while (crt) { // 마지막 노드값까지 출력해야 하기에 crt 노드가 NULL이 될 때까지 실행
		printf("%d ", crt->num);
		crt = crt->next;
	}
	printf("\n");

	return;
}

int main(void) {
	Link head = NULL, cur;
	int number = 0;
	FILE* fp = fopen("in.txt", "r");
	fscanf(fp, "%d", &number);
	for (int i = 0; i < number; i++) {
		int tmp = 0;
		fscanf(fp, "%d", &tmp);
		cur = createNode(tmp);
		head = addNode(head, cur);
	}
	printList(head);
	int input = 1;

	while (1) {
		
		printf("Input number : ");
		scanf("%d", &input);
		if (input == 0) {
			break;
		}
		head=deleteNode(head,input);
		printList(head);
	}

	printf("quit\n");
	return 0;
}

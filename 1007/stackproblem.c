//2022428313 우정주

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef enum {
	lparen, rparen, plus, minus, times, divide, mod, eos, lg, rg, and, or , operand
}precedence; // 열거형 변수 선언

int stack[100];
char symbol;
int n = 0;
int top = 0;

void push(int token) { // stack에 피연산자를 추가하는 함수
	stack[++top] = token;
	return;
}

int pop() {
	return stack[top--]; // stack의 top 요소를 출력하는 함수
}

precedence get_token(char expr[]) { // expr에서 토큰을 하나씩 읽어 precedence값으로 변환해주는 함수
	symbol = expr[n++];
	switch (symbol) {
	case'(':return lparen;
	case')':return rparen;
	case'+':return plus;
	case'-':return minus;
	case'/':return divide;
	case'*':return times;
	case'%':return mod;
	case'\n': case '\0': return eos;
	case'<':return lg;
	case'>':return rg;
	case'&':return and;
	case'|':return or ;
	default:return operand;
	}
}

int operation(precedence token, int fir, int sec) { //precedence의 종류에 따라 연산을 진행하는 함수
	int tmp = 0;
	switch (token) {
	case lparen:
		break;
	case rparen:
		break;
	case plus:
		tmp = fir + sec;
		return tmp;
		break;
	case minus:
		tmp = fir - sec;
		return tmp;
		break;
	case divide:
		tmp = fir / sec;
		return tmp;
		break;
	case times: 
		tmp = fir * sec;
		return tmp;
		break;
	case mod:
		tmp = fir % sec;
		return tmp;
		break;
	case eos: break;
	case lg: 
		break;
	case rg: 
		break;
	case and: 
		break;
	case or : 
		break;
	default: break;
	}
}

int main(void) {
	precedence token = 0;
	int sec, fir;
	int number = 0;
	int tmp = 0;
	char expression[3][100] = { "12/3-45*+67*-\0","342*+5-3/21*+57%-\0","123*+45+6*7-+\0" };
	for (int j = 0; j < 3; j++) {
		
		char* expr = expression[j]; // 포인터로 위에 입력된 string을 하나씩 가져옴
		printf("postfix expression : %s\n", expr);
		token = eos;
		stack[0] = eos;
		n = 0;
		top = 0; // 전역 변수로 선언했기 때문에 시작 전 초기화 해줘야함.

		while ((token = get_token(expr)) != eos) { // token을 받아 eos가 아닌 한 반복하는 조건
			if (token == operand) { // operand일 경우 push
				tmp = expr[n - 1] - 48; 
				push(tmp);
			}
			else { // operand가 아니면 연산자 -> 연산 실행
				sec = pop(); //차례대로 push 해서 피연산자 대입
				fir = pop();
				tmp = operation(token, fir, sec); // 연산
				push(tmp); // 결과 push
			}
		}

	tmp = pop(); // 마지막에 남은 피연산자 == 결과
	printf("evaluation result: %d\n", tmp); // 결과 출력
	}

	return 0;
}

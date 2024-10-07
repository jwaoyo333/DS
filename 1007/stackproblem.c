//2022428313 우정주

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef enum {
	lparen, rparen, plus, minus, times, divide, mod, eos, lg, rg, and, or , operand
}
precedence; // 열거형 변수 선언
int stack[100];
char expr[100];
char symbol;
int n = 0;
int top = 0;

void push(int token) { // token을 받아 stack에 추가하는 함수
	stack[++top] = token;
	return;
}

int pop() {
	return stack[top--]; // stack에서 precedence 타입의 token을 출력하는 함수
}

precedence get_token() { // expr에서 char을 받아 규칙에 맞추어 변환하는 함수
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

void operation(precedence token, int fir, int sec) { //precedence를 열거형의 규칙에 따라 출력하는 함수
	switch (token) {
	case lparen:
		break;
	case rparen:
		break;
	case plus:printf("+");
		break;
	case minus:printf("-");
		break;
	case divide:printf("/");
		break;
	case times: printf("*");
		break;
	case mod:printf("%%");
		break;
	case eos: break;
	case lg: printf("<");
		break;
	case rg: printf(">");
		break;
	caseand : printf("&");
		break;
	case or : printf("|");
		break;
	default: break;
	}
}

int main() {
	precedence token = 0;
	int sec, fir;
	int number = 0;


	for (int i = 0; i < number; i++) {
		token = eos;
		stack[0] = eos;
		n = 0;
		top = 0; // 전역 변수로 선언했기 때문에 시작 전 초기화 해줘야함.

		fgets(expr, 100, fp); // 라인 단위로 긁어옴
		for (int i = 0; i < 100; i++) {
			if (expr[i] == '\n') {
				expr[i] = '\0';
				break;
			} // fgets로 받아온 줄바꿈 연산자를 NULL 연산자로 변경 처리
		}
		printf("infix:\t%s\n", expr);
		printf("postfix : ");

		while ((token = get_token()) != eos) { // token을 받아 eos가 아닌 한 반복하는 조건
			if (token == operand) {
				
			}
			else if (token = ) {

			}
			else {
				sec = pop();
				fir = pop();
				push(fir);
			}
		}
		while (top > 0) {
			print_token(pop()); // eos 이후로는 남아있는 거 모두 출력
		}
		printf("\n\n");
	}

	fclose(fp);
	return 0;
}
//2022428313 ������

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef enum {
	lparen, rparen, plus, minus, times, divide, mod, eos, lg, rg, and, or , operand
}
precedence; // ������ ���� ����
int stack[100];
char expr[100];
char symbol;
int n = 0;
int top = 0;

void push(int token) { // token�� �޾� stack�� �߰��ϴ� �Լ�
	stack[++top] = token;
	return;
}

int pop() {
	return stack[top--]; // stack���� precedence Ÿ���� token�� ����ϴ� �Լ�
}

precedence get_token() { // expr���� char�� �޾� ��Ģ�� ���߾� ��ȯ�ϴ� �Լ�
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

void operation(precedence token, int fir, int sec) { //precedence�� �������� ��Ģ�� ���� ����ϴ� �Լ�
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
		top = 0; // ���� ������ �����߱� ������ ���� �� �ʱ�ȭ �������.

		fgets(expr, 100, fp); // ���� ������ �ܾ��
		for (int i = 0; i < 100; i++) {
			if (expr[i] == '\n') {
				expr[i] = '\0';
				break;
			} // fgets�� �޾ƿ� �ٹٲ� �����ڸ� NULL �����ڷ� ���� ó��
		}
		printf("infix:\t%s\n", expr);
		printf("postfix : ");

		while ((token = get_token()) != eos) { // token�� �޾� eos�� �ƴ� �� �ݺ��ϴ� ����
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
			print_token(pop()); // eos ���ķδ� �����ִ� �� ��� ���
		}
		printf("\n\n");
	}

	fclose(fp);
	return 0;
}
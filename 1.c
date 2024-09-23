#include <stdio.h>
#define MAX_TERMS 100

typedef struct {
	int expon;
	int coef;
}poly;

poly terms[MAX_TERMS];

int avail = 0;
int starta, finisha;

void padd(int startA, int finishA, int startB, int finishB, int *startD, int *finishD) {
	int coefficient;
	*startD = avail;
	while (startA <= finishA && startB <= finishB) {
		switch (COMPARE(terms[startA].expon, terms[startB].expon)) {

		}
	}
}

void attach(float coefficient, int exponent) {
	if (avail >= MAX_TERMS) {
		fprintf(stderr, "Too many terms in the polynomial\n");
		return;
	}
	terms[avail].coef = coefficient;
	terms[avail++].expon = exponent;

	return;
}

int main(void) {
	
}

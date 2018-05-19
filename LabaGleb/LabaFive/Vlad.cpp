// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>


#define __MATRIX__

typedef struct {
	//количество строк в массиве с данными
	unsigned int    m;
	//количество столбцов в массиве с данными
	unsigned int    n;
	//ссылка на массив с данными
	double          *a;
} TMatrix;

void mx_print(TMatrix *m) {
	unsigned int i, j;

	if (m != NULL) {
		if (m->a != NULL) {
			for (i = 0; i < m->m; i++) {
				for (j = 0; j < m->n; j++)
					printf("%8.2lf", m->a[i * m->n + j]);
				printf("\n");
			}
		}
	}
}

TMatrix *mx_identity(unsigned int n) {
	unsigned int i, j;
	TMatrix *m = NULL;

	m = (TMatrix*)malloc(sizeof(TMatrix));
	if (m != NULL) {
		m->a = (double*)malloc(n * n * sizeof(double));
		if (m->a != NULL) {
			m->n = m->m = n;
			for (i = 0; i < m->m; i++)
				for (j = 0; j < m->n; j++)
					m->a[i * n + j] = i == j ? 1 : 0;
		}
		else {
			free(m);
			m = NULL;
		}
	}

	return m;
}


TMatrix *mx_add(TMatrix *m1, TMatrix *m2) {
	if (m1->a == NULL) {
		return m2;
	}
	else if (m2->a == NULL) {
		return m1;
	}
	if (m1->n != m2->n) {
		if (m1->m != m2->m) {
			return NULL;
		}
	}
	TMatrix *a;
	a->m = m1->m; a->n = m1->n;
	for (unsigned int i = 0; i < m1->n; i++) {
		for (unsigned int k = 0; k < m1->m; i++)
			a->a[i*k] = m1->a[i*k] * m2->a[k*i];
	}
	return a;
}

int main(void) {
	TMatrix *m;
	TMatrix *n;
	TMatrix *k;

	m = mx_identity(3);
	n = mx_identity(3);
	
	k = mx_add(m, n);
	mx_print(k);
	printf("enithing");
	system("pause");
	return 0;
}
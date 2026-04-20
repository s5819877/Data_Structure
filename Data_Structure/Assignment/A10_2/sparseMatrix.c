#include <stdio.h>
#include <stdlib.h>

#include "sparseMatrix.h"

sparseMatrix* createSparseMatrix(int rows, int cols) {
	sparseMatrix* sm = (sparseMatrix*)malloc(sizeof(sparseMatrix));
	sm->rows = rows;
	sm->cols = cols;
	sm->list = createArrayList(rows * cols);
	return sm;
}

void addElementSparseMatrix(sparseMatrix* sm, int row, int col, int value) {
	int size;
	size = sizeArrayList(sm->list);

	insertArrayList(sm->list, size, (elementArrayList) { row, col, value });
}

void printSparseMatrix(sparseMatrix* sm) {
	printf("희소행렬입니다 (%d x %d)\n", sm->rows, sm->cols);
	printArrayList(sm->list);
}

void randomSparseMatrix(sparseMatrix* sm, int count) {

	int num = 0;

	while (num < count) {

		int r = rand() % sm->rows;
		int c = rand() % sm->cols;
		int v = rand() % 100 + 1;

		int dup = 0;

		for (int i = 0; i < sm->list->size; i++) {

			if (sm->list->data[i].row == r &&
				sm->list->data[i].col == c) {
				dup = 1;
				break;
			}
		}

		if (dup) 
			continue;

		elementArrayList e;
		e.row = r;
		e.col = c;
		e.value = v;

		insertSortedArrayList(sm->list, e);

		num++;
	}
}

sparseMatrix* transposeSparseMatrix(sparseMatrix* sm, int* moveCount) {

	sparseMatrix* result =
		createSparseMatrix(sm->cols, sm->rows);

	for (int i = 0; i < sizeArrayList(sm->list); i++) {

		elementArrayList e =
			getItemArrayList(sm->list, i);

		elementArrayList t =
		{ e.col, e.row, e.value };

		insertSortedArrayList(result->list, t);

		(*moveCount)++;
	}

	return result;
}

sparseMatrix* addSparseMatrix(sparseMatrix* sm1, sparseMatrix* sm2) {

	sparseMatrix* smresult =
		createSparseMatrix(sm1->rows, sm1->cols);

	int i = 0, j = 0;

	while (i < sm1->list->size && j < sm2->list->size) {

		elementArrayList a = sm1->list->data[i];
		elementArrayList b = sm2->list->data[j];

		elementArrayList r;

		if (a.row == b.row && a.col == b.col) {

			r.row = a.row;
			r.col = a.col;
			r.value = a.value + b.value;

			i++; j++;

		}
		else if (a.row < b.row ||
			(a.row == b.row && a.col < b.col)) {

			r = a;
			i++;

		}
		else {

			r = b;
			j++;
		}

		insertArrayList(smresult->list,
			smresult->list->size,
			r);
	}

	while (i < sm1->list->size)
		insertArrayList(smresult->list,
			smresult->list->size,
			sm1->list->data[i++]);

	while (j < sm2->list->size)
		insertArrayList(smresult->list,
			smresult->list->size,
			sm2->list->data[j++]);

	return smresult;
}
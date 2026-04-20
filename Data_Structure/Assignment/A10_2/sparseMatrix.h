#include <stdio.h>
#include <stdlib.h>

#include "arrayList.h"

typedef struct sparseMatrix {
	int rows;
	int cols;
	arrayList* list;
} sparseMatrix;

extern sparseMatrix* createSparseMatrix(int row, int col);
extern void addElementSparseMatrix(sparseMatrix* sm, int row, int col, int value);
extern void printSparseMatrix(sparseMatrix* sm);
extern void randomSparseMatrix(sparseMatrix* sm, int count);
extern sparseMatrix* transposeSparseMatrix(sparseMatrix* sm, int* moveCount);
extern sparseMatrix* addSparseMatrix(sparseMatrix* sm1, sparseMatrix* sm2);
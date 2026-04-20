#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sparseMatrix.h"

int main() {
	srand(time(NULL));

	sparseMatrix* sm = createSparseMatrix(10, 10);

	randomSparseMatrix(sm, 20);

	printf("Original Matrix\n");
	printSparseMatrix(sm);

	int moveCount = 0;

	sparseMatrix* transposed =
		transposeSparseMatrix(sm, &moveCount);

	printf("\nTransposed Matrix\n");
	printSparseMatrix(transposed);

	printf("\n데이터 이동 횟수: %d\n", moveCount);

	sparseMatrix* smresult =  addSparseMatrix(sm, transposed);
	printSparseMatrix(smresult);

	return 0;
}
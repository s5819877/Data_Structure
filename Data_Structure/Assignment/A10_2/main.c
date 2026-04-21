#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sparseMatrix.h"

int main() {
    srand(time(NULL));

    sparseMatrix* sm = createSparseMatrix(10, 10);
    randomSparseMatrix(sm, 20);

    printf("=== 원본 희소행렬 ===\n");
    printSparseMatrix(sm);

    int moveCount = 0;
    sparseMatrix* transposed = transposeSparseMatrix(sm, &moveCount);

    printf("\n=== 전치행렬 ===\n");
    printSparseMatrix(transposed);

    printf("\n데이터 이동 횟수: %d\n", moveCount);

    sparseMatrix* smsum = addSparseMatrix(sm, transposed);
    printf("\n=== 행렬 합 ===\n");
    printSparseMatrix(smsum);

    return 0;
}
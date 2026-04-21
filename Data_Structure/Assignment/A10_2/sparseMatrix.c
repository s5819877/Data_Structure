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
    int size = sizeArrayList(sm->list);
    insertArrayList(sm->list, size, (elementArrayList) { row, col, value });
}

void printSparseMatrix(sparseMatrix* sm) {
    printf("Sparse Matrix (%d x %d):\n", sm->rows, sm->cols);

    for (int r = 0; r < sm->rows; r++) {
        for (int c = 0; c < sm->cols; c++) {
            int val = 0;
            for (int i = 0; i < sizeArrayList(sm->list); i++) {
                elementArrayList e = getItemArrayList(sm->list, i);
                if (e.row == r && e.col == c) {
                    val = e.value;
                    break;
                }
            }
            printf("%4d", val);
        }
        printf("\n");
    }

    printArrayList(sm->list);
    printf("\n");
}

void randomSparseMatrix(sparseMatrix* sm, int count) {
    int num = 0;
    while (num < count) {
        int r = rand() % sm->rows;
        int c = rand() % sm->cols;
        int v = rand() % 100 + 1;

        int dup = 0;
        for (int i = 0; i < sizeArrayList(sm->list); i++) {
            elementArrayList e = getItemArrayList(sm->list, i);
            if (e.row == r && e.col == c) {
                dup = 1;
                break;
            }
        }

        if (!dup) {
            addElementSparseMatrix(sm, r, c, v);
            num++;
        }
    }
}

sparseMatrix* transposeSparseMatrix(sparseMatrix* sm, int* moveCount) {
    sparseMatrix* result = createSparseMatrix(sm->cols, sm->rows);
    *moveCount = 0;

    int size = sizeArrayList(sm->list);
    for (int c = 0; c < sm->cols; c++) {
        for (int i = 0; i < size; i++) {
            elementArrayList e = getItemArrayList(sm->list, i);
            if (e.col == c) {
                insertArrayList(result->list, sizeArrayList(result->list),
                    (elementArrayList) {
                    e.col, e.row, e.value
                });
                (*moveCount)++;
            }
        }
    }

    return result;
}

sparseMatrix* addSparseMatrix(sparseMatrix* sm1, sparseMatrix* sm2) {
    sparseMatrix* smResult = createSparseMatrix(sm1->rows, sm1->cols);

    for (int i = 0; i < sizeArrayList(sm1->list); i++) { // 범위 수정
        elementArrayList nonZeroOfSum1 = getItemArrayList(sm1->list, i);

        int j;
        for (j = 0; j < sizeArrayList(sm2->list); j++) { // 범위 수정
            elementArrayList nonZeroOfSum2
                = getItemArrayList(sm2->list, j);
            if (nonZeroOfSum1.row == nonZeroOfSum2.row &&
                nonZeroOfSum1.col == nonZeroOfSum2.col) {
                insertArrayList(smResult->list, sizeArrayList(smResult->list),
                    (elementArrayList) {
                    nonZeroOfSum1.row,
                    nonZeroOfSum1.col,
                    nonZeroOfSum1.value + nonZeroOfSum2.value
                });
                break;
            }
        }

        if (j == sizeArrayList(sm2->list)) {
            insertArrayList(smResult->list, sizeArrayList(smResult->list),
                nonZeroOfSum1);
        }
    }

    for (int j = 0; j < sizeArrayList(sm2->list); j++) { //sm2에 남은 원소 추가
        elementArrayList nonZeroOfSum2
            = getItemArrayList(sm2->list, j);

        int find = 0;
        for (int i = 0; i < sizeArrayList(sm1->list); i++) {
            elementArrayList nonZeroOfSum1
                = getItemArrayList(sm1->list, i);
            if (nonZeroOfSum1.row == nonZeroOfSum2.row &&
                nonZeroOfSum1.col == nonZeroOfSum2.col) {
                find = 1;
                break;
            }
        }

        if (!find) {
            insertArrayList(smResult->list, sizeArrayList(smResult->list),
                nonZeroOfSum2);
        }
    }

    return smResult;
}
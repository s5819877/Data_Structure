#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;

    printf("홀수 N 입력: ");
    scanf_s("%d", &N);

    if (N % 2 == 0) {
        printf("홀수만 입력 가능합니다.\n");
        return 1;
    }

    int *arr = (int*)malloc(N * N * sizeof(int));
    if (!arr) {
        printf("메모리 할당 실패\n");
        return 1;
    }

    for (int k = 0; k < N * N; k++)
        *(arr + k) = 0;

    int i = 0;
    int j = N / 2;
    for (int num = 1; num <= N * N; num++) {
        *(arr + i * N + j) = num;

        int next_i = (i - 1 + N) % N;
        int next_j = (j + 1) % N;

        if (*(arr + next_i * N + next_j) != 0) {
            i = (i + 1) % N;
        }
        else {
            i = next_i;
            j = next_j;
        }
    }

    printf("\n마방진 (%dx%d) :\n", N, N);
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++)
            printf("%4d", *(arr + i * N + j));
        printf("\n");
    }

    printf("\n<각 행의 합>\n");
    for (i = 0; i < N; i++) {
        int sum = 0;
        printf("%d행 : ", i + 1);
        for (j = 0; j < N; j++) {
            printf("%d + ", *(arr + i * N + j));
            sum += *(arr + i * N + j);
        }
        printf("\b\b= %d\n", sum);
    }

    printf("\n<각 열의 합>\n");
    for (j = 0; j < N; j++) {
        int sum = 0;
        printf("%d열 : ", j + 1);
        for (i = 0; i < N; i++) {
            printf("%d + ", *(arr + i * N + j));
            sum += *(arr + i * N + j);
        }
        printf("\b\b= %d\n", sum);
    }

    int diagsum[2] = { 0, 0 };
    printf("\n<각 대각선의 합>\n");
    for (i = 0; i < N; i++) {
        diagsum[0] += *(arr + i * N + i);           
        diagsum[1] += *(arr + i * N + (N - 1 - i)); 
    }
    printf("대각선 1 : ");
    for (i = 0; i < N; i++) printf("%d + ", *(arr + i * N + i));
    printf("\b\b= %d\n", diagsum[0]);

    printf("대각선 2 : ");
    for (i = 0; i < N; i++) printf("%d + ", *(arr + i * N + (N - 1 - i)));
    printf("\b\b= %d\n", diagsum[1]);

    free(arr);

    return 0;
}
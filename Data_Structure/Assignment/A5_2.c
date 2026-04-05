#include <stdio.h>
#define N 5  

int main() {
    int arr[N][N] = { 0 };
    int i, j, num;

    i = 0;
    j = N / 2;

    for (num = 1; num <= N * N; num++) {
        arr[i][j] = num;

        int next_i = (i - 1 + N) % N;
        int next_j = (j + 1) % N;

        if (arr[next_i][next_j] != 0) {
            i = (i + 1) % N;
        }
        else {
            i = next_i;
            j = next_j;
        }
    }

    printf("마방진 (%dx%d) :\n", N, N);
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%4d", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("<각 행의 합> \n");
    for (i = 0; i < N; i++) {
        int sum = 0;
        printf("%d행 : ", i + 1);
        for (j = 0; j < N; j++) {
            printf("%d + ", arr[i][j]);
            sum += arr[i][j];
        }
        printf("\b\b= %d\n", sum);
    }
    printf("\n");

    printf("<각 열의 합> \n");
    for (j = 0; j < N; j++) {
        int sum = 0;
        printf("%d열 : ", j + 1);
        for (i = 0; i < N; i++) {
            printf("%d + ", arr[i][j]);
            sum += arr[i][j];
        }
        printf("\b\b= %d\n", sum);
    }
    printf("\n");

    int diagsum[2] = { 0 };
    int diagarr[2][N] = { 0 };
    for (i = 0; i < N; i++) {
        diagarr[0][i] = arr[i][i];
        diagsum[0] += arr[i][i];
        diagarr[1][i] = arr[i][N - 1 - i];
        diagsum[1] += arr[i][N - 1 - i];
    }

    printf("<각 대각선의 합> \n");
    for (j = 0; j < 2; j++) {
        printf("대각선 %d : ", j + 1);
        for (i = 0; i < N; i++) {
            printf("%d + ", diagarr[j][i]);
        }
        printf("\b\b= %d\n", diagsum[j]);
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int *arr;
    int N;
    int i;
    int sum = 0;
    int max, min;

    printf("배열 크기 N 입력: ");
    scanf_s("%d", &N);

    arr = (int*)malloc(N * sizeof(int));
    if (arr == NULL) {
        printf("메모리 할당 실패!\n");
        return 1;
    }

    srand(time(NULL));

    for (i = 0; i < N; i++) {
        *(arr + i) = rand() % (N + 1);
    }

    printf("정방향 출력: ");
    for (i = 0; i < N; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");

    printf("역방향 출력: ");
    for (i = N - 1; i >= 0; i--) {
        printf("%d ", *(arr + i));
    }
    printf("\n");

    max = *(arr);
    min = *(arr);

    for (i = 0; i < N; i++) {
        sum += *(arr + i);

        if (*(arr + i) > max) {
            max = *(arr + i);
        }

        if (*(arr + i) < min) {
            min = *(arr + i);
        }
    }

    printf("총합: %d\n", sum);
    printf("최대값: %d\n", max);
    printf("최소값: %d\n", min);

    free(arr);

    return 0;
}
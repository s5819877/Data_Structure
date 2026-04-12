/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME 50

typedef struct {
    char name[MAX_NAME];
    int id;
    int score;
} Student;

int main() {
    FILE* fp = fopen("C:\\Users\\jongh\\source\\repos\\Data_Structure\\Data_Structure\\Assignment\\A7\\name_list.txt", "r");
    if (fp == NULL) {
        printf("파일 열기 실패\n");
        return 0;
    }

    int count = 0;
    char temp[MAX_NAME];

    while (fgets(temp, MAX_NAME, fp) != NULL) {
        count++;
    }

    rewind(fp);

    char (*name_list)[MAX_NAME] = malloc(sizeof(char) * MAX_NAME * count);

    for (int i = 0; i < count; i++) {
        fgets(name_list[i], MAX_NAME, fp);
        name_list[i][strcspn(name_list[i], "\n")] = '\0';
    }

    fclose(fp);

    int N;
    printf("학생 수 입력: ");
    scanf_s("%d", &N);

    Student* arr = malloc(sizeof(Student) * N);

    srand(time(NULL));

    for (int i = 0; i < N; i++) {
        int idx = rand() % count;

        strcpy(arr[i].name, name_list[idx]);
        arr[i].id = i + 1;
        arr[i].score = rand() % 100 + 1;
    }

    int max_idx = 0, min_idx = 0, sum = 0;

    for (int i = 0; i < N; i++) {
        if (arr[i].score > arr[max_idx].score)
            max_idx = i;

        if (arr[i].score < arr[min_idx].score)
            min_idx = i;

        sum += arr[i].score;
    }

    double avg = (double)sum / N;

    printf("\n[최고점 학생]\n학번 : %d\n이름 : %s\n점수 : %d\n",
        arr[max_idx].id, arr[max_idx].name, arr[max_idx].score);

    printf("\n[최저점 학생]\n학번 : %d\n이름 : %s\n점수 : %d\n",
        arr[min_idx].id, arr[min_idx].name, arr[min_idx].score);

    printf("\n평균: %.2f\n", avg);

    free(name_list);
    free(arr);

    return 0;
}
*/
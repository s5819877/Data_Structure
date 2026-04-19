/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arrayList.h"

int inputNumber(int min) {
    int value;
    char input[100], extra;

    while (1) {
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;

        if (sscanf_s(input, "%d %c", &value, &extra) != 1) {
            printf("정수만 입력 가능합니다\n");
            return -1;
        }

        if (value < min) {
            return -1;
        }

        return value;
    }
}

int main() {
	arrayList* myArrayList;
	myArrayList = createArrayList(100);

	if (sizeArrayList(myArrayList) == 0) {
		printf("Create ok\n");
	}

	int choice, pos, value;

	while (1) {
		printf("\n===== 메뉴 =====\n");
		printf("1. 삽입 (insert)\n");
		printf("2. 삭제 (delete)\n");
		printf("3. 변경 (replace)\n");
		printf("4. 출력 (print)\n");
		printf("5. 전체 삭제 (clear)\n");
		printf("0. 종료\n");
		printf("선택: ");

        choice = inputNumber(0);

        if (choice < 0 || choice > 5) {
            printf("메뉴 숫자 중에서 고르세요\n");
            continue;
        }

        switch (choice) {
        case 1: // insert
            printf("위치 입력: ");
            pos = inputNumber(0);

            if (pos < 0 || pos > myArrayList->size) {
                printf("삽입 가능한 위치는 0 ~ %d까지입니다\n", myArrayList->size);
                continue;
            }

            printf("값 입력(양의 정수): ");
            value = inputNumber(1);

            if (value < 1) {
                printf("양의 정수를 입력하세요\n");
                continue;
            }

            if (!insertArrayList(myArrayList, pos, value)) {
                printf("삽입 실패\n");
            }
            break;

        case 2: // delete
            if (myArrayList->size == 0) {
                printf("리스트가 비어있습니다\n");
                continue;
            }

            printf("위치 입력: ");
            pos = inputNumber(0);

            if (pos < 0 || pos > myArrayList->size-1) {
                printf("삭제 가능한 위치는 0 ~ %d까지입니다\n", myArrayList->size - 1);
                continue;
            }

            if (deleteArrayList(myArrayList, pos) == -1) {
                printf("삭제 실패\n");
            }
            break;

        case 3: // replace
            if (myArrayList->size == 0) {
                printf("리스트가 비어있습니다\n");
                continue;
            }

            printf("위치 입력: ");
            pos = inputNumber(0);

            if (pos < 0 || pos > myArrayList->size - 1) {
                printf("변경 가능한 위치는 0 ~ %d까지입니다\n", myArrayList->size - 1);
                continue;
            }
            printf("값 입력(양의 정수): ");
            value = inputNumber(1);

            if (value < 1) {
                printf("양의 정수를 입력하세요\n");
                continue;
            }

            if (!replaceItemArrayList(myArrayList, pos, value)) {
                printf("변경 실패\n");
            }
            break;

        case 4: // print
            printArrayList(myArrayList);
            break;

        case 5: // clear
            initArrayList(myArrayList);
            printf("전체 삭제 완료\n");
            break;

        case 0:
            destroyArrayList(myArrayList);
            printf("종료\n");
            return 0;

        default:
            printf("잘못된 입력\n");
        }
    }

    return 0;
}
*/
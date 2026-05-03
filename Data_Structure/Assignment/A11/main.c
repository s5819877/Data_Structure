#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "polynomial.h"

polynomial* parsePolynomial(const char* input) {
    polynomial* po = createPolynomial(100);
    const char* p = input;

    while (*p != '\0' && *p != '\n') {
        while (isspace((unsigned char)*p)) p++;
        if (*p == '\0' || *p == '\n') break;

        int sign = 1;
        if (*p == '-') {
            sign = -1;
            p++;
            while (isspace((unsigned char)*p)) p++;
        }
        else if (*p == '+') {
            sign = 1;
            p++;
            while (isspace((unsigned char)*p)) p++;
        }

        if (!isdigit((unsigned char)*p)) {
            printf("[오류] 계수(숫자)를 찾을 수 없습니다\n");
            destroyArrayList(po);
            return NULL;
        }
        int coef = 0;
        while (isdigit((unsigned char)*p)) {
            coef = coef * 10 + (*p - '0');
            p++;
        }
        coef *= sign;

        if (*p != 'X' && *p != 'x') {
            printf("[오류] 'X'가 필요합니다\n");
            destroyArrayList(po);
            return NULL;
        }
        p++;

        if (*p != '^') {
            printf("[오류] '^'가 필요합니다\n");
            destroyArrayList(po);
            return NULL;
        }
        p++;

        if (!isdigit((unsigned char)*p)) {
            printf("[오류] 지수(숫자)를 찾을 수 없습니다\n");
            destroyArrayList(po);
            return NULL;
        }
        int expo = 0;
        while (isdigit((unsigned char)*p)) {
            expo = expo * 10 + (*p - '0');
            p++;
        }

        addItemPolynomial(po, (elementType) { coef, expo });

        while (isspace((unsigned char)*p)) p++;

        if (*p != '\0' && *p != '\n' && *p != '+' && *p != '-') {
            printf("[오류] '+', '-' 또는 끝이 필요합니다\n");
            destroyArrayList(po);
            return NULL;
        }
    }

    if (sizeArrayList(po) == 0) {
        printf("[오류] 항이 하나도 없습니다.\n");
        destroyArrayList(po);
        return NULL;
    }

    return po;
}

polynomial* inputPolynomial(const char* name) {
    char buf[512];
    while (1) {
        printf("%s 입력 (예: 3X^2+2X^1-1X^0): ", name);
        if (fgets(buf, sizeof(buf), stdin) == NULL) continue;
        buf[strcspn(buf, "\n")] = '\0';

        if (strlen(buf) == 0) {
            printf("[오류] 빈 입력입니다.\n다시 입력하세요.\n\n");
            continue;
        }

        polynomial* po = parsePolynomial(buf);
        if (po != NULL) return po;

        printf("다시 입력해주세요.\n\n");
    }
}

void printMenu() {
    printf("\n=============================\n");
    printf("다항식 계산기\n");
    printf("=============================\n");
    printf("1. 덧셈  (p1 + p2)\n");
    printf("2. 곱셈  (p1 * p2)\n");
    printf("3. 나가기\n");
    printf("=============================\n");
    printf("선택: ");
}

int main() {
    char buf[16];

    printf("==============================\n");
    printf("다항식 계산기\n");
    printf("==============================\n");
    printf("입력 형식: 계수X^지수+계수X^지수+...\n");
    printf("예시 : 3X^2+2X^1-1X^0\n");

    while (1) {
        printMenu();

        if (fgets(buf, sizeof(buf), stdin) == NULL) break;
        int choice = atoi(buf);

        if (choice == 3) {
            printf("\n프로그램을 종료합니다.\n");
            break;
        }

        if (choice != 1 && choice != 2) {
            printf("[오류] 1, 2, 3 중 하나를 입력하세요.\n");
            continue;
        }

        printf("\n── 다항식 입력 ──\n");
        polynomial* p1 = inputPolynomial("p1");
        printf("p1 = ");
        printPolynomial(p1);
        printf("\n");

        polynomial* p2 = inputPolynomial("p2");
        printf("p2 = ");
        printPolynomial(p2);

        printf("\n── 결과 ──\n");

        if (choice == 1) {
            polynomial* result = addPolynomial(p1, p2);
            printf("p1 + p2 = ");
            printPolynomial(result);
            destroyArrayList(result);
        }
        else {
            polynomial* result = multiplyPolynomial(p1, p2);
            printf("p1 * p2 = ");
            printPolynomial(result);
            destroyArrayList(result);
        }

        destroyArrayList(p1);
        destroyArrayList(p2);
    }

    return 0;
}
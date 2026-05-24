#define _CRT_SECURE_NO_WARNINGS
#include "LinkedStack.h"

void printMenu() {
    printf("======= 스택 메뉴 =======\n");
    printf("1. URL 추가\n");
    printf("2. URL 제거\n");
    printf("3. 스택 확인\n");
    printf("=========================\n");
    printf("선택 : ");
}

int main() {
    LinkedStack* myStack = createLinkedStack();
    int choice;
    char url[256];

    while (1) {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("URL 입력 : ");
            scanf("%s", url);
            pushLinkedStack(myStack, url);
            printf("현재 창 : %s\n\n", peekLinkedStack(myStack));
            break;

        case 2:
            if (emptyLinkedStack(myStack)) {
                printf("스택이 비어있습니다.\n\n");
                break;
            }

            stackElement popstack = popLinkedStack(myStack);
            printf("이탈 : %s\n", popstack);
            free(popstack);

            if (emptyLinkedStack(myStack)) {
                printf("브라우저가 종료되었습니다.\n");
                destroyLinkedStack(myStack);
                return 0;
            }
            else {
                printf("현재 창 : %s\n\n", peekLinkedStack(myStack));
            }

            break;

        case 3:
            if (emptyLinkedStack(myStack)) {
                printf("스택이 비어있습니다.\n\n");
            }
            else {
                printf("현재 창 : %s\n\n", peekLinkedStack(myStack));
            }
            break;

        default:
            printf("잘못된 입력입니다. 다시 입력해주세요\n\n");
            break;
        }
    }
}

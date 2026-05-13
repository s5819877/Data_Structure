#include "LinkedList.h"

void printMenu() {
	printf("\n============ 연결리스트 메뉴 ============\n");
	printf(" 1. 맨 앞에 추가\n");
	printf(" 2. 맨 뒤에 추가\n");
	printf(" 3. 특정 위치에 추가\n");
	printf(" 4. 특정 위치 삭제\n");
	printf(" 5. 전체 목록 출력\n");
	printf(" 6. 리스트 크기 확인\n");
	printf(" 0. 종료\n");
	printf("=========================================\n");
	printf("선택 : ");
}

int main() {
	LinkedList* myList;
	myList = createLinkedList();
	int choice, num, pos;

	while (1) {
		printMenu();
		scanf_s("%d", &choice);

		switch (choice) {
		case 1:
			printf("추가할 정수 입력 : ");
			scanf_s("%d", &num);
			insertFirstLinkedList(myList, (PointType) { num, 0 });
			break;

		case 2:
			printf("추가할 정수 입력 : ");
			scanf_s("%d", &num);
			insertLastLinkedList(myList, (PointType) { num, 0 });
			break;

		case 3:
			printf("삽입할 위치 입력(0 ~ %d) : ", myList->size);
			scanf_s("%d", &pos);
			printf("추가할 정수 입력 : ");
			scanf_s("%d", &num);
			insertAtLinkedList(myList, pos, (PointType) { num, 0 });
			break;

		case 4:
			if (isEmptyLinkedList(myList)) {
				printf("리스트가 비어 있습니다.\n");
				break;
			}

			printf("삭제할 위치 입력(0 ~ %d) : ", myList->size - 1);
			scanf_s("%d", &pos);
			deleteAtLinkedList(myList, pos);
			break;

		case 5:
			printLinkedList(myList);
			break;
			
		case 6:
			printf("현재 리스트 크기 : %d\n", sizeLinkedList(myList));
			break;

		case 0:
			destroyLinkedList(myList);
			printf("프로그램을 종료합니다.\n");
			return 0;

		default:
			printf("잘못된 선택입니다. 다시 입력해주세요.\n");
			break;
		}
	}
}
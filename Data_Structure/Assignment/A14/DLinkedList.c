#include "DLinkedList.h"

DLinkedList* createDLinkedList() {
	DLinkedList* temp;
	temp = (DLinkedList*)malloc(sizeof(DLinkedList));
	temp->head.prev = &(temp->head);
	temp->head.next = &(temp->head);
	temp->size = 0;

	return temp;
}

void destroyDLinkedList(DLinkedList* dl) {
	while (dl->size != 0) {
		deleteFirstDLinkedList(dl);
	}

	free(dl);
}

int isEmptyDLinkedList(DLinkedList* dl) {
	return (dl->size == 0);
}

int sizeDLinkedList(DLinkedList* dl) {
	return dl->size;
}

int insertFirstDLinkedList(DLinkedList* dl, PointType item) {
	PointType* nPtr = (PointType*)malloc(sizeof(PointType));
	*nPtr = item;

	nPtr->prev = &(dl->head);
	nPtr->next = dl->head.next;
	dl->head.next = nPtr;
	nPtr->next->prev = nPtr;

	dl->size++;
}

int insertLastDLinkedList(DLinkedList* dl, PointType item) {
	PointType* nPtr = (PointType*)malloc(sizeof(PointType));
	*nPtr = item;

	nPtr->prev = dl->head.prev;
	nPtr->next = &(dl->head);
	nPtr->prev->next = nPtr;
	nPtr->next->prev = nPtr;

	dl->size++;
}

int insertAtDLinkedList(DLinkedList* dl, int pos, PointType item) {
	if (pos < 0 || pos>dl->size) {
		printf("범위를 벗어난 위치입니다.\n");
		return -1;
	}

	if (pos == 0) {
		return insertFirstDLinkedList(dl, item);
	}

	if (pos == dl->size) {
		return insertLastDLinkedList(dl, item);
	}

	PointType* start = dl->head.next;
	for (int i = 0; i < pos; i++) {
		start = start->next;
	}

	PointType* nPtr = (PointType*)malloc(sizeof(PointType));
	*nPtr = item;

	nPtr->prev = start->prev;
	nPtr->next = start;
	start->prev->next = nPtr;
	start->prev = nPtr;

	dl->size++;
}

PointType deleteFirstDLinkedList(DLinkedList* dl) {
	PointType* temp = dl->head.next;
	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;

	dl->size--;
	free(temp);
}

PointType deleteAtDLinkedList(DLinkedList* dl, int pos) {
	if (pos < 0 || pos >= dl->size) {
		printf("범위를 벗어난 위치입니다.\n");
		return (PointType) { 0, 0, 0 };
	}

	PointType* start = dl->head.next;
	for (int i = 0; i < pos; i++) {
		start = start->next;
	}

	start->prev->next = start->next;
	start->next->prev = start->prev;

	free(start);
	dl->size--;
}

void printDLinkedList(DLinkedList* dl) {
	printf("Print DLinkedList:\n");
	printf("Size: %d\n", dl->size);

	if (dl->size == 0) {
		return;
	}

	PointType* start = dl->head.next;

	for (int i = 0; i < dl->size; i++) {
		printf("[%d] num: %d, next: %x\n", i, start->num, start->next);

		start = start->next;
	}
}
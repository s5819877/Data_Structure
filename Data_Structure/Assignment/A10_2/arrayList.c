#include <stdio.h>
#include <stdlib.h>

#include "arrayList.h"

arrayList* createArrayList(int size) {
	arrayList* al;
	al = (arrayList*)malloc(sizeof(arrayList));

	al->data = (elementArrayList*)malloc(
		sizeof(elementArrayList) * size);
	al->size = 0;
	al->capacity = size;

	return al;
}

void destroyArrayList(arrayList* al) {
	free(al->data);
	free(al);
}

int isEmptyArrayList(arrayList* al) {
	if (al->size == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

int isFullArrayList(arrayList* al) {
	if (al->size == al->capacity) {
		return 1;
	}
	else {
		return 0;
	}
}

int sizeArrayList(arrayList* al) {
	return al->size;
}

int insertArrayList(arrayList* al,
	int pos, elementArrayList item) {
	if (pos < 0 || pos > al->size) {
		return 0;
	}

	if (isFullArrayList(al)) {
		int newCapacity = al->capacity * 2;

		elementArrayList* newData =
			realloc(al->data, sizeof(elementArrayList) * newCapacity);

		if (newData == NULL) {
			fprintf(stderr, "메모리 재할당 실패\n");
			return 0;
		}

		al->data = newData;
		al->capacity = newCapacity;
	}

	for (int i = al->size - 1; i >= pos; i--) {
		al->data[i + 1] = al->data[i];
	}

	al->data[pos] = item;
	al->size++;

	return 1;
}

int insertSortedArrayList(arrayList* al, elementArrayList item) {

	int pos = 0;

	while (pos < al->size) {

		elementArrayList cur = al->data[pos];

		if (cur.row > item.row ||
			(cur.row == item.row && cur.col > item.col)) {
			break;
		}

		pos++;
	}

	return insertArrayList(al, pos, item);
}

elementArrayList deleteArrayList(
	arrayList* al, int pos) {
	if (pos < 0 || pos > al->size - 1) {
		fprintf(stderr, "범위 벗어남\n");
		exit(1);
	}

	elementArrayList item = al->data[pos];

	for (int i = pos; i < al->size - 1; i++) {
		al->data[i] = al->data[i + 1];
	}

	al->size--;

	return item;
}

void initArrayList(arrayList* al) {
	al->size = 0;
}

elementArrayList getItemArrayList(
	arrayList* al, int pos) {
	return al->data[pos];
}

int replaceItemArrayList(arrayList* al,
	int pos, elementArrayList item) {
	if (pos < 0 || pos > al->size - 1) {
		return 0;
	}

	al->data[pos] = item;

	return 1;
}

void printArrayList(arrayList* al) {
	printf("희소 행렬 순차 리스트\n");

	printf("cap: %d, size: %d\n", al->capacity, al->size);

	for (int i = 0; i < al->size; i++) {
		printf("(%d, %d, %d) ", al->data[i].row,
			al->data[i].col, al->data[i].value);
	}
	printf("\n");
}

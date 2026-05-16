#include <stdio.h>
#include <stdlib.h>

typedef struct pointType {
	int num;
	struct pointType* prev;
	struct pointType* next;
} PointType;

typedef struct dLinkedList {
	PointType head;
	int size;
} DLinkedList;

extern DLinkedList* createDLinkedList();
extern void destroyDLinkedList(DLinkedList* dl);

extern int isEmptyDLinkedList(DLinkedList* dl);
extern int sizeDLinkedList(DLinkedList* dl);

extern int insertFirstDLinkedList(DLinkedList* dl, PointType item);
extern int insertLastDLinkedList(DLinkedList* dl, PointType item);
extern int insertAtDLinkedList(DLinkedList* dl, int pos, PointType item);

extern PointType deleteFirstDLinkedList(DLinkedList* dl);
extern PointType deleteAtDLinkedList(DLinkedList* dl, int pos);

extern void printDLinkedList(DLinkedList* dl);
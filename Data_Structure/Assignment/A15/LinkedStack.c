#define _CRT_SECURE_NO_WARNINGS
#include "LinkedStack.h"

LinkedStack* createLinkedStack() {
    LinkedStack* re = (LinkedStack*)malloc(sizeof(LinkedStack));
    re->head = NULL;
    re->size = 0;

    return re;
}

int destroyLinkedStack(LinkedStack* s) {
    Node* temp = s->head;
    while (temp != NULL) {
        Node* next = temp->next;
        free(temp->data);
        free(temp);
        temp = next;
    }
    free(s);

    return 1;
}

int emptyLinkedStack(LinkedStack* s) {
    return s->size == 0;
}

int fullLinkedStack(LinkedStack* s) {
    return 0;
}

int pushLinkedStack(LinkedStack* s, stackElement item) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = (char*)malloc(sizeof(char) * strlen(item) + 1);
    strcpy(temp->data, item);
    temp->next = s->head;
    s->head = temp;
    s->size++;
    return 1;
}

stackElement popLinkedStack(LinkedStack* s) {
    if (emptyLinkedStack(s)) {
        return (stackElement)NULL;
    }

    Node* temp = s->head;
    stackElement data = temp->data;
    s->head = temp->next;
    free(temp);
    s->size--;
    return data;
}

stackElement peekLinkedStack(LinkedStack* s) {
    if (emptyLinkedStack(s)) {
        return (stackElement)NULL;
    }
    return s->head->data;
}

void printLinkedStack(LinkedStack* s) {
    printf("Stack:\n");
    printf("Size: %d\n", s->size);
    Node* temp = s->head;
    while (temp != NULL) {
        printf("%s\n", temp->data);
        temp = temp->next;
    }
}
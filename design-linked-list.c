/* This is a terrible implementation */
#include <stdio.h>
#include <stdlib.h>


struct node {
    int val;
    struct node* next;
};

typedef struct {
    struct node* head;    
} MyLinkedList;


MyLinkedList* myLinkedListCreate() {
    MyLinkedList* list = malloc(sizeof(*list));
    list->head = NULL;
    return list;
}

int myLinkedListGet(MyLinkedList* obj, int index) {

    if (obj->head == NULL) { return -1; }

    struct node* checkNode = obj->head;


    for (int i = 0; i < index; i++) {
        checkNode = checkNode->next;
        if (checkNode == NULL) { return -1; }
    }
    
    return checkNode->val;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    struct node* newNode = malloc(sizeof(struct node));
    newNode->val = val;
    newNode->next = obj->head;

    obj->head = newNode;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    struct node* newNode = malloc(sizeof(struct node));
    newNode->val = val;
    newNode->next = NULL;

    if (obj->head == NULL) {
        obj->head = newNode;
        return;
    }
    
    struct node* lastNode = obj->head;
    while (lastNode->next != NULL){
        lastNode = lastNode->next;
    }

    lastNode->next = newNode;
    newNode = NULL;
}

/* I don't like this implementation, could probably be made better
by using a checking node for reference instead of asigning 
the next of our new node for checking */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {

    if (obj->head == NULL && index != 0) { return; }

    if (index == 0){
        myLinkedListAddAtHead(obj, val);
        return;
    }


    struct node* newNode = malloc(sizeof(struct node));
    newNode->next = obj->head;
    newNode->val = val;

    for (int i = 0; i < index - 1; i++) {
        if (newNode->next->next == NULL){ break; }
        newNode->next = newNode->next->next;
    }
    
    struct node* tempNext = newNode->next->next;
    newNode->next->next = newNode;
    newNode->next = tempNext;
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index == 0) {
        struct node* tempNode = obj->head;
        obj->head = tempNode->next;
        free(tempNode);
        return;
    }

    struct node* checkNode = obj->head;

    if (checkNode->next == NULL && index >= 1){
        return;
    }

    for (int i = 1; i < index; i++) {
        if (checkNode->next->next == NULL) {return;}
        checkNode = checkNode->next;
    }

    struct node* tempNode = checkNode->next;
    checkNode->next = tempNode->next;
    free(tempNode);
}

void myLinkedListFree(MyLinkedList* obj) {

    struct node* delNode = obj->head;

    if (delNode == NULL) {
        free(obj);
        return;
    }

    struct node* tempNode = delNode->next;

    while (tempNode != NULL){
        free(delNode);
        delNode = tempNode;
        tempNode = tempNode->next;
    }

    free(obj);
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/
int main() {
    MyLinkedList* obj = myLinkedListCreate();
    myLinkedListAddAtIndex(obj, 1, 0);
    printf("%d\n", myLinkedListGet(obj, 0));

    struct node* printNode = obj->head;
    while (printNode != NULL) {
        printf("%d\n", printNode->val);
        printNode = printNode->next;
    }

    return 0;
}

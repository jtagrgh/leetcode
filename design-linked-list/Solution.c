// https://leetcode.com/problems/design-linked-list

/* What I plan to improve:
    - Add dummy head and tail nodes
    - Add tail pointer to list struct
*/
#include <stdio.h>
#include <stdlib.h>


struct node {
    int val;
    struct node* next;
};

typedef struct {
    struct node* head;
    struct node* tail;
} MyLinkedList;


MyLinkedList* myLinkedListCreate() {
    MyLinkedList* list = malloc(sizeof(MyLinkedList));

    list->head = malloc(sizeof(struct node));
    list->tail = malloc(sizeof(struct node));
    list->tail->next = NULL;
    list->head->next = list->tail;

    return list;
}

/* Negative index returns first node */
int myLinkedListGet(MyLinkedList* obj, int index) {
    /* Checks if there's no elements */
    if (obj->head->next == obj->tail) { return -1; }

    struct node* nodeSeeker = obj->head->next;

    for (int i = 0; i < index; i++) {
        nodeSeeker = nodeSeeker->next;
        if (nodeSeeker == obj->tail) { return -1; }
    }

    return nodeSeeker->val;
}


void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    struct node* newNode = malloc(sizeof(struct node));
    newNode->val = val;

    newNode->next = obj->head->next;
    obj->head->next = newNode;
}


void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    struct node* newNode = malloc(sizeof(struct node));
    newNode->next = NULL;
    obj->tail->next = newNode;

    obj->tail->val = val;
    obj->tail = newNode;    
}


void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    struct node* nodeSeeker = obj->head;
    struct node* newNode = malloc(sizeof(struct node));
    newNode->val = val;

    for (int i = 0; i < index; i++){
        nodeSeeker = nodeSeeker->next;    
        if (nodeSeeker == obj->tail){ return; }
    }

    newNode->next = nodeSeeker->next;
    nodeSeeker->next = newNode;
}


/* Negative numbers delete first node */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    /* Checks if there's no elements */
    if (obj->head->next == obj->tail) { return; }

    struct node* nodeSeeker = obj->head;
    struct node* delNode;

    for (int i = 0; i < index; i++){
        nodeSeeker = nodeSeeker->next;
        if (nodeSeeker->next == obj->tail) { return; }
    }

    delNode = nodeSeeker->next;
    nodeSeeker->next = delNode->next;

    free(delNode);
}


void myLinkedListFree(MyLinkedList* obj) {
    struct node* delNode = obj->head;
    struct node* nextNode = delNode->next;

    while(1) {
        free(delNode);
        delNode = nextNode;
        if (delNode == NULL) { break; }
        nextNode = delNode->next;
    }

    free(obj);
}


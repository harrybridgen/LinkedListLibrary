#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	void *data;
	struct Node *next;
	struct Node *prev;
} Node;

typedef struct LinkedList {
	struct Node *head;
	struct Node *tail;
} LinkedList;

Node *initNode(void);
Node *getHead(LinkedList *linkedlist);
LinkedList *initLinkedList(void);

void appendLinkedList(LinkedList *linkedlist, void *data);
void prependLinkedList(LinkedList *linkedlist, void *data);

Node *removeHead(LinkedList *linkedlist);
Node *removeTail(LinkedList *linkedlist);

void freeNode(Node *node);
void freeLinkedList(LinkedList *linkedlist);

void printList(LinkedList *linkedlist);

#endif
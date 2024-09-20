#include "LinkedList.h"

Node *initNode(void) {
	Node *node;
	if (!(node = (Node *)malloc(sizeof(Node)))) {
		printf("Failed to allocate memory for Node\n");
		return NULL;
	}
	printf("Allocated memory for Node\n");
	node->data = node->next = node->prev = NULL;
	return node;
}

void freeNode(Node *node) {
	free(node);
	printf("Free Node\n");
}

LinkedList *initLinkedList(void) {
	LinkedList *linkedlist;
	if (!(linkedlist = (LinkedList *)malloc(sizeof(LinkedList)))) {
		printf("Failed to memory for LinkedList\n");
		return NULL;
	}
	printf("Allocated memory for LinkedList\n");
	linkedlist->head = linkedlist->tail = NULL;
	return linkedlist;
}

Node *getHead(LinkedList *linkedlist) { return linkedlist->head; }

Node *getTail(LinkedList *linkedlist) { return linkedlist->tail; }

void appendLinkedList(LinkedList *linkedlist, void *data) {
	if (linkedlist == NULL) {
		printf("LinkedList is NULL");
	}

	Node *node;
	node = initNode();
	node->data = data;
	node->prev = linkedlist->tail;

	if (linkedlist->tail) {
		linkedlist->tail->next = node;
	}
	linkedlist->tail = node;
	if (!(linkedlist->head)) {
		linkedlist->head = node;
	}
}

Node *removeHead(LinkedList *linkedlist) {
	Node *node = getHead(linkedlist);
	linkedlist->head = node->next;
	node->next->prev = NULL;
	return node;
}

Node *removeTail(LinkedList *linkedlist) {}

void prependLinkedList(LinkedList *linkedlist, void *data) {
	if (linkedlist == NULL) {
		printf("LinkedList is NULL");
	}

	Node *node;
	node = initNode();
	node->data = data;
	node->next = linkedlist->head;

	if (linkedlist->head) {
		linkedlist->head->prev = node;
	}
	linkedlist->head = node;
	if (!(linkedlist->tail)) {
		linkedlist->tail = node;
	}
}

void printList(LinkedList *linkedlist) {
	Node *node;
	node = linkedlist->head;
	printf("head: %d\n", *((int *)linkedlist->head->data));
	printf("tail: %d\n", *((int *)linkedlist->tail->data));
	while (node != NULL) {
		printf("data: %d\n", *((int *)node->data));
		node = node->next;
	}
}

void freeLinkedList(LinkedList *linkedlist) {
	Node *node;
	while (linkedlist->head != NULL) {
		node = getHead(linkedlist);
		linkedlist->head = node->next;
		freeNode(node);
		node = NULL;
	}
	free(linkedlist);
	printf("Free LinkedList\n");
}
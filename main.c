#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"

int main() {
	LinkedList *linkedlist;
	linkedlist = initLinkedList();

	int x = 5;
	appendLinkedList(linkedlist, &x);

	int y = 10;
	appendLinkedList(linkedlist, &y);

	int a = 102;
	appendLinkedList(linkedlist, &a);

	int c = 12;
	appendLinkedList(linkedlist, &c);

	int j = 1212;
	prependLinkedList(linkedlist, &j);

	Node *node;
	node = removeHead(linkedlist);
	int data = *(int *)node->data;
	freeNode(node);
	appendLinkedList(linkedlist, &data);

	printList(linkedlist);

	freeLinkedList(linkedlist);
	return 0;
}
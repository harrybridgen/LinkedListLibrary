#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"

int main() {
	LinkedList *linkedlist;
	linkedlist = initLinkedList();

	int x = 5;
	appendNewNode(linkedlist, &x);

	int y = 10;
	appendNewNode(linkedlist, &y);

	int a = 102;
	appendNewNode(linkedlist, &a);

	int c = 12;
	appendNewNode(linkedlist, &c);

	int j = 1212;
	prependLinkedList(linkedlist, &j);

	Node *node;
	node = removeHead(linkedlist);
	int data = *(int *)node->data;
	freeNode(node);
	appendNewNode(linkedlist, &data);

	printList(linkedlist);

	freeLinkedList(linkedlist);
	return 0;
}
/*
 * SortedIntersectionLL.cpp
 *
 *  Created on: Jul 17, 2014
 *      Author: Arpit Bhayani
 */

#include <map>
#include <set>
#include <cstring>
#include <stack>
#include <vector>
#include <queue>
#include <list>
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

#define si(x) scanf("%d" , &x)
#define sl(x) scanf("%ld" , &x)
#define sll(x) scanf("%lld" , &x)
#define sc(x) scanf("%c" , &x)
#define ss(x) scanf("%s" , &x)

#define DEBUG 0
#define gc getchar
#define ll long long

void scanint(ll int &x) {
	register ll int c = gc();
	x = 0;
	for (; (c < 48 || c > 57); c = gc())
		;
	for (; c > 47 && c < 58; c = gc()) {
		x = (x << 1) + (x << 3) + c - 48;
	}
}

int readline(char * str) {

	int i = 0;
	char ch;
	while ((ch = getchar()) != '\n') {
		str[i++] = ch;
	}
	str[i] = '\0';
	return i;
}

#define ASIZE 10

struct node {
	int data;
	struct node * next;
};

struct node * newnode(int val) {
	struct node * t = (struct node *) malloc(sizeof(struct node));
	t->data = val;
	t->next = NULL;
	return t;
}

void addToHead(struct node ** head, int val) {
	struct node * n = newnode(val);
	n->next = (*head);
	*head = n;
}

void printList(struct node * head) {
	struct node * p = head;

	while (p) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

void sortedIntersection(struct node * h1, struct node * h2, struct node ** h3) {

	struct node * p = h1;
	struct node * q = h2;

	while (p != NULL && q != NULL) {
		if (p->data == q->data) {
			break;
		}

		if (p->data < q->data)
			p = p->next;
		else
			q = q->next;
	}

	if (p == NULL || q == NULL) {
		*h3 = NULL;
		return;
	}

	*h3 = newnode(p->data);
	p = p->next;
	q = q->next;

	struct node * r = *h3;

	while (p != NULL && q != NULL) {
		if (p->data == q->data) {

			r->next = newnode(p->data);
			p = p->next;
			q = q->next;
			r = r->next;

		} else if (p->data < q->data) {
			p = p->next;
		} else {
			q = q->next;
		}

	}

}

int main(int argc, char * argv[]) {

	struct node *l1 = NULL, *l2 = NULL, *l3 = NULL;

	l1 = newnode(6);
	addToHead(&l1, 5);
	addToHead(&l1, 4);
	addToHead(&l1, 3);
	addToHead(&l1, 2);
	addToHead(&l1, 1);

	l2 = newnode(12);
	addToHead(&l2, 10);
	addToHead(&l2, 8);
	addToHead(&l2, 6);
	addToHead(&l2, 4);
	addToHead(&l2, 2);

	printList(l1);
	printList(l2);

	sortedIntersection(l1, l2, &l3); 	// l3 -> l1 intersect l2

	printList(l3);

	return 0;
}

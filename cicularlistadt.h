#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct node {
	void* dp;
	struct node* next;
} NODE;

typedef struct list {
	NODE* head;
	int count;
} LIST;

LIST* createlist() {
	LIST* p;
	p = (LIST*)malloc(sizeof(LIST));
	if (!p)
		return NULL;
	p->head = NULL;
	p->count = 0;
	return p;
}

bool insertion(LIST* p, NODE* pred, void* din) {
	NODE* pnew;
	pnew = (NODE*)malloc(sizeof(NODE));
	if (!pnew)
		return false;
	pnew->dp = din;
	if (pred == NULL) {
		if (p->head == NULL) {
			pnew->next = pnew; // Points to itself to form a circular reference
			p->head = pnew;
		} else {
			pnew->next = p->head;
			NODE* temp = p->head;
			while (temp->next != p->head)
				temp = temp->next;
			temp->next = pnew;
			p->head = pnew;
		}
	} else {
		pnew->next = pred->next;
		pred->next = pnew;
	}
	p->count++;
	return true;
}

void* deletion(LIST* p, NODE* pred) {
	void* dout;
	NODE* delnode;
	if (!p->head)
		return NULL;
	else if (!pred) {
		delnode = p->head;
		if (p->head->next == p->head)
			p->head = NULL;
		else {
			NODE* temp = p->head;
			while (temp->next != p->head)
				temp = temp->next;
			temp->next = p->head->next;
			p->head = p->head->next;
		}
	} else {
		delnode = pred->next;
		pred->next = delnode->next;
	}
	dout = delnode->dp;
	free(delnode);
	p->count--;
	return dout;
}

NODE* searchlist(LIST* p, void* pkey, bool (cmp)(void, void*)) {
	NODE* temp;
	if (!p->head)
		return NULL;
	temp = p->head;
	do {
		if (cmp(temp->dp, pkey))
			return temp;
		temp = temp->next;
	} while (temp != p->head);
	return NULL;
}

void* retrievelist(LIST* p, void* pkey, bool (cmp)(void, void*)) {
	NODE* temp;
	temp = searchlist(p, pkey, cmp);
	if (temp)
		return (temp->dp);
	return NULL;
}

void displaylist(LIST* p, void (fp)(void)) {
	if (!p->head)
		return;
	NODE* temp;
	temp = p->head;
	do {
		fp(temp->dp);
		temp = temp->next;
	} while (temp != p->head);
}

bool listfull(LIST* p) {
	NODE* temp;
	temp = (NODE*)malloc(sizeof(NODE));
	if (temp) {
		free(temp);
		return false;
	}
	return true;
}

bool listempty(LIST* p) {
	if (p->head == NULL)
		return true;
	return false;
}

int listcount(LIST* p) {
	return (p->count);
}

bool destroylist(LIST* p) {
	if (!p)
		return false;
	NODE* t, * delnode;
	if (p->head) {
		t = p->head;
		do {
			delnode = t;
			t = t->next;
			free(delnode->dp);
			free(delnode);
		} while (t != p->head);
	}
	free(p);
	return true;
}

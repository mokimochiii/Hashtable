#include "ll.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

LL * list_create()
{
	LL *l = (LL *)malloc(sizeof(LL));
	if (l == NULL) {
		return NULL;
	}
	l->head = NULL;
	l->tail = NULL;
	return l;
}

bool list_add(LL *l, item *i)
{
	Node *n = (Node *)malloc(sizeof(Node));
	if (n == NULL) {
		return false;
	}
	n->data = *i;
	n->next = NULL;
	if (l->head == NULL) {
		l->head = n;
	} else {
		l->tail->next = n;
	}
	l->tail = n;
	return true;
}


item * list_find(LL *l, bool (*cmp)(item *,item *), item *i)
{
	Node *n = l->head;
        while (n != NULL) {
		if (cmp(&n->data, i)) {
			return &n->data;
		}
		n = n->next;
	}
	return NULL;
}

void list_destroy(LL **l){
	if(*l == NULL){
		return;
	}

	Node *n = (*l)->head;
	Node *temp;

	while(n != NULL){
		temp = n->next;
		free(n);
		n = temp;
	}
	
	free(*l);
	*l = NULL;
}

void list_remove(LL *l, bool (*cmp)(item *, item *), item *i){
	if(l == NULL || l->head == NULL){ //if list is NULL
		return;
	}

	Node *n = l->head;
	Node *prev = NULL;
	while(n != NULL){
		if(cmp(&n->data, i)){
			if(prev == NULL){ //if node is the head
				l->head = n->next;
				if (l->head == NULL) {
                    			l->tail = NULL;
                		}
			}else{
				prev->next = n->next;
				if (prev->next == NULL) {
                    			l->tail = prev;
				}	
			}
			free(n);
			return; //remove only first occurrence
		}
		prev = n;
		n = n->next;
	}
}


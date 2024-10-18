#include <stdio.h>
#include <string.h>
#include "ll.h"
#include "hash.h"
#include "badhash.h"
#include <stdbool.h>
#include <stdlib.h>

Hashtable * hash_create(void){
	Hashtable *table = (Hashtable *)malloc(sizeof(Hashtable));
	if(table == NULL){
		return NULL;
	}
	//table->buckets = list_create();
	table->table_size = sizeof(table->buckets)/sizeof(LL*);
	//printf("here: table size is %lu\n", table->table_size); for debugging
	for(size_t i = 0; i < table->table_size; i++){
		table->buckets[i] = list_create();
	}
	return table;

}

bool hash_put(Hashtable *table, char *key, int val){
	int *ptr = hash_get(table, key);//pointer for val of key
	size_t hashed_key = hash(key);
	size_t location = hashed_key%(table->table_size);

	if(ptr != NULL){//if there is a value for the key
		*ptr = val;
		return true;
	}

	item i;
	strcpy(i.key, key);
	i.id = val;
	list_add(table->buckets[location], &i);
	return true;
	
}

int * hash_get(Hashtable *table, char *key){
	size_t hashed_key = hash(key);
        //if(table->table_size == 0){
	//	printf("%lu\n", table->table_size);
	//}//for debugging
	size_t location = hashed_key%(table->table_size);
	LL *l = table->buckets[location];

	item search;
	strcpy(search.key, key);
	
	item *found = list_find(l, cmp, &search);
        if(found == NULL){
		return NULL;
	}
	return &found->id;
}

void hash_destroy(Hashtable **table){
	//printf("check2\n"); for debugging
	for(size_t i = 0; i < (*table)->table_size; i++){
		LL *temp = (*table)->buckets[i];
		list_destroy(&temp);
        }
	free(*table);
	table = NULL;
}

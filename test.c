#include <stdio.h>
#include <string.h>
#include "ll.h"
#include "badhash.h"
#include <stdbool.h>
#include <stdlib.h>

typedef struct Hashtable Hashtable;

struct Hashtable {
        LL *buckets[32];
        size_t table_size;
};

int main(){
	Hashtable *table = (Hashtable *)malloc(sizeof(Hashtable));
        //table->buckets = list_create();
        table->table_size = sizeof(table->buckets)/(sizeof(LL));
	printf("%lu\n", table->table_size);
        for(size_t i = 0; i < table->table_size; i++){
                table->buckets[i] = list_create();
        }
	printf("%lu\n", table->table_size);
	return 0;
}

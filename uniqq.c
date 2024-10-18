#include <stdio.h>
#include <stdbool.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include "hash.h"

#define MAX_LINE_LENGTH 1024

void print_unique(Hashtable *h){
	for (size_t i = 0; i < h->table_size; i++) {
        	LL *bucket = h->buckets[i];
        	Node *n = bucket->head;
        	while (n != NULL) {
			printf("%s\n", n->data.key);
            		n = n->next;
        	}
    	}
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        fprintf(stderr, "Usage: %s\n", argv[0]);
        return 1;
    }

    Hashtable *table = hash_create();
    char buffer[MAX_LINE_LENGTH];

    while (true) {
        
	ssize_t bytes_read = read(STDIN_FILENO, buffer, MAX_LINE_LENGTH);    

	if (bytes_read == -1) {
            if (errno == EINTR) {
                // Interrupted by a signal, continue reading
                continue;
            } else {
                // Error reading from stdin
                char *msg = "Error reading from stdin";
		perror(msg);
                hash_destroy(&table);
                return 1;
            }
	}else if(bytes_read == 0){
		break;
	}
	
	char *pos;

	if ((pos = strchr(buffer, '\n')) != NULL) {
            *pos = '\0'; // Replace newline character with null terminator
        }

        int *id = hash_get(table, buffer);
        if (id == NULL) {
            hash_put(table, buffer, 1);
        } else {
            (*id)++;
        }
    }

    print_unique(table);
    hash_destroy(&table);

    return 0;
}

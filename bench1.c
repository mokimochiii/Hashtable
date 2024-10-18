#include <stdio.h>
#include <string.h>
#include "hash.h"
#include "dictwords.h"


int main()
{
	LL *l = getwords();

	// some sanity checks.
	//
	item look;
	strcpy(look.key, "idempotent"); //initializes item
	item *ret = list_find(l, cmp, &look); //find this item in the list
	if (ret == NULL  || (*ret).id != 56613) {
		printf("something went wrong\n"); //if it cant find display err
		if(ret == NULL){
			printf("NULL\n");
		}else if((*ret).id != 56613){
			printf("56613\n");
		}else if(ret == NULL  && (*ret).id != 56613){
			printf("BOTH\n");
		}
		return 1;
	}


	list_destroy(&l);
	printf("SUCCESS!\n"); //found
	return 0;


}

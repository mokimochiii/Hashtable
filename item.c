#include "item.h"
#include <string.h>
#include <stdio.h>


// implementation of the cmp() function on items, for when items are ints
bool cmp(item *i1, item *i2)
{
	//return (*i1 == *i2);
	//printf("%s\n", i1->key);
	//printf("%s\n", i2->key);
	//printf("%d\n", strcmp(i1->key, i2->key));
	return strcmp(i1->key, i2->key) == 0;

}

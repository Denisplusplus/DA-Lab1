#include <stdio.h>
#include <string.h>
#include "StringMaker.h"


int main(void) {

	char* string = StringCreate();
	printf("%s\n", string);
	StringDestroy(&string);
	return 0;
}

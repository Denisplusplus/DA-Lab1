#include <stdio.h>
#include <string.h>
#include "StringMaker.h"

char* StringCreate(void) {
	char* string = (char*) calloc(sizeof(char), 65);
	scanf("%s", string);
	size_t string_lenght = strlen(string);
	if (string_lenght < 64) {
		for (size_t i = string_lenght; i <= 64; i++) {
			string[i] = '\0';	
		}
	}
	return string;
}


void StringDestroy(char** string) {
	free(*string);
	string = NULL;
}
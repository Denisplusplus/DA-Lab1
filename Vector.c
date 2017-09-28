#include <stdio.h>
#include <string.h>
#include "StringMaker.h"
#include "Vector.h"

TVector* VectorCreate(void) {
	TVector* vector = (TVector*) malloc(sizeof(TVector));
	vector->item_array = NULL;
	vector->size = 0;
	return vector;
}

void VectorEntry(TVector* vector, Key key, char *data) {
	vector->size++;
    vector->item_array = (TItem *) realloc(vector->item_array, vector->size * sizeof(TItem));
    vector->item_array[vector->size - 1].key = key;
    vector->item_array[vector->size - 1].data = data;
}


void VectorPrint(TVector* vector) {
    if ((vector->size == 0) || (!vector)) {
        printf("Vector is empty\n");
        return;
    }
    for (int i = 0; i < vector->size; i++) {
    		printf("%lf\n", vector->item_array[i].key);
        	printf("%s\n", vector->item_array[i].data);
    
    }
    printf("\n");
}

void VectorDestroy(TVector** vector) {
	int max_size = (*vector)->size - 1;
	for (int i = 0; i < max_size; i++) {
		if ((*vector)->item_array[i].data) {
			StringDestroy(&((*vector)->item_array[i].data));
		}
	}
	if ((*vector)->item_array) {
		free((*vector)->item_array);
		(*vector)->item_array = NULL;
	}
	if (*vector) {
		free (*vector);
		*vector = NULL;
	}

}

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

void VectorEntry(TVector* vector, Key key) {
	vector->size++;
    vector->item_array = (TItem *) realloc(vector->item_array, vector->size * sizeof(TItem));
    vector->item_array[vector->size - 1].key = key;
    vector->item_array[vector->size - 1].data = StringCreate();
   	
}


void VectorPrint(TVector* vector) {
    if (vector->size == 0) {
        printf("Vector is empty\n");
        return;
    }
    for (int i = 0; i < vector->size; i++) {
    		printf("%lf\n", vector->item_array[i].key);
        	printf("%s\n", vector->item_array[i].data);
    
    }
    printf("\n");
}

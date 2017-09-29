#include <stdio.h>
#include <string.h>
#include "StringMaker.h"
#include "Vector.h"

TVector* BucketSort(TVector* vector) {
	if (vector == NULL || vector->size < 2) {
		return vector;
	}
	double maxValue = vector->item_array[0].key; 
	double minValue = vector->item_array[0].key;
	for (int i = 1; i < vector->size; i++) {
		if (vector->item_array[i].key > maxValue) maxValue = vector->item_array[i].key;
		if (vector->item_array[i].key < minValue) minValue = vector->item_array[i].key;
	}
	int buckets_size = (int) (maxValue - minValue + 1);
	TVector*  bucket[buckets_size];
	for (int i = 0; i<buckets_size; i++) {
		bucket[i] = VectorCreate();
	}
   	for (int i = 0; i < vector->size; i++) {
 		VectorEntry(bucket[(int) (vector->item_array[i].key - minValue)], vector->item_array[i].key, vector->item_array[i].data);
    }
    TVector* vectorR = NULL;
   	vectorR = VectorCreate();
    for (int i = 0; i < buckets_size; i++) {
        if (bucket[i]->size > 0) {
            for (int j = 0; j < bucket[i]->size; j++) {
               VectorEntry(vectorR, bucket[i]->item_array[j].key, bucket[i]->item_array[j].data);
            }
        }
    }

    for (int i = 0; i < buckets_size; i++) {
    	VectorDestroy(&bucket[i]);
    }	
    if (*bucket) {
    	free(*bucket);
    	(*bucket) = NULL;
    }
    return vectorR;
}

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

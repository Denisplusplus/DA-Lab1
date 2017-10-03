#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "StringMaker.h"
#include "Vector.h"

void swap(TItem*r* vector1,  TItem** vector2)
{
	TItem* temp;
	temp = *vector1;
	*vector1 = *vector2;
	*vector2 = temp;
}

TVector* InsertionSort(TVector* vector)
{	
	if (!vector || vector->size < 2) {
		return vector;
	}
	for (int i = 1; i < vector->size; i++) {
		for (int j = i; j > 0 && vector->item_array[j - 1].key > vector->item_array[j].key; j--) {
			swap(&(vector->item_array[j - 1]), &(vector -> item_array[j]));
		}
	}
	return vector;
}


void BucketSort(TVector* vector) {
	if (vector->size < 2) {
		VectorPrint(vector);
		return;
	}
	
	double maxValue = vector->item_array[0].key; 
	double minValue = vector->item_array[0].key;
	
	for (int i = 1; i < vector->size; i++) {
		if (vector->item_array[i].key > maxValue) maxValue = vector->item_array[i].key;
		if (vector->item_array[i].key < minValue) minValue = vector->item_array[i].key;
	}

	size_t bucket_size = vector->size / 2 ;
	double length = (maxValue - minValue + 1) / bucket_size;

	TVector**  bucket;
	bucket = (TVector**) malloc(bucket_size * sizeof(TVector*));
	for (size_t i = 0; i < bucket_size; i++) {
		 bucket[i] = VectorCreate();
	}

	for (size_t i = 0; i < vector->size; i++) {
       	size_t index = (int) ((vector->item_array[i].key - minValue) / length);
        VectorEntry(bucket[index], vector->item_array[i].key, vector->item_array[i].data);
    }
   
    for (size_t i = 0; i < bucket_size; i++) {
    	InsertionSort(bucket[i]);
    	VectorPrint(bucket[i]);
    }
    for (int i = 0; i<bucket_size; i++) {
    	VectorDestroy(&bucket[i]);
    }
    free(bucket);
    bucket = NULL;

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
    for (int i = 0; i < vector->size; i++) {
    		printf("%lf\t", vector->item_array[i].key);
        	printf("%s\n", vector->item_array[i].data);
    }
}

void VectorDestroy(TVector** vector) {
	if (!(*vector)) {
		return;
	}
	int max_size = (*vector)->size;
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
		(*vector) = NULL;
	}

}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Vector.h"

void swap(TItem* vector1,  TItem* vector2)
{
	TItem temp;
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


	double maxValue = vector->item_array[0].key; 
	double minValue = vector->item_array[0].key;
	
	for (int i = 1; i < vector->size; i++) {
		if (vector->item_array[i].key > maxValue) maxValue = vector->item_array[i].key;
		if (vector->item_array[i].key < minValue) minValue = vector->item_array[i].key;
	}

	size_t bucket_size = vector->size / 2 ;
	double length = (maxValue - minValue + 1) / bucket_size;
	TVector bucket[bucket_size];
	for (size_t i = 0; i < bucket_size; i++) {
		 VectorCreate(&bucket[i], 1);
	}

	for (size_t i = 0; i < vector->size; i++) {
       	size_t index = (int) ((vector->item_array[i].key - minValue) / length);
        VectorEntry(&bucket[index], vector->item_array[i]);
    }

    for (size_t i = 0; i < bucket_size; i++) {
    	InsertionSort(&bucket[i]);
    	VectorPrint(&bucket[i]);
    }
    for (size_t i = 0; i < bucket_size;i++) {
    	VectorFree(&bucket[i]);
    }

}

TVector* VectorCreate(TVector* vector, int capacity) {
	vector->item_array = (TItem*)malloc(sizeof(TItem) * capacity);
    vector->size = 0;
	vector->capacity = capacity;
	return vector;
}

void VectorEntry(TVector* vector, TItem item) {
	if (vector->size == vector->capacity) {
		vector->capacity *= 2;
		vector->item_array = (TItem*)realloc(vector->item_array, sizeof(TItem) * vector->capacity);
	}
	vector->item_array[vector->size++] = item;
}


void VectorPrint(TVector* vector) {
    for (int i = 0; i < vector->size; i++) {
    		printf("%lf\t", vector->item_array[i].key);
        	printf("%s\n", vector->item_array[i].data);
    }
}


void VectorFree(TVector* vector)
{	
	if (vector->item_array) {
    	free(vector->item_array);
	}
}

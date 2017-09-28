#ifndef VECTOR_H
#define VECTOR_H

typedef double Key;


typedef struct item {
 	Key key;
    char *data;
} TItem;

typedef struct vector {
    TItem* item_array;
    size_t size;
} TVector;

TVector* VectorCreate();
void VectorEntry(TVector* vector, Key key, char* data);
void VectorPrint(TVector* vector);
TVector* VectorBucketSort(TVector* vector);
void VectorDestroy(TVector** vector);

#endif

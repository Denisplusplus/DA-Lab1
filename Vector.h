#ifndef VECTOR_H
#define VECTOR_H

typedef double Key;


typedef struct item {
 	 Key key;
    char data[65];
} TItem;

typedef struct vector {
    TItem* item_array;
    int size;
    int capacity;
} TVector;

void BucketSort(TVector* vector);
TVector* VectorCreate(TVector* vector, int capacity);
void VectorEntry(TVector* vector, TItem item);
void VectorPrint(TVector* vector);
void VectorFree(TVector* vector);


#endif

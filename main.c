#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StringMaker.h"
#include "Vector.h"


int main(void) {

	TVector* vector = NULL;
	vector = VectorCreate();
	char* string = NULL;
	double key;
	while (scanf("%lf", &key) != EOF) {
		string = StringCreate();
		VectorEntry(vector, key, string);
	}
	VectorPrint(BucketSort(vector));
	VectorDestroy(&vector);

	return 0;
}





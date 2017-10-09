#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Vector.h"


int main(void) {
	TVector vector;
	TItem item;
	VectorCreate(&vector, 1);
	while(scanf("%lf %s", &item.key, item.data) == 2) {
		VectorEntry(&vector, item);
	}
	if (vector.size >=2 ) {
		BucketSort(&vector);
	} else {
		VectorPrint(&vector);
	}
	VectorFree(&vector);
	return 0;	
}








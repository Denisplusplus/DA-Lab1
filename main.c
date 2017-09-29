#include <stdio.h>
#include <string.h>
#include "StringMaker.h"
#include "Vector.h"

void menu(void);



int main(void) {

	int choise;
	TVector* vector = NULL;
	vector = VectorCreate();
	TVector* vector_sorted = NULL;
	//vector_sorted = VectorCreate();
    do {
    	double key;
		menu();
		scanf("%d", &choise);
		switch(choise) {
			case 1 :
				scanf("%lf", &key);
				char* string = StringCreate();
				VectorEntry(vector, key, string);
				break;
			case 2 :
				VectorPrint(vector);
				break;
			case 3 :
				vector_sorted = BucketSort(vector);
				break;
			case 4 :
			   VectorPrint(vector);		
				break;		
			case 5 :
				StringDestroy(&string);
				VectorDestroy(&vector);
				VectorDestroy(&vector_sorted);
				
				break;
			case 0 :
				return 0;
		}	
	} while(1);	
	return 0;
}





void menu(void)
{
	printf("1)Insert key and data to vector\n");
	printf("2)Print vector\n");
	printf("3)Sort vector\n");
	printf("4)Print sorted vector\n");
	printf("5)Destroy vector\n");

}

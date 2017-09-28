#include <stdio.h>
#include <string.h>
#include "StringMaker.h"
#include "Vector.h"

void menu(void);



int main(void) {

	int choise;
	TVector* vector = NULL;
	vector = VectorCreate();

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
				VectorDestroy(&vector);
				StringDestroy(&string);
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
	printf("3)Destroy vector\n");

}

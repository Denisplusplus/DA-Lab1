da1: da1.o Vector.o 
	gcc -o da1 da1.o Vector.o 

da1.o: da1.c Vector.h 
	gcc -c -pedantic -Wall -std=c99 -Werror -Wno-sign-compare -lm da1.c 

vector.o: Vector.c Vector.h 
	gcc -c -pedantic -Wall -std=c99 -Werror -Wno-sign-compare -lm Vector.c 

clean:
	rm -rf *.o da1

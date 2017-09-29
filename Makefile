exec: main.o Vector.o StringMaker.o
	gcc -o exec main.o Vector.o StringMaker.o 

main.o: main.c Vector.h StringMaker.h 
	gcc -c -std=c99 -w main.c 

vector.o: Vector.c Vector.h StringMaker.h
	gcc -c -std=c99 -w Vector.c 

stringmaker.o: StringMaker.c StringMaker.h
	gcc -c -std=c99 -w StringMaker.c 

clean:
	rm -rf *.o exec	

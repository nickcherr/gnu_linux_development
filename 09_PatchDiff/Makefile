all: labyrinth labyrinth_patch1 labyrinth_patch2 labyrinth_patch3

labyrinth:
	gcc labyrinth.c -o labyrinth.o

labyrinth_patch1: labyrinth
	patch labyrinth.c 1.patch -o labyrinth_patch1.c
	gcc labyrinth_patch1.c -o labyrinth_patch1.o

labyrinth_patch2: labyrinth
	patch labyrinth_patch1.c 2.patch -o labyrinth_patch2.c
	gcc labyrinth_patch2.c -o labyrinth_patch2.o

labyrinth_patch3: labyrinth
	patch labyrinth_patch2.c 3.patch -o labyrinth_patch3.c
	gcc labyrinth_patch3.c -o labyrinth_patch3.o


run: all
	./labyrinth.o
	./labyrinth_patch1.o 5
	./labyrinth_patch2.o X, 5
	./labyrinth_patch3.o 42 X, 5

clean:
	rm -f *.o labyrinth_patch*.c

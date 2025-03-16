all: programa

programa: TreasureFinder.o Tablero.o Bomba.o Tierra.h
	gcc -o programa TreasureFinder.o Tablero.o Bomba.o Tierra.h -Wall

TreasureFinder.o: TreasureFinder.c 
	gcc -c TreasureFinder.c -Wall

Tablero.o: Tablero.c Tablero.h
	gcc -c Tablero.c Tablero.h -Wall

Bomba.o: Bomba.c Bomba.h
	gcc -c Bomba.c Bomba.h -Wall

clean:
	rm -f programa *.o *.gch
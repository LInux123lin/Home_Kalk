__start__: Home_zadanie.out
	./Home_zadanie.out
	
Home_zadanie.out: main.o calc.o
	gcc main.o calc.o
	
glowny.o: main.c calc.h
	gcc -c -Wall -pedantic main.c
	
modul.o: calc.h calc.c
	gcc -c -Wall -pedantic calc.c
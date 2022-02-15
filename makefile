p1_e1: p1_e1.o point.o
	gcc p1_e1.o point.o -o p1_e1 -Wall -pedantic

point.o: point.c point.h types.h
	gcc -c point.c

p1_e1.o: p1_e1.c point.h types.h
	gcc -c p1_e1.c


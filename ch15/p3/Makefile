qsort: qsort.o quicksort.o split.o
	gcc -o qsort qsort.o quicksort.o split.o

quicksort.o: quicksort.c quicksort.h split.h
	gcc -c quicksort.c

split.o: split.c split.h
	gcc -c split.c

a.out: client.o impl.o
	gcc client.o impl.o

impl.o: impl.c header.h	
	gcc -c impl.c

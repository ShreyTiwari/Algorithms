a.out: impl.o client.o 
		gcc impl.o client.o 

impl.o: impl.c header.h 
		gcc -c impl.c 

client.o: client.c header.h 
		gcc -c client.c
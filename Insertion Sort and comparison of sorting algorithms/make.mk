a.out: impl.o client.o 
		gcc impl.o client.o 

impl.o: header.h impl.c 
		gcc -c impl.c 

client.o: header.h client.c 
		gcc -c client.c
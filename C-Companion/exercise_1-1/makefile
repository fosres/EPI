# My First Makefile

all: main.o input.o output.o
	cc -o all main.o input.o output.o

main.o:	$(HEADERS) main.c 
	cc -c main.c -o main.o

input.o: $(HEADERS) input.c
	cc -c input.c -o input.o

output.o: $(HEADERS) output.c
	cc -c output.c -o output.o


clean:
	-rm -f *.o
	-rm -f all

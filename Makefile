#Corrina Lakin CS4280 P0

CC = g++
CFLAGS = -g -Wall -std=c++11
OBJS = main.o parser.o scanner.o statSem.o


statSem: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o statSem

main.o: main.cpp parser.h scanner.h token.h statSem.h
	$(CC) $(CFLAGS) -c main.cpp

scanner.o: scanner.cpp scanner.h token.h
	$(CC) $(CFLAGS) -c scanner.cpp

parser.o: parser.cpp parser.h statSem.h
	$(CC) $(CFLAGS) -c parser.cpp

statSem.o: statSem.cpp statSem.h
	$(CC) $(CFLAGS) -c statSem.cpp

clean:
	rm *.o statSem

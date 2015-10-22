CC=g++
CFLAGS=-std=c++11 -W -Wall
EXEC=files

files: pixel.o image.o main.o
	$(CC) pixel.o image.o main.o -o algoprog

main.o: main.cpp 
	$(CC) -o main.o -c main.cpp $(CFLAGS)

pixel.o: pixel.cpp
	$(CC) -o pixel.o -c pixel.cpp $(CFLAGS)

image.o: image.cpp
	$(CC) -o image.o -c image.cpp $(CFLAGS)

clean:
	rm -rf *.o

CC=/opt/gcc-4.9.3/bin/gcc
CFLAGS=-std=c++0x -W -Wall -ansi -pedantic
EXEC=files

all: $(EXEC)

files: pixel.o maillon.o image.o main.o
	$(CC) -o pixel.o maillon.o image.o main.o -o algoprog

main.o: main.cpp 
	$(CC) -o main.o -c main.cpp $(CFLAGS)

maillon.o: maillon.cpp
	$(CC) -o maillon.o -c maillon.cpp $(CFLAGS)

image.o: image.cpp
	$(CC) -o image.o -c image.cpp $(CFLAGS)

pixel.o: Pixel.cpp
	$(CC) -o pixel.o -c Pixel.cpp $(CFLAGS)


clean:
	rm -rf *.o
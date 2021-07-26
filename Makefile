CC = g++
CFLAGS = -O2

all: main

main: main.cpp
	$(CC) $(CFLAGS) main.cpp -o main

run: main
	./main

clean:
	rm *.o main
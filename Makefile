CC = g++
CFLAGS = -O2 -I../include -c
LD = ld
LDFLAGS = -I../include

OBJS = linear.o matrix.o matrix_row.o funcs.o main.o

all: main

%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@

main: $(OBJS)
	$(CC) $(OBJS) -o main

run: main
	./main

clean:
	rm *.o main
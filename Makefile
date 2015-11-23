CFLAGS = -std=c99 -Wall -lm

all: main.c
	gcc -o robot main.c $(CFLAGS)

clean:
	rm -fr *.o robot

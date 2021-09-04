prog=deq
CFLAGS = -std=c99 -Wall -I. -D_GNU_SOURCE

try: main.o libdeq.so
	gcc -o $@ $< -L. -ldeq -Wl,-rpath=. -I.

main: main.c deq.c
	gcc -o main main.c deq.c Tests.c $(CFLAGS)

debug: CFLAGS +=-g
debug: main

clean:
	rm -rf main main.o
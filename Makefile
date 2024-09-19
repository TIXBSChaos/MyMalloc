C = gcc
CFLAGS = -g -std=c99 -Wall -fsanitize=address,undefined

cfoo: callingFreeOnOutsideObject.o mymalloc.o
        $(CC) $(CFLAGS) $^ -o $@

cfwnc: callingFreeWithNotChunk.o mymalloc.o
        $(CC) $(CFLAGS) $^ -o $@

cftt: callingFreeTwoTimes.o mymalloc.o
        $(CC) $(CFLAGS) $^ -o $@

mallocTest: mallocTest.o mymalloc.o
        $(CC) $(CFLAGS) $^ -o $@

freeTest: freeTest.o mymalloc.o
        $(CC) $(CFLAGS) $^ -o $@

coalesceTest: coalesceTest.o mymalloc.o
        $(CC) $(CFLAGS) $^ -o $@

memgrind: memgrind.o mymalloc.o
        $(CC) $(CFLAGS) $^ -o $@

memtest: memtest.o mymalloc.o
        $(CC) $(CFLAGS) $^ -o $@

%.o: %.c
        $(CC) $(CFLAGS) -c $< -o $@
memgrind.o memtest.o mymalloc.o: mymalloc.h

test: memtest
        ./memtest

clean:
        rm -f *.o memtest memgrind

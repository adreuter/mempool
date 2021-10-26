out: test.o mempool.o
	gcc -o out test.o mempool.o

test.o: test/test.c
	gcc -c test/test.c

mempool.o: src/mempool.c
	gcc -c src/mempool.c
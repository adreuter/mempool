out: test.o mempool.o
	gcc -o bin/out bin/test.o bin/mempool.o

test.o: test/test.c
	gcc -c test/test.c -o bin/test.o

mempool.o: src/mempool.c
	gcc -c src/mempool.c -o bin/mempool.o
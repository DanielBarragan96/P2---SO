all:
	gcc -o init init.c
	gcc -o getty getty.c
	gcc -o sh sh.c -pthread


clean:

	-f init
	-f getty
	-f sh

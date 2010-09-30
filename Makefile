brain: loader.o mem.o vm.o
	gcc -o brain loader.o mem.o vm.o

%.o: %.c
	gcc -c -Wall $^ -I .

run: main
	./main
main: queue.o main.o
	gcc queue.o main.o -o main
queue.o: queue.c
	gcc -c queue.c -o queue.o
main.o: main.c
	gcc -c main.c -o main.o

clean:
	rm -f main.o queue.o main

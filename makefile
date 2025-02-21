main: main.c 
	gcc -g -o main main.c pieces.c
	clear

run: main
	clear
	./main

memcheck: main
	valgrind --track-origins=yes  --leak-check=full --show-leak-kinds=all -s ./main
clean:
	rm -f pieces pieces.h.gch main
	clear

compile: main.c
	gcc -g -o  main main.c
	clear

run: main
	clear
	./main

clean:
	rm main
	clear
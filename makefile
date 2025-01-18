
compile: main.c
	gcc -o main main.c
	clear

run: main
	clear
	./main

clean:
	rm main
	clear
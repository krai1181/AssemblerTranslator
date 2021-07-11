play: functions.o main.o
	gcc -ansi -Wall -g main.o functions.o -o play
functions.o: functions.c
	gcc -c -ansi -Wall functions.c -o functions.o
main.o: main.c
	gcc -c -ansi -Wall main.c -o main.o
all: Activity

cli.o: cli.h cli.c
	gcc -c cli.c -Wall -Wextra

plist.o: plist.h plist.c
	gcc -c plist.c -Wall -Wextra

song.o: song.h song.c
	gcc -c song.c -Wall -Wextra

main.o: cli.h node.h plist.h playlist.h song.h main.c 
	gcc -c main.c

Activity: cli.o plist.o song.o main.o
	gcc cli.o plist.o song.o main.o -o program.exe
clean:
	rm -f *.o program.exe

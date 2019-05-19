#epolltest: main.o util.o lt.o
#	gcc -o epolltest main.o util.o lt.o
#main.o: main.c util.h lt.h
#	gcc -c main.c
#et.o: et.c lt.h 
#	gcc -c lt.c
#util.o:util.c util.h
#	gcc -c util.c
#clean:
#	rm util.o lt.o main.o
epolltest: main.o util.o et.o
	gcc -o epolltest main.o util.o et.o
main.o: main.c util.h et.h
	gcc -c main.c
et.o: et.c et.h 
	gcc -c et.c
util.o:util.c util.h
	gcc -c util.c
clean:
	rm util.o et.o main.o

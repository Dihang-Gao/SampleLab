CC=gcc
CFLAGS=-g -Wall

all:filestats

filestats: main.o line.o util.o errorcode.o
	$(CC) main.o line.o util.o errorcode.o -o filestats

main.o: Main.c ErrorCode.h Line.h CountType.h Settings.h Util.h
	$(CC) $(CFLAGS) -c Main.c -o main.o

line.o: Line.c Line.h ErrorCode.h Util.h Settings.h
	$(CC) $(CFLAGS) -c Line.c -o line.o

util.o: Util.c Util.h ErrorCode.h Settings.h
	$(CC) $(CFLAGS) -c Util.c -o util.o

errorcode.o: ErrorCode.c ErrorCode.h Util.h Settings.h
	$(CC) $(CFLAGS) -c ErrorCode.c -o errorcode.o

clean:
	rm -f *.o *~ filestats

debug: all
	cgdb ./filestats

ddd: all
	ddd ./filestats

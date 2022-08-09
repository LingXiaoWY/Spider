.PHPONY:spider
INCLUDE_PATH=../include/
LIBRARY_PATH=../library/
INSTALL_PATH=/usr/bin/
CC=gcc
CFLAGS=-I$(INCLUDE_PATH) -g -c -Wall
CPPFLAGS=
LDFLAGS=-lssl -lcrypto
TARGET=app
OLD_FILE=$(wildcard *.c)
NEW_FILE=$(patsubst %.c,%.o,$(OLD_FILE))
MV=mv *.o ../bin

$(TARGET):$(NEW_FILE)
	$(CC) $^ $(LDFLAGS) -o $@
	$(MV)

%.o:%.c
	$(CC) $(CFLAGS) $<

clean:
	rm -rf ../bin/*.o $(TARGET) ../result/*.html


CC = clang
CFLAGS = -Wall -Wextra -O2
TARGET = gage
PREFIX ?= /usr/local

all: $(TARGET)

$(TARGET): main.c lexer.c lexer.h
	$(CC) $(CFLAGS) main.c -o $(TARGET)

install: $(TARGET)
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	cp $(TARGET) $(DESTDIR)$(PREFIX)/bin/

clean:
	rm -f $(TARGET)

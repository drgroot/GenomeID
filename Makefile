CC=gcc
CFLAGS=-c -Wall

SOURCES:= $(shell find src/ -name '*.c')
HEADERS:= $(shell find src/ -name '*.h')
OBJECTS=$(SOURCES:.c=.o)
LIBRARY=lib/libgenomeid.a

all: $(LIBRARY) test

notest: $(SOURCES) $(LIBRARY) 

test: $(LIBRARY) tests/test.c
	gcc tests/test.c -o test -I src/ -L lib/ -l genomeid

$(LIBRARY): $(OBJECTS)
	mkdir -p lib
	ar rcs $(LIBRARY) $(OBJECTS)

.o: $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f src/*.o
	rm -f lib/*.a

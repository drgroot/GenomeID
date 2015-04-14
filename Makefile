CC=gcc
CFLAGS=-c -Wall

SOURCES=src/genomeid.c
OBJECTS=$(SOURCES:.c=.o)
LIBRARY=lib/libgenomeid.a

all: $(SOURCES) $(LIBRARY) test

notest: $(SOURCES) $(LIBRARY)

test: $(LIBRARY)
	gcc tests/test.c -o test -I src/ -L lib/ -l genomeid

$(LIBRARY): $(OBJECTS)
	mkdir -p lib
	ar rcs $(LIBRARY) $(OBJECTS)

.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f src/*.o
	rm -f lib/*.a

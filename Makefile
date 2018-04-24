CC=gcc
CFLAGS=-I. -O2
DEPS=linalg.h
OBJ=main.o ler.o
TARGET=bib
LIBS=-lm -L. -llinalg

%.o: %.c $(DEPS)
	$(CC) -c -fpic -o $@ $< $(CFLAGS)

$(TARGET): $(OBJ)
	$(CC) -Wl,-rpath=. -o $@ $^ $(CFLAGS) $(LIBS)

lib: $(OBJ)
	$(CC) -shared -o liblinalg.so $^ $(CFLAGS)
	
clean:
	rm $(OBJ)

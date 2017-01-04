CC=gcc
CFLAGS=-I.
OBJ = linklist.o

.PHONY: clean

%.o: %.c 
	$(CC) -c -o $@ $< $(CFLAGS)
	$(CC) -o $(@:.o=) $^ $(CFLAGS)

all: $(OBJ)

clean:
	rm -f $(OBJ) $(OBJ:.o=)
CC = g++
CFLAGS = -g -w -Wall

OBJ = main.o

main: $(OBJ)
	$(CC) $(CFLAGS) -o main $(OBJ)
clean:
	rm -f *.o main
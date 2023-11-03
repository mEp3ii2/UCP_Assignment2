CC = gcc
CFLAGS = -Wall -ansi -pedantic -g
OBJ = main.o box.o printer.o setup.o validator.o playerStruct.o mapStruct.o carStruct.o carMovement.o movement.o terminal.o linkedList.o carCollide.o 
EXEC = traffic

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o : main.c setup.h validator.h
	$(CC) -c main.c $(CFLAGS)

printer.o : printer.c printer.h mapStruct.h carCollide.h
	$(CC) -c printer.c $(CFLAGS)

box.o : box.c box.h mapStruct.h carStruct.h playerStruct.h
	$(CC) -c box.c $(CFLAGS)

setup.o : setup.c setup.h box.h printer.h  mapStruct.h carStruct.h playerStruct.h movement.h 
	$(CC) -c setup.c $(CFLAGS)

validator.o: validator.c
	$(CC) -c validator.c $(CFLAGS)

playerStruct.o: playerStruct.c playerStruct.h
	$(CC) -c playerStruct.c $(CFLAGS)

mapStruct.o: mapStruct.c 
	$(CC) -c mapStruct.c $(CFLAGS)

carStruct.o: carStruct.c carStruct.h
	$(CC) -c carStruct.c $(CFLAGS)

carMovement.o: carMovement.c carMovement.h carStruct.h mapStruct.h
	$(CC) -c carMovement.c $(CFLAGS)

movement.o: movement.c movement.h terminal.h carStruct.h playerStruct.h mapStruct.h carMovement.h printer.h linkedList.h carCollide.h
	$(CC) -c movement.c $(CFLAGS)

terminal.o: terminal.c terminal.h
	$(CC) -c terminal.c $(CFLAGS)

linkedList.o: linkedList.c linkedList.h
	$(CC) -c linkedList.c $(CFLAGS)
carCollide.o: carCollide.c carCollide.h
	$(CC) -c carCollide.c $(CFLAGS)

clean:
	rm -f $(EXEC) $(OBJ)
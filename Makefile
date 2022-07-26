CC = gcc
TARGET = add-nbo
OBJS = add-nbo.o

all : $(TARGET)

$TARGET : $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

add-nbo.o : add-nbo.c
	$(CC) -c add-nbo.c

clean : 
	rm $(TARGET) $(OBJS)

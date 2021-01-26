CC=gcc
SFLAGS=-Wall
OBJETS=vigenere.o
EXECUTABLE=vigenere


all : $(EXECUTABLE)

$(EXECUTABLE) : $(OBJETS)
	$(CC) $(SFLAGS) -o $@ $(OBJETS)

$(OBJETS) : vigenere.c
	$(CC) $(SFLAGS) -c $<

clean :
	rm -f $(OBJETS) $(EXECUTABLE)

run : all
	./$(EXECUTABLE)

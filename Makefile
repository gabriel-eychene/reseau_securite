CC=gcc
SFLAGS=-Wall
OBJETS=Babbage.o
EXECUTABLE=babbage


all : $(EXECUTABLE)

$(EXECUTABLE) : $(OBJETS)
	$(CC) $(SFLAGS) -o $@ $(OBJETS)

$(OBJETS) : Babbage.c
	$(CC) $(SFLAGS) -c $<

clean :
	rm -f $(OBJETS) $(EXECUTABLE)

run : all
	./$(EXECUTABLE)

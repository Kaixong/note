#
# makefile for testglove, a simple console app to demonstrate reading the
# glove
#
# Copyright (C) 2000, 5DT <Fifth Dimension Technologies>
#

CPP = g++
#CFLAGS = -Wall
CFLAGS = -w
BIN = testglove
LIBS = -lfglove
#CFG_INC = -I../include
OBJFILES = testglove.o

default: $(OBJFILES)
	$(CPP) -o $(BIN) $(OBJFILES) $(LIBS)

clean:
	rm -f $(BIN) $(OBJFILES) *~ core #*

%.o: %.cpp
	$(CPP) $(CFLAGS) $(CFG_INC) -c $< -o $@


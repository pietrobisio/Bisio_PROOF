CC = g++
LD = $(CC)
CFLAGS = -c -Wall -Os
IFLAGS =  -I./ -I../
ROOTINC := $(shell root-config --cflags)
ROOTLIB := $(shell root-config --glibs)
LIBS = -lRooFit -lRooFitCore -lMinuit -lMinuit2 -lProof 
LFLAGS = -L../


SRC = $(wildcard *.cc)

TARGET = ana

OBJECTS = $(patsubst %.cc, %.o, $(wildcard *.cc))

all:   dict $(TARGET)

dict: anaSelector.h
	@echo "Generating dictionary $@..."
	@rootcint -v -f anaSelector_Dict.cc -c -p $(IFLAGS) anaSelector.h	anaSelector_LinkDef.h

$(TARGET): $(OBJECTS)
	$(LD) -shared -fPIC -o libanaSelector.so $(LFLAGS) $(ROOTLIB) $^  
	$(LD) -o $@ $^ $(LFLAGS) $(ROOTLIB) $(LIBS)

%.o: %.cc
	$(CC) -fPIC -g $(CFLAGS) $(IFLAGS) $(ROOTINC) $^ -o $@

clean:
	rm $(TARGET) $(OBJECTS)
	rm libanaSelector.so

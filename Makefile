#
# Makefile
#

TARGET = ims
DOC    = zprava.pdf

ZIP_FILE = 11_xsolic00_xsechr00.zip

CXX      = g++
CXXFLAGS = -std=c++11 -O2
LIBS     = -lm #-lsimlib

# DEBUG
CXXFLAGS += -D DEBUG -Wall -Wextra -g

OBJS = ims.o


.PHONY: all clean pack

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LIBS)

clean:
	$(RM) $(TARGET) $(ZIP_FILE) *.o

pack:
	zip $(ZIP_FILE) $(DOC) Makefile *.cc

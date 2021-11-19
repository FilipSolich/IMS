#
# Makefile
#

TARGET = ims
DOC    = zprava.pdf

PACK       = 11_xsolic00_xsechr00.zip
PACK_FILES = $(DOC) Makefile *.cc

CXX      = g++
CXXFLAGS = -std=c++11 -O2
LIBS     = -lm -lsimlib

# DEBUG
CXXFLAGS += -D DEBUG -Wall -Wextra -g

OBJS = ims.o


.PHONY: all clean pack

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LIBS)

clean:
	$(RM) $(TARGET) $(PACK) *.o

pack:
	zip $(PACK) $(PACK_FILES)

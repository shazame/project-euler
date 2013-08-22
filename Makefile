CFLAGS=-Wall -Wextra
CXXFLAGS=-Wall -Wextra
LDFLAGS=

EXT=cpp

SRCDIR=.
SRC=$(wildcard $(SRCDIR)/*.$(EXT))
BIN=$(SRC:.$(EXT)=)

.PHONY: all clean

all: $(BIN)

%.o: %.$(EXT)

clean:
	@ rm -f $(BIN) *~

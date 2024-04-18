CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin

OBJS = $(OBJ)/vertex.o $(OBJ)/edge.o $(OBJ)/main.o
HDRS = $(INC)/vertex.hpp $(OBJ)/edge.hpp 
CFLAGS = -g -Wall -c -I$(INC)

EXE = $(BIN)/code.out

all: $(EXE)

clean:
	rm -f $(EXE) $(OBJS) gmon.out

$(EXE): $(OBJS) | $(BIN)
	$(CC) $(OBJS) -o $(EXE) $(LIBS)

$(BIN):
	mkdir -p $(BIN)

$(OBJ)/%.o: $(SRC)/%.cpp $(HDRS) | $(OBJ)
	$(CC) $(CFLAGS) $< -o $@

$(OBJ):
	mkdir -p $(OBJ)

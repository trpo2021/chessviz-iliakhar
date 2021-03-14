CFLAGS = -Wall -Werror
CC = gcc

CHESSVIZ_BIN = bin

CHESSVIZ_OBJ = obj/scr/chessviz
CHESSVIZ_SCR = scr/chessviz

LIBCHESSVIZ_OBJ = obj/scr/libchessviz
LIBCHESSVIZ_SCR = scr/libchessviz

all:$(CHESSVIZ_BIN)/chessviz
	./$< scr/chessviz/moves.txt

$(CHESSVIZ_BIN)/chessviz:$(CHESSVIZ_OBJ)/chess.o $(LIBCHESSVIZ_OBJ)/libchessviz.a
	$(CC) $(CFLAGS) $^ -o $@

$(CHESSVIZ_OBJ)/chess.o : $(CHESSVIZ_SCR)/chess.c
	$(CC) -c $(CFLAGS) $< -o $@

$(LIBCHESSVIZ_OBJ)/%.o : $(LIBCHESSVIZ_SCR)/%.c
	$(CC) -c $(CFLAGS) $< -o $@


$(LIBCHESSVIZ_OBJ)/libchessviz.a : $(patsubst $(LIBCHESSVIZ_SCR)/%c, $(LIBCHESSVIZ_OBJ)/%o, $(wildcard $(LIBCHESSVIZ_SCR)/*c))
	ar rcs $@ $^

clean:
	rm -rf $(CHESSVIZ_OBJ)/*.o
	rm -rf $(LIBCHESSVIZ_OBJ)/*.o
	rm -rf $(LIBCHESSVIZ_OBJ)/*.a
	rm -rf $(CHESSVIZ_BIN)/chessviz

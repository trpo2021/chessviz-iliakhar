CFLAGS = -I scr -Wall -Werror
CFLAGS_TEST = -I thirdparty -Wall -Werror
CPPFLAGS = -MMD
CC = gcc

CHESSVIZ_BIN = bin

TEST = test
TEST_HEADER = thirdparty
TEST_OBJ = obj/test

CHESSVIZ_OBJ = obj/scr/chessviz
CHESSVIZ_SCR = scr/chessviz

LIBCHESSVIZ_OBJ = obj/scr/libchessviz
LIBCHESSVIZ_SCR = scr/libchessviz

.PHONY: all
all:$(CHESSVIZ_BIN)/chessviz
	./$< scr/chessviz/moves.txt

$(CHESSVIZ_BIN)/chessviz:$(CHESSVIZ_OBJ)/chess.o $(LIBCHESSVIZ_OBJ)/libchessviz.a
	$(CC) $(CFLAGS) $^ -o $@

$(CHESSVIZ_OBJ)/chess.o : $(CHESSVIZ_SCR)/chess.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

$(LIBCHESSVIZ_OBJ)/%.o : $(LIBCHESSVIZ_SCR)/%.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@


$(LIBCHESSVIZ_OBJ)/libchessviz.a : $(patsubst $(LIBCHESSVIZ_SCR)/%.c, $(LIBCHESSVIZ_OBJ)/%.o, $(wildcard $(LIBCHESSVIZ_SCR)/*.c))
	ar rcs $@ $^
	
.PHONY: format
format:
	#echo $(wildcard $(LIBCHESSVIZ_SCR)/*.c)
	clang-format -style=file -i $(wildcard $(LIBCHESSVIZ_SCR)/*.c) $(wildcard $(CHESSVIZ_SCR)/*.c) $(wildcard $(TEST)/*.c)
#####################################____TEST___#####################################
.PHONY: test
test:$(TEST_OBJ)/main.o
	$(CC) $(CFLAGS_TEST) $^ -o $(CHESSVIZ_BIN)/chessviz_test

(TEST_OBJ)/main.o : $(TEST)/main.c
	$(CC) -c $(CFLAGS_TEST) $(CPPFLAGS) $< -o $@

$(TEST_OBJ)/%.o : $(TEST)/%.c
	$(CC) -c $(CFLAGS_TEST) $(CPPFLAGS) $< -o $@
#####################################################################################
.PHONY: clean
clean:
	rm -rf $(CHESSVIZ_OBJ)/*.o
	rm -rf $(CHESSVIZ_OBJ)/*.d
	rm -rf $(LIBCHESSVIZ_OBJ)/*.o
	rm -rf $(LIBCHESSVIZ_OBJ)/*.d
	rm -rf $(TEST_OBJ)/*.o
	rm -rf $(TEST_OBJ)/*.d
	rm -rf $(LIBCHESSVIZ_OBJ)/*.a
	rm -rf $(CHESSVIZ_BIN)/chessviz
-include $(patsubst $(LIBCHESSVIZ_SCR)/%.c, $(LIBCHESSVIZ_OBJ)/%.d, $(wildcard $(LIBCHESSVIZ_SCR)/*.c))
-include $(patsubst $(TEST)/%.c, $(TEST_OBJ)/%.d, $(wildcard $(TEST)/*.c))

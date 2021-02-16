cmpl: chess.c
	gcc -Wall -Werror -c chess.c
	gcc chess.c -o chess

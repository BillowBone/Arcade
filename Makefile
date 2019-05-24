##
## EPITECH PROJECT, 2019
## OOP - Arcade
## File description:
## Makefile
##

GPP		= g++

RM		= rm -rf

CO_CFLAGS	= -W -Wall -Wextra -pedantic

CO_NAME		= arcade

CO_SRCS		= core/src/main.cpp	\
		core/src/Core.cpp	\
		core/src/Parser.cpp	\
		core/src/Errors.cpp	\

all: graphicals games core

core:
	$(GPP) -o $(CO_NAME) $(CO_SRCS) -I./core/include/ -I./lib/include/ -I./lib/ncurses/include/ -I./games/include/ $(CO_CFLAGS) -ldl

games:
	make -C ./games/Nibbler/
	make -C ./games/Pacman/

graphicals:
#	make -C ./lib/sfml/
	make -C ./lib/ncurses/
	make -C ./lib/sdl/

clean:
#	make clean -C ./lib/sfml/
	make clean -C ./lib/ncurses/
	make clean -C ./games/Nibbler/
	make clean -C ./games/Pacman/
	make clean -C ./lib/sdl/

fclean: clean
	$(RM) $(CO_NAME)
#	make fclean -C ./lib/sfml/
	make fclean -C ./lib/ncurses/
	make fclean -C ./games/Nibbler/
	make fclean -C ./games/Pacman/
	make fclean -C ./lib/sdl/

re: fclean all

.PHONY: all clean fclean re core games

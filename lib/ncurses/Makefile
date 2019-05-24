##
## EPITECH PROJECT, 2019
## OOP - Arcade
## File description:
## Makefile
##

GPP	= g++

RM	= rm -rf

CFLAGS	= -W -Wall -Wextra -pedantic

NAME	= lib_arcade_ncurses.so

SRCS	= 	./src/NCursesLib.cpp	\
			../src/AGraphic.cpp	\

all: $(NAME)

$(NAME):
	$(GPP) -c -fPIC $(SRCS) -lncurses -I./include -I../include/ -I../../include/
	$(GPP) NCursesLib.o AGraphic.o -shared -o ../$(NAME) -lncurses

clean:
	$(RM) *.o

fclean: clean
	$(RM) ../$(NAME)

re: fclean all

.PHONY: all clean fclean re

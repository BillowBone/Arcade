##
## EPITECH PROJECT, 2019
## OOP - Arcade
## File description:
## Makefile Nibbler
##

GPP	= g++

RM	= rm -rf

CFLAGS	= -W -Wall -Wextra -pedantic

NAME	= lib_arcade_pacman.so

SRCS	= 	./src/Pacman.cpp	\
			../src/AGame.cpp	\
			../../core/src/Errors.cpp	\

all: $(NAME)

$(NAME):
	$(GPP) -c -fPIC $(SRCS) -I./include -I../include/ -I../../core/include/
	$(GPP) Pacman.o AGame.o Errors.o -shared -o ../$(NAME)

clean:
	$(RM) *.o

fclean: clean
	$(RM) ../$(NAME)

re: fclean all

.PHONY: all clean fclean re
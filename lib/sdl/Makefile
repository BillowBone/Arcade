##
## EPITECH PROJECT, 2019
## OOP - Arcade
## File description:
## Makefile
##

GPP	= g++

RM	= rm -rf

CFLAGS	= -W -Wall -Wextra -pedantic

NAME	= lib_arcade_sdl.so

SRCS	= 	./src/SDLLib.cpp	\
		../src/AGraphic.cpp	\
		../../core/src/Errors.cpp	\

all: $(NAME)

$(NAME):
	$(GPP) -c -fPIC $(SRCS) -lSDL2 -I./include -I../include/ -I../../include/ -I../../core/include/
	$(GPP) SDLLib.o AGraphic.o Errors.o -shared -o ../$(NAME) -lSDL2

clean:
	$(RM) *.o

fclean: clean
	$(RM) ../$(NAME)

re: fclean all

.PHONY: all clean fclean re

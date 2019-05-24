##
## EPITECH PROJECT, 2019
## OOP - Arcade
## File description:
## Makefile
##

GPP	= g++

RM	= rm -rf

CFLAGS	= -W -Wall -Wextra -pedantic

NAME	= lib_arcade_sfml.so

SRCS	= 	./src/SFMLLib.cpp	\
		../src/AGraphic.cpp	\
		../../core/src/Errors.cpp	\

all: $(NAME)

$(NAME):
	$(GPP) -c -fPIC $(SRCS) -lsfml-graphics -I./include -I../include/ -I../../include/ -I../../core/include/
	$(GPP) SFMLLib.o AGraphic.o Errors.o -shared -o ../$(NAME) -lsfml-graphics

clean:
	$(RM) *.o

fclean: clean
	$(RM) ../$(NAME)

re: fclean all

.PHONY: all clean fclean re

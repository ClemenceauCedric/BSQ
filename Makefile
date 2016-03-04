##
## Makefile for BSQ in /home/Speedy/Work/CPE_2015_BSQ
##
## Made by Clemenceau Cédric
## Login   <Speedy@epitech.net>
##
## Started on  Tue Dec  8 13:20:01 2015 Clemenceau Cédric
## Last update Mon Dec 21 22:21:33 2015 Clémenceau Cedric
##

CC	=	gcc

RM	=	rm -f

CFLAGS	=	-I./include
CFLAGS	+=	-Wall -W -Wextra -ansi -pedantic

SRC	=	src/main.c \
		src/my_realloc.c \
		src/my_strcat.c \
		src/my_strcpy.c \
		src/fct_bsq.c \
		src/other.c \
		src/draw_x.c

OBJ	=	$(SRC:.c=.o)

NAME	=	bsq

$(NAME)	:	$(OBJ)
		$(CC) $(OBJ) -o $(NAME)

all	:	$(NAME)

clean	:
		$(RM) $(OBJ)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re

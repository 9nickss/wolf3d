##
## EPITECH PROJECT, 2025
## wolf3d makefile
## File description:
## makefile
##

NAME		=		wolf3d

SRCS		=		$(wildcard src/**/*.c)

OBJS		=		$(SRCS:.c=.o)

LIB			=		-I./include

LIB_CRI		=		--coverage -lcriterion

LIB_CSFML	=		-lcsfml-window -lcsfml-graphics \
					-lcsfml-system -lcsfml-audio

VAL			=		--leak-check=full --track-origins=yes \
					--show-leak-kinds=all --track-fds=yes \
					--log-file=valgrind_error.txt -s

OPTI		=		-o3

CFLAGS		+=		-Wall -Wextra -Wshadow -I./include

$(NAME)		:		$(OBJS)
					gcc -o $(NAME) $(OBJS) $(LIB) $(LIB_CSFML) -lm

.PHONY		:		all clean fclean re unit_tests tests_run val val_run run \
					opti opti_run

all			:
					$(MAKE) $(NAME)

clean		:
					rm -f $(OBJS)

fclean		:		clean
					rm -f *.gcda *.gcno *~ $(NAME)

re			:		fclean all

unit_tests	:		fclean all
					gcc -o unit_tests $(SRCS) tests/*.c \
					$(LIB) $(LIB_CSFML) $(LIB_CRI)

tests_run	:		unit_tests
					./unit_tests

val			:		re
					gcc -o $(NAME) $(SRCS) $(LIB) $(LIB_CSFML) -lm -g3

val_run			:	val
					@valgrind $(VAL) ./$(NAME)

run			:		all
					./$(NAME)

opti			:
					gcc $(OPTI) -o $(NAME) $(SRCS) $(LIB) $(LIB_CSFML) -lm

opti_run		:	opti
					./$(NAME)

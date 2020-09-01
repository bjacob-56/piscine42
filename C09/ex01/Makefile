
SRCS	= srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c

OBJS 	= ${SRCS:.c=.o}

NAME = libft.a
CC	?= gcc
AR	?= ar
RM	?= rm -f
CFLAGS	= -Wall -Wextra -Werror -I./includes

.c.o:
	${CC} ${CFLAGS} -o $@ -c $<

${NAME}:	${OBJS}
	${AR} rcs ${NAME} ${OBJS}

all : 		${NAME}

clean :
	${RM} ${OBJS}

fclean : 	clean
	${RM} ${NAME}

re :		fclean all

.PHONY: all clean fclean re libft.a

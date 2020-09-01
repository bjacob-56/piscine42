
SRCS	= srcs/check_double_keys.c srcs/check_input_dictionary.c srcs/ft_free_init.c srcs/ft_word.c  srcs/modif_str_number.c srcs/open_dictionary.c srcs/rush_02.c

OBJS 	= ${SRCS:.c=.o}

NAME = rush-02
CC	?= gcc
RM	?= rm -f
CFLAGS	= -Wall -Wextra -Werror -I./includes

.c.o:
	${CC} ${CFLAGS} -o $@ -c $<

${NAME}:	${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS}

all : 		${NAME}

clean :
	${RM} ${OBJS}

fclean : 	clean
	${RM} ${NAME}

re :		fclean all

.PHONY: all clean fclean re rush-02

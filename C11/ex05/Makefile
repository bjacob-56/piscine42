
SRCS	= do_op.c ft_atoi.c ft_operateurs.c ft_putnbr.c

OBJS 	= ${SRCS:.c=.o}

NAME = do-op
CC	?= gcc
RM	?= rm -f
CFLAGS	= -Wall -Wextra -Werror -I./operateurs.h

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

.PHONY: all clean fclean re do-op

NAME_S = server

NAME_C = client

CC	= clang

CFLAGS	= -Wall -Wextra -Werror -g

RM	= rm -f

SSRC	= server.c

CSRC	= client.c

SOBJ = ${SSRC:.c=.o}

COBJ = ${CSRC:.c=.o}

.c.o:
	${CC} ${CFLAGS} -c $< -o $@

all: ${NAME_S} ${NAME_C}

${NAME_S}: ${SOBJ}
	@make -C ./libft/
	${CC} ${CFLAGS} -o $(NAME_S) ${SOBJ} libft/libft.a

$(NAME_C):${COBJ}
	@make -C ./libft/
	${CC} ${CFLAGS} -o $(NAME_C) ${COBJ} libft/libft.a

clean:
	${RM} ${SOBJ} ${COBJ}
	@cd libft; make fclean

fclean:	clean
	${RM} client server

re:	fclean all

.PHONY:	re fclean clean all

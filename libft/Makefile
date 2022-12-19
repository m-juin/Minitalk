# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/27 10:16:13 by mjuin             #+#    #+#              #
#    Updated: 2022/11/22 09:56:39 by mjuin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

CC	= clang

AR	= ar rcs

CFLAGS	= -Wall -Wextra -Werror -g

RM	= rm -f

SRCS_ALL = ${SRC_CHAR} $(SRC_IS) $(SRC_MEMORY) $(SRC_STR) \
 $(SRC_WRITE) $(SRC_MISC) $(SRC_LST)

SRC_CHAR = 	./SRC/Char/ft_toupper.c \
	./SRC/Char/ft_tolower.c

SRC_IS = 	./SRC/Is/ft_isalpha.c \
	./SRC/Is/ft_isdigit.c \
	./SRC/Is/ft_isalnum.c \
	./SRC/Is/ft_isascii.c \
	./SRC/Is/ft_isprint.c

SRC_MEMORY = ./SRC/Memory/ft_memset.c \
	./SRC/Memory/ft_bzero.c \
	./SRC/Memory/ft_memcpy.c \
	./SRC/Memory/ft_memmove.c \
	./SRC/Memory/ft_memchr.c \
	./SRC/Memory/ft_memcmp.c \
	./SRC/Memory/ft_calloc.c

SRC_STR = ./SRC/Str/ft_strlen.c \
	./SRC/Str/ft_strlcpy.c \
	./SRC/Str/ft_strlcat.c \
	./SRC/Str/ft_strchr.c \
	./SRC/Str/ft_strrchr.c \
	./SRC/Str/ft_strncmp.c \
	./SRC/Str/ft_strnstr.c \
	./SRC/Str/ft_strdup.c \
	./SRC/Str/ft_substr.c \
	./SRC/Str/ft_strjoin.c \
	./SRC/Str/ft_strtrim.c \
	./SRC/Str/ft_strmapi.c \
	./SRC/Str/ft_striteri.c \
	./SRC/Str/ft_straddchar.c

SRC_WRITE = ./SRC/Write/ft_putchar_fd.c \
	./SRC/Write/ft_putstr_fd.c \
	./SRC/Write/ft_putendl_fd.c \
	./SRC/Write/ft_putnbr_fd.c \
	./SRC/Write/ft_puthexa_fd.c \
	./SRC/Write/ft_uputnbr_fd.c \
	./SRC/Write/ft_printf.c

SRC_MISC = ./SRC/Misc/ft_atoi.c \
	./SRC/Misc/ft_split.c \
	./SRC/Misc/ft_itoa.c \
	./SRC/Misc/ft_power.c \
	./SRC/Misc/ft_convert_bin.c

SRC_LST	= ./SRC/Lst/ft_lstnew.c \
	./SRC/Lst/ft_lstadd_front.c \
	./SRC/Lst/ft_lstsize.c \
	./SRC/Lst/ft_lstlast.c \
	./SRC/Lst/ft_lstadd_back.c \
	./SRC/Lst/ft_lstdelone.c \
	./SRC/Lst/ft_lstclear.c \
	./SRC/Lst/ft_lstiter.c \
	./SRC/Lst/ft_lstmap.c

OBJS_ALL = ${SRCS_ALL:.c=.o}

OBJS_PRINTF = ${SRC_WRITE:.c=.o}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:	$(NAME)

$(NAME):	${OBJS_ALL}
	${AR} ${NAME} ${OBJS_ALL}

clean:
	${RM} ${OBJS_ALL}

fclean:	clean
	${RM} ${NAME}

re:	fclean all

printf:		${OBJS_PRINTF}
	${AR} ${NAME} ${OBJS_PRINTF}

.PHONY:
	re fclean clean all printf

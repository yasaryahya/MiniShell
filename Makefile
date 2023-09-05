NAME = minishell

CC = cc
CFLAGS = -Wall -Werror -Wextra

UNAME		:= $(shell uname -s)
USER 		:= $(shell whoami)

SRC = $(shell find . -name "*.c")

RL_INC	:= /goinfre/$(USER)/brew/Cellar/readline/8.2.1/include
RL_LIB	:= /goinfre/$(USER)/brew/Cellar/readline/8.2.1/lib


${NAME}:
	${CC} ${CFLAGS} ${SRC} -o ${NAME} -lreadline

all: ${NAME}

clean:

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re down_brew
CC = cc
CFLAGS = -Wall -Wextra -Werror 

NAME = minishell
SRC = $(shell find . -name "*.c")

${NAME}:
	${CC} ${CFLAGS} ${SRC} -o ${NAME} -lreadline

all: ${NAME}

clean:

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
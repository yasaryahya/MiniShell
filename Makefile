CC = cc
CFLAGS = $(INCLUDE) -Wall -Werror -Wextra

INCLUDE = -IInclude/ -I/Users/$(USER)/goinfre/brew/Cellar/readline/8.2.1/include

NAME = minishell
SRC = $(shell find . -name "*.c")

${NAME}:
	${CC} ${CFLAGS} ${SRC} -o ${NAME} -lreadline

all: ${NAME}

clean:

fclean: clean
	${RM} ${NAME}

re: fclean all

down_brew:
	git clone "https://github.com/Homebrew/brew" /goinfre/$(USER)/brew
	eval "$$(/goinfre/$(USER)/brew/bin/brew shellenv)"
	/goinfre/$(USER)/brew/bin/brew update --force --quiet
	chmod -R go-w "$$(/goinfre/$(USER)/brew/bin/brew --prefix)/share/zsh"
	@echo "Brew installed inside /goinfre/$(USER)/brew"
	/goinfre/$(USER)/brew/bin/brew install readline
	@echo "Brew readline installed."

.PHONY: all clean fclean re down_brew
NAME = minishell

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I$(RL_INC) -L$(RL_LIB) -lreadline -g -ggdb

RM = rm -rf

SRCS = $(wildcard *.c function/*.c main/*.c lexer/*.c env/*.c)

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

USER := $(shell whoami)

RL_INC = /goinfre/$(USER)/brew/Cellar/readline/8.2.1/include
RL_LIB = /goinfre/$(USER)/brew/Cellar/readline/8.2.1/lib

all: $(NAME)

$(NAME): $(SRCS) libft
	@$(CC) $(CFLAGS) -o $(NAME) $(SRCS) $(LIBFT)
	@./$(NAME)

v:
	@$(CC) $(CFLAGS) -o $(NAME) $(SRCS) $(LIBFT)
	@valgrind ./$(NAME)

libft:
	@make -C $(LIBFT_PATH) all

down_brew:
	git clone "https://github.com/Homebrew/brew" /goinfre/$(USER)/brew
	eval "$$(/goinfre/$(USER)/brew/bin/brew shellenv)"
	/goinfre/$(USER)/brew/bin/brew update --force --quiet
	chmod -R go-w "$$(/goinfre/$(USER)/brew/bin/brew --prefix)/share/zsh"
	@echo "Brew installed inside /goinfre/$(USER)/brew"
	/goinfre/$(USER)/brew/bin/brew install readline
	@echo "Brew readline installed."

clean:
	@make -C $(LIBFT_PATH) clean

fclean:
	@make -C $(LIBFT_PATH) fclean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re libft $(NAME)

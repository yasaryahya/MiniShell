NAME = minishell
CC = gcc
CFLAGS = -Wall -Wextra -Werror -lreadline -g -ggdb
RM = rm -rf
SRCS = $(wildcard *.c function/*.c main/*.c lexer/*.c env/*.c)
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a
USER := $(shell whoami)
RL_INC = /usr/include
#RL_LIB = /usr/lib/x86_64-linux-gnu
#RL_FLAGS = -lreadline -L

all: $(NAME)

$(NAME): $(SRCS) libft
	@$(CC) $(CFLAGS) -o $(NAME) $(SRCS) $(LIBFT) #$(RL_FLAGS)

v:
	@$(CC) $(CFLAGS) -o $(NAME) $(SRCS) $(LIBFT) #$(RL_FLAGS)
	@valgrind ./$(NAME)

libft:
	@make -C $(LIBFT_PATH) all

clean:
	@make -C $(LIBFT_PATH) clean

fclean:
	@make -C $(LIBFT_PATH) fclean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re libft $(NAME) v

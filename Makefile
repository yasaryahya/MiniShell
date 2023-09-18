# Proje adı
NAME = minishell

# Derleyici
CC = gcc

# Derleme seçenekleri
CFLAGS = -Wall -Wextra -Werror -I$(RL_INC) -L$(RL_LIB) -lreadline

# Temizleme komutu
RM = rm -rf

# Kaynak dosyaları ve dizin yapısı
SRCS = $(wildcard *.c function/*.c library/*.c main/*.c Lexer/*.c token/*.c)

# libft kütüphanesi
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

# Kullanıcı adı ve işletim sistemi belirleme
USER := $(shell whoami)

# readline kütüphanesi yolları
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

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekuchel <ekuchel@student.42wolfsburg.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/05 16:52:32 by ekuchel           #+#    #+#              #
#    Updated: 2023/10/14 00:42:31 by ekuchel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

S = ./
HDRS_DIR = ./

NAME = philo

SRC = $(S)main.c \
	$(S)utils.c \

# List of object files derived from the source files
OBJ = $(SRC:.c=.o)

HDRS = -I$(HDRS_DIR)
CC = @gcc
CFLAGS = -Wall -Werror -Wextra

RM = /bin/rm -f
RMDIR = /bin/rmdir

define ASCII_ART
#   ██▓███  ██░ ██ ██▓██▓    ▒█████   ██████ ▒█████  ██▓███  ██░ ██▓█████ ██▀███   ██████
#  ▓██░  ██▓██░ ██▓██▓██▒   ▒██▒  ██▒██    ▒▒██▒  ██▓██░  ██▓██░ ██▓█   ▀▓██ ▒ ██▒██    ▒
#  ▓██░ ██▓▒██▀▀██▒██▒██░   ▒██░  ██░ ▓██▄  ▒██░  ██▓██░ ██▓▒██▀▀██▒███  ▓██ ░▄█ ░ ▓██▄
#  ▒██▄█▓▒ ░▓█ ░██░██▒██░   ▒██   ██░ ▒   ██▒██   ██▒██▄█▓▒ ░▓█ ░██▒▓█  ▄▒██▀▀█▄   ▒   ██▒
#  ▒██▒ ░  ░▓█▒░██░██░██████░ ████▓▒▒██████▒░ ████▓▒▒██▒ ░  ░▓█▒░██░▒████░██▓ ▒██▒██████▒▒
#  ▒▓▒░ ░  ░▒ ░░▒░░▓ ░ ▒░▓  ░ ▒░▒░▒░▒ ▒▓▒ ▒ ░ ▒░▒░▒░▒▓▒░ ░  ░▒ ░░▒░░░ ▒░ ░ ▒▓ ░▒▓▒ ▒▓▒ ▒ ░
#  ░▒ ░     ▒ ░▒░ ░▒ ░ ░ ▒  ░ ░ ▒ ▒░░ ░▒  ░ ░ ░ ▒ ▒░░▒ ░     ▒ ░▒░ ░░ ░  ░ ░▒ ░ ▒░ ░▒  ░ ░
#  ░░       ░  ░░ ░▒ ░ ░ ░  ░ ░ ░ ▒ ░  ░  ░ ░ ░ ░ ▒ ░░       ░  ░░ ░  ░    ░░   ░░  ░  ░
#           ░  ░  ░░     ░  ░   ░ ░       ░     ░ ░          ░  ░  ░  ░  ░  ░          ░
#

endef
export ASCII_ART

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
RESET = \033[0m
BANNER_PHILO = @echo "$$ASCII_ART"

all : $(NAME)

$(NAME) : $(OBJ)
	@echo "$(RED)";
	$(BANNER_PHILO)
	@echo "$(GREEN)Philosophers Done!$(RESET)";
	$(CC) $(CFLAGS) -pthread $(HDRS) $^ -o $@
# @echo "$(YELLOW)Compiling Philosophers ...$(RESET)";

%.o: %.c
	$(CC) $(CFLAGS) $(HDRS) -c $< -o $@

run : $(NAME)
	./$(NAME)

clean:
	$(RM) -f $(OBJ)

fclean: clean
	$(RM) -f $(NAME)
	@echo "$(BLUE)Cleaning philo... $(RESET)";

re: fclean all

.PHONY: all clean fclean re run
#%.o:%.c
# $(CC) $(CFLAGS) .c $^-o $@

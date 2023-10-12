# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekuchel <ekuchel@student.42wolfsburg.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/05 16:52:32 by ekuchel           #+#    #+#              #
#    Updated: 2023/10/12 18:23:01 by ekuchel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

S = ./
HDRS_DIR = ./

NAME = philo

SRC = $(S)main.c \


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
	@echo "$(RED)";
	$(BANNER_PHILO)
	@echo "$(GREEN)Philosophers Done!$(RESET)";

$(NAME) : $(SRC)
	$(CC) $(CFLAGS) -pthread $(HDRS) $^ -o $@
# @echo "$(YELLOW)Compiling Philosophers ...$(RESET)";

run : $(NAME)
	./$(NAME)

clean:
	$(RM) -f *.o

fclean: clean
	$(RM) -f $(NAME)
	@echo "$(BLUE)Cleaning philo... $(RESET)";

re: fclean all run

.PHONY: all clean fclean re run
#%.o:%.c
# $(CC) $(CFLAGS) .c $^-o $@


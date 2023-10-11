# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekuchel <ekuchel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/05 16:52:32 by ekuchel           #+#    #+#              #
#    Updated: 2023/10/11 15:38:36 by ekuchel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

S = ./src/
HDRS_DIR = ./includes/

NAME = philo

SRC = $(S)/main.c \


HDRS = -I$(HDRS_DIR)
CC = gcc
CFLAGS = -Wall -Werror -Wextra

RM = /bin/rm -f
RMDIR = /bin/rmdir

define ASCII_ART
	 _____
	__|__   |__  __   _  ____  ____    _____  ______  _____  _____  __   _  ______  _____   ______
	|     |     ||  |_| ||    ||    |  /     \|   ___|/     \|     ||  |_| ||   ___||     | |   ___|
	|    _|     ||   _  ||    ||    |_ |     | `-.`-. |     ||    _||   _  ||   ___||     \  `-.`-.
	|___|     __||__| |_||____||______|\_____/|______|\_____/|___|  |__| |_||______||__|\__\|______|
	    |_____|

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
	@echo "$(GREEN)Philosophers successfully compiled!$(RESET)";

$(NAME) : $(SRC)
	$(CC) $(CFLAGS) -pthread $(HDRS) $^ -o $@
	@echo "$(YELLOW)Compiling Philosophers ...$(RESET)";


clean:
	$(RM) -r $(NAME)

fclean: clean
	$(RM) -f $(NAME)
	@echo "$(BLUE)Cleaning philo... $(RESET)";

re: fclean all

.PHONY: all clean fclean re
#%.o:%.c
# $(CC) $(CFLAGS) .c $^-o $@


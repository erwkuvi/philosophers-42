# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekuchel <ekuchel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/05 16:52:32 by ekuchel           #+#    #+#              #
#    Updated: 2023/10/09 17:39:36 by ekuchel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
RESET = \033[0m

S = ./src/
HDRS_DIR = ./includes/

NAME = philo

SRC = $(S)/main.c \


HDRS = -I$(HDRS_DIR)
CC = gcc
CFLAGS = -Wall -Werror -Wextra

RM = /bin/rm -f
RMDIR = /bin/rmdir

all : $(NAME)
	@echo "$(GREEN)Philosophers successfully compiled!$(RESET)";

$(NAME) : $(SRC)
	$(CC) $(CFLAGS) $(HDRS) $^ -o $@

clean:
	$(RM) -r $(NAME)

fclean: clean
	$(RM) -f $(NAME)
	@echo "$(BLUE)Cleaning philo... $(RESET)";

re: fclean all

.PHONY: all clean fclean re
#%.o:%.c
# $(CC) $(CFLAGS) .c $^-o $@



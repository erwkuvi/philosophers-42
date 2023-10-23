# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekuchel <ekuchel@student.42wolfsburg.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/05 16:52:32 by ekuchel           #+#    #+#              #
#    Updated: 2023/10/23 13:41:19 by ekuchel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

S = ./src/
HDRS_DIR = ./includes/

NAME = philo

SRC = $(S)main.c \
	$(S)utils.c \
	$(S)utils2.c \
	$(S)error_handle.c \
	$(S)error.c \
	$(S)join_destroy.c \
	$(S)init.c
# $(S)routine.c \
# $(S)actions.c

# List of object files derived from the source files
OBJ = $(SRC:.c=.o)

HDRS = -I$(HDRS_DIR)
CC = @gcc
CFLAGS = -Wall -Werror -Wextra -fsanitize=thread -g
#valgrind --tool=helgrind ./philo <args>
#valgrind --tool=drd ./philo <args>

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
	./$(NAME) 4 410 200 200

clean:
	$(RM) -f $(OBJ)

fclean: clean
	$(RM) -f $(NAME)
	@echo "$(BLUE)Cleaning philosophers... $(RESET)";

re: fclean all run

.PHONY: all clean fclean re run
#%.o:%.c
# $(CC) $(CFLAGS) .c $^-o $@


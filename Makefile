# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekuchel <ekuchel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/05 16:52:32 by ekuchel           #+#    #+#              #
#    Updated: 2023/10/05 18:00:38 by ekuchel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Sources and object files are going to be in a sub-directory from now on
S = src/
O = obj/

HDRS_DIR = ./includes/
HDRS = -I$(HDRS_DIR)


SRC = $S/main.c \
	#   $Sfunction.c

OBJ = $(SRC:$S%=$O%.o) ##Be careful, here we use "SRC:", not "$(SRC):"

$O:
	@mkdir -p $@
# The @ at the beginning of the line prevents make
# from displaying the line before executing it

$O%.o: $S% | $O
	$(CC) $(CFLAGS) -c $< -o $@

NAME = philo

CC = gcc
CFLAGS = -Wall -Werror -Wextra

RM = /bin/rm -f
RMDIR = /bin/rmdir

all : $(NAME)
	@echo "Philo successfully compiled!";

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(HDRS) $^ -o $@

cleanobj:
	$(RM) $(OBJ)

cleanobjdir: cleanobj
	$(RMDIR) $O

clean: cleanobjdir

fclean: clean
	$(RM) $(NAME)
	@echo "Cleaning philo... ";

re: fclean all

.PHONY: all clean fclean re
#%.o:%.c
# $(CC) $(CFLAGS) .c $^-o $@



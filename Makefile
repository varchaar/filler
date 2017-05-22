# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: varichar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/22 13:41:20 by varichar          #+#    #+#              #
#    Updated: 2017/05/22 13:17:37 by varichar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UNAME := $(shell uname)
NAME = varichar.filler
HEADER = -Iincludes -Ilib/includes
SRCS_P := $(shell ls srcs/*.c)
SRCS := $(addprefix srcs/, $(SRCS_P))
CFLAGS = -Wall -Werror -Wextra -ggdb
LIB = -Llib -lft
CC = gcc
OBJ := $(SRCS_P:.c=.o)
RED=\033[1;31m
GREEN=\033[1;32m
NC=\033[0m

.PHONY: all fclean clean re lib minilibx cleanlibx cleanlib OBJ

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) lib
	@echo "$(GREEN)[✓]$(NC) Objects of $(NAME) compiled"
	@$(CC) -o $@ $(HEADER) $(CFLAGS) $(LIB) $(OBJ) 
	@echo "$(GREEN)[✓]$(NC) library $(NAME) built"

%.o: %.c
	@$(CC) -c $< -o $@ $(CFLAGS) $(HEADER) 

lib:
	@make -C lib

clean:
	@rm -Rf $(OBJ)
	@make -C lib clean
	@echo "$(RED)[-]$(NC) Objects of $(NAME) cleaned"

cleanlib:
	@make -C lib fclean
	@echo "$(RED)[-]$(NC) Objects of $(NAME) cleaned"

fclean: clean cleanlib cleanlibx
	@rm -Rf $(NAME)
	@echo "$(RED)[-]$(NC) Library $(NAME) cleaned"

re: fclean all

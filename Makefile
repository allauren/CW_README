# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/07 23:19:18 by tcassier          #+#    #+#              #
#    Updated: 2018/02/04 13:32:13 by tcassier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean all re fclean

NAME = asm

CC = gcc
CFLAGS = -Wall -Werror -Wextra -I$(INC_PATH) -I$(LFT_INC_PATH)

SRC_PATH = ./src/
SRCS = $(addprefix $(SRC_PATH), $(SRC))
SRC = main.c

OBJ_PATH = ./obj/
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))
OBJ = $(SRC:.c=.o)

INC_PATH = ./includes/
INCS = $(addprefix $(INC_PATH), $(INC))
INC = asm.h

LFT_INC_PATH = $(LFT_PATH)includes
LFT_PATH = ./libft/
LFT_FLAGS = -L $(LFT_PATH) -lft

all: $(NAME)

$(NAME): $(OBJ_PATH) $(OBJS)
	@make -C $(LFT_PATH) all
	@$(CC) $(CFLAGS) -o $@ $(OBJS) $(LFT_FLAGS)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(INCS)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

clean: clean_lft
	@rm -f $(OBJ)
	@rm -rf $(OBJ_PATH)

fclean: clean fclean_lft
	@rm -f $(NAME)

clean_lft:
	@make -C $(LFT_PATH) clean

fclean_lft:
	@make -C $(LFT_PATH) fclean

re: fclean all

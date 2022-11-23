# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajeannin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 18:12:51 by ajeannin          #+#    #+#              #
#    Updated: 2022/11/23 19:04:54 by ajeannin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

########## VARIABLES ##########

NAME			= push_swap
INCLUDES		= -Iincludes -Ilibft
LIBFT			= -Llibft -lft
#INCLUDES		= includes
#LIBFT			= libft
SRC_DIR			= src/
OBJ_DIR			= obj/
SRC_DIR_BONUS		= src_bonus/
CC			= gcc
CFLAGS			= -Wall -Werror -Wextra



########### SOURCES ###########

SRC_FILES		= main			\
			  parsing		\
			  push			\
			  rev_rotate		\
			  rotate		\
			  sort_stack		\
			  swap			\
			  utils			\

SRC			= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ			= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
OBJF			= .cache_exists


SRC_FILES_BONUS		= checker		\

SRC_BONUS		= $(addprefix $(SRC_DIR_BONUS), $(addsuffix .c, $(SRC_FILES_BONUS)))
OBJ_BONUS		= $(addprefix $(OBJ_DIR_BONUS), $(addsuffix .o, $(SRC_FILES_BONUS)))

############ RULES ############

all:		$(NAME)

$(NAME):	$(OBJ)
#	make -C $(LIBFT)
	make -C libft/
	$(CC) $(FLAGS) $(OBJ) $(INCLUDES) $(LIBFT) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:	
	make clean -C libft/	
	rm -rf $(OBJ_DIR)

fclean:		clean
	make fclean -C libft/
	rm -rf $(NAME)

bonus:

re:		fclean all


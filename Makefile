# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/26 16:29:54 by vpeinado          #+#    #+#              #
#    Updated: 2024/04/29 23:57:30 by vpeinado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Style
GREEN	=	\033[92;5;118m
YELLOW	=	\033[93;5;226m
GRAY	=	\033[33;2;37m
RESET	=	\e[0m
CURSIVE	=	\033[33;3m
RED		= 	\033[31m

#Program name
NAME	= minishell
#Compiler
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror #-g -fsanitize=address 
#CFLAGS			= -Wall -Werror -Wextra -I$(INCLUDE) -I /Users/$(USER)/.brew/opt/readline/include/ #-g3 -fsanitize=address 
#OFLAGS			= -lreadline -L /Users/$(USER)/.brew/opt/readline/lib
RM		= rm -f

#Includes
INC			= -I ./inc/

#Libft
LIBFT_DIR	= libft/
LIBFT_NAME	= libft.a
LIBFT		= $(LIBFT_DIR)$(LIBFT_NAME)

#Source files
SRC_DIR	= src/
EXEC_DIR	= exec/
BUILTIN_DIR= builtins/
PARSE_DIR	= parse/
SRC 	= $(shell find src -type f -iname "*.c" | sed 's|^src/||')

#Object files
OBJ_DIR	= obj/
OBJ		= $(SRC:.c=.o)
OBJS 	= $(addprefix $(OBJ_DIR), $(OBJ))
			

all: obj $(LIBFT) $(NAME) 

obj:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)$(EXEC_DIR)
	@mkdir -p $(OBJ_DIR)$(BUILTIN_DIR)
	@mkdir -p $(OBJ_DIR)$(PARSE_DIR)	
$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@ 

$(LIBFT):
	@make -sC $(LIBFT_DIR)

#push $(OFLAGS) after $Cflags
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(INC) -lreadline 
	@printf "$(GREEN)Minishell: OK!$(RESET)\n"

clean:
	@rm -Rf $(OBJ_DIR)
	@make clean -sC $(LIBFT_DIR)
	@printf "$(YELLOW)Object files: $(RED)Deleted!$(RESET)\n"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFT_DIR)$(LIBFT_NAME)
	@printf "$(YELLOW)Minishell: $(RED)Deleted!$(RESET)\n"

re: fclean all

.PHONY: all re clean fclean

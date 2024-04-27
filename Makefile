# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/26 16:29:54 by vpeinado          #+#    #+#              #
#    Updated: 2024/04/27 15:41:14 by vpeinado         ###   ########.fr        #
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
LIBFT_PATH	= libft/
LIBFT_NAME	= libft.a
LIBFT		= $(LIBFT_PATH)$(LIBFT_NAME)

#Source files
SRC_PATH	= src/
EXEC_PATH	= exec/
BUILTIN_PATH= builtin/
PARSE_PATH	= parse/
SRC 	= main.c env.c exit.c heredoc.c signals.c utils.c\
			builtins/ft_cd.c builtins/ft_echo.c builtins/ft_env.c \
			builtins/ft_exit.c builtins/ft_export.c builtins/ft_pwd.c builtins/ft_unset.c \
			exec/main_exec.c exec/utils_exec.c \
			parse/commands.c parse/errors_parse.c parse/expand_utils.c parse/expand.c \
			parse/extract.c parse/parse_utils.c parse/parse.c parse/split_args.c 
SRCS	= $(addprefix $(SRC_PATH), $(SRC))

#Object files
OBJ_PATH	= obj/
BUILTIN_PATH= builtins/
EXEC_PATH	= exec/
PARSE_PATH	= parse/
OBJ		= $(SRC:.c=.o)
OBJS 	= $(addprefix $(OBJ_PATH), $(OBJ))
			

all: obj $(LIBFT) $(NAME) 

obj:
	@mkdir -p $(OBJ_PATH)
	@mkdir -p $(OBJ_PATH)$(EXEC_PATH)
	@mkdir -p $(OBJ_PATH)$(BUILTIN_PATH)
	@mkdir -p $(OBJ_PATH)$(PARSE_PATH)	
$(OBJ_PATH)%.o: $(SRC_PATH)%.c | $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@ 

$(LIBFT):
	@make -sC $(LIBFT_PATH)

#push $(OFLAGS) after $Cflags
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(INC) -lreadline 
	@printf "$(GREEN)Minishell: OK!$(RESET)\n"

clean:
	@rm -Rf $(OBJ_PATH)
	@make clean -C $(LIBFT_PATH)
	@printf "$(YELLOW)Object files: $(RED)Deleted!$(RESET)\n"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFT_PATH)$(LIBFT_NAME)
	@printf "$(YELLOW)Minishell: $(RED)Deleted!$(RESET)\n"

re: fclean all

.PHONY: all re clean fclean

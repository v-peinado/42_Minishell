# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/03 14:27:33 by vpeinado          #+#    #+#              #
#    Updated: 2024/04/26 21:02:16 by vpeinado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN	=	\033[92;5;118m
YELLOW	=	\033[93;5;226m
GRAY	=	\033[33;2;37m
RESET	=	\e[0m
CURSIVE	=	\033[33;3m
RED		= 	\033[31m

SRCS  		= ft_bzero.c ft_isdigit.c ft_memcpy.c ft_strncmp.c ft_toupper.c \
				ft_isalnum.c ft_isprint.c ft_memset.c ft_strnstr.c \
				ft_isalpha.c ft_memchr.c ft_strchr.c ft_strrchr.c \
				ft_isascii.c ft_memcmp.c ft_strlen.c ft_tolower.c \
				ft_strlcpy.c ft_strnstr.c ft_memmove.c ft_atoi.c \
				ft_calloc.c ft_strdup.c ft_strlcat.c ft_strjoin.c \
				ft_putstr_fd.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
				ft_substr.c ft_striteri.c ft_strmapi.c ft_strtrim.c ft_split.c \
				ft_itoa.c get_next_line.c get_next_line_utils.c \
				ft_isdigit_string.c ft_freestr.c ft_arraylen.c \
				ft_arraypush.c ft_print_char.c ft_print_int.c ft_print_ptr.c ft_print_hex.c\
				ft_print_str.c ft_print_uint.c ft_printf.c ft_free_matrix.c
OBJS		= $(SRCS:.c=.o)

BONUS		= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
				ft_lstiter.c ft_lstmap.c ft_lstclear.c ft_lstdelone.c \
				ft_lstadd_back.c 

BONUS_OBJS	= $(BONUS:.c=.o)

CC			= gcc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror 

NAME		= libft.a

all: 		$(NAME)

$(NAME):	$(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@printf "$(GRAY)Libft: OK!$(RESET)\n"

clean:
	@$(RM) $(OBJS) $(BONUS_OBJS)
	@printf "$(GRAY)Libft files: $(RED)Deleted!$(RESET)\n"

fclean:		clean 
	@$(RM) $(NAME)

re:					fclean all

bonus:		$(OBJS) $(BONUS_OBJS)
	@ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY:				all clean fclean re 
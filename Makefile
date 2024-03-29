#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: JEAN-SEBA <jcourtem@student.42quebec>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/30 18:55:23 by JEAN-SEBA         #+#    #+#              #
#    Updated: 2022/01/26 10:50:35 by jcourtem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 			= 	gcc -Wextra -Wall -Werror -g
NAME 		= 	libftprintf.a
LIBFT_PATH	=	include/libft/
INC			=	include/ft_printf.h
SRCS		=	srcs/
FILES		=	ft_check_flag.c \
				ft_printf.c \
				ft_put_h.c \
				ft_put_i.c \
				ft_put_p.c \
				ft_put_s.c \
				ft_put_u.c \
				ft_intlen.c \
				ft_strlen.c \
			   	ft_put_c.c \
				ft_putnbr.c \
				ft_put_percent.c 
SRCS_FILES	=	$(addprefix $(SRCS),$(FILES))	
OBJS 		= 	$(SRCS_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS) $(INC)

$(OBJS):

.Phony: clean fclean re

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

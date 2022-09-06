# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/26 18:22:31 by ommohame          #+#    #+#              #
#    Updated: 2022/08/27 03:08:03 by ommohame         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		philo

SRCS		=		main.c \
					help.c \
					parser.c \
					fill_struct.c \

UTILS		=	ft_strlen.c \
				ft_putstr_fd.c \
				ft_strfcmp.c \
				ft_isdigit.c \
				ft_atox.c	\
				print_struct.c \

SRCS_DIR	=		./srcs/

UTILS_DIR	=		./utils/

INCLUDES	=		./includes

CC			=		gcc

CFLAGS		=		-Wall -Werror -Wextra

OBJS		=		$(addprefix $(SRCS_DIR),$(SRCS:.c=.o))

UTILS_OBJS	=		$(addprefix $(UTILS_DIR),$(UTILS:.c=.o))

RM			=		rm -rf

$(NAME)		:		$(UTILS_OBJS) $(OBJS)
					$(CC) $(CFLAGS) $(UTILS_OBJS) $(OBJS) -I$(INCLUDES) -o $(NAME)
					clear
					@echo "compilation Successful! 🥳"

all			:		$(NAME)

clean		:
					@$(RM) $(OBJS) 
					@$(RM) $(UTILS_OBJS)
					@echo "clean Successful! 🥳"

fclean		:		clean
					@$(RM) $(NAME)
					@echo "fclean Successful! 🥳"

re			:		fclean all

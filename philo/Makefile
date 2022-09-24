# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/26 18:22:31 by ommohame          #+#    #+#              #
#    Updated: 2022/09/24 15:24:26 by ommohame         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		philo

SRCS		=		main.c \
					philo.c \
					help.c \
					parser.c \
					fill_struct.c \
					threads.c \
					life.c \
					time.c \
					check_death.c \
					print_state.c \

UTILS		=		ft_strlen.c \
					ft_strdup.c \
					ft_put_fd.c \
					ft_strfcmp.c \
					ft_isdigit.c \
					ft_atox.c	\
					print_struct.c \

SRCS_DIR	=		./srcs/

UTILS_DIR	=		./utils/

INCLUDES	=		./includes

CC			=		gcc

CFLAGS		=		-Wall -Werror -Wextra -pthread -g3

OBJS		=		$(addprefix $(SRCS_DIR),$(SRCS:.c=.o))

UTILS_OBJS	=		$(addprefix $(UTILS_DIR),$(UTILS:.c=.o))

RM			=		rm -rf

$(NAME)		:		$(UTILS_OBJS) $(OBJS)
					$(CC) $(CFLAGS) $(UTILS_OBJS) $(OBJS) -I$(INCLUDES) -o $(NAME)
					clear
					@echo "Compilation  Successful!"

all			:		$(NAME)

clean		:
					@$(RM) $(OBJS) 
					@$(RM) $(UTILS_OBJS)

fclean		:		clean
					@$(RM) $(NAME)

re			:		fclean all

.PHONY		:		$(NAME) all clean fclean re
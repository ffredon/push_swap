# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fredon <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/23 09:01:04 by fredon            #+#    #+#              #
#    Updated: 2016/02/08 12:59:38 by fredon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

SRCS	= 	srces/main.c \
			srces/ft_read.c \
			srces/ft_utils.c \
			srces/ft_atoi.c \
			srces/ft_deal.c \
			srces/ft_insert.c \
			srces/ft_trif.c \
			srces/ft_resolve.c \
			srces/ft_swap.c \
			srces/ft_bubble.c \
			srces/ft_nextswp.c \
			srces/ft_ops.c \
			srces/ft_dinsert.c \
			srces/ft_ops2.c \
			srces/ft_testswap.c \
			srces/ft_fus.c \
			srces/ft_fus2.c \
			srces/ft_use2.c \
			srces/ft_lstutils.c

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

PRINTF	=	libftprintf.a

PDIR	=	lib/ft_printf

RM		=	rm -f

.PHONY	:	re clean fclean all

all		:
		@make $(NAME)

$(NAME)	:	libft $(OBJS)
		@echo "\033[1m\033[34m*** Making Executable *** \033[0m"
		@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(PDIR)/$(PRINTF) -I ./includes

%.o		:	%.c
		@echo "\033[1m\033[31mBuilding\033[0m \t$<"
		@$(CC) $(CFLAGS) -o $@ -c $^ -I ./includes

libft	:
		@echo "\033[1m\033[34m *** Compiling LIBPRINTF ***\033[0m"
		@make -C $(PDIR)

libcl	:
		@echo "\033[1m\033[34m *** Cleaning LIBPRINTF .o***\033[0m"
		@make -C $(PDIR) clean

libfcl	:
		@echo "\033[1m\033[34m*** Cleaning PRINTF EXEC ***\033[0m"
		@make -C $(PDIR) fclean

clean	: libcl
		@echo "\033[1m\033[034m*** Cleaning .o ***\033[0m"
		@$(RM) $(OBJS)

fclean	: clean libfcl
		@echo "\033[1m\033[34m*** Cleaning exec***\033[0m"
		@$(RM) $(NAME)

re		: fclean all

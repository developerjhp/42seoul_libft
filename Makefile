# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinhyupa <jinhyupa@student.42.kr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/07 22:00:07 by jinhyupa          #+#    #+#              #
#    Updated: 2022/02/07 22:00:12 by jinhyupa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

CC		= gcc
CFLAGS		= -Wall -Wextra -Werror

AR		= ar
ARFLAGS		= rcs

RM		= rm
RMFLAGS		= -f

INCLUDES	= ./libft.h

SRCS		=	ft_memset.c		\
			ft_bzero.c		\
			ft_memcpy.c		\
			ft_memmove.c		\
			ft_memchr.c		\
			ft_memcmp.c		\
			ft_strlen.c		\
			ft_strlcpy.c		\
			ft_strlcat.c		\
			ft_strchr.c		\
			ft_strrchr.c		\
			ft_strnstr.c		\
			ft_strncmp.c		\
			ft_atoi.c		\
			ft_isalnum.c		\
			ft_isalpha.c		\
			ft_isascii.c		\
			ft_isdigit.c		\
			ft_isprint.c		\
			ft_toupper.c		\
			ft_tolower.c		\
			ft_calloc.c		\
			ft_strdup.c		\
			ft_substr.c		\
			ft_strjoin.c		\
			ft_strtrim.c		\
			ft_split.c		\
			ft_itoa.c		\
			ft_strmapi.c		\
			ft_striteri.c		\
			ft_putchar_fd.c		\
			ft_putstr_fd.c		\
			ft_putendl_fd.c		\
			ft_putnbr_fd.c


SRCS_BN		=	ft_lstnew.c		\
			ft_lstadd_front.c	\
			ft_lstsize.c		\
			ft_lstlast.c		\
			ft_lstadd_back.c	\
			ft_lstdelone.c		\
			ft_lstclear.c		\
			ft_lstiter.c		\
			ft_lstmap.c

OBJS		= $(SRCS:.c=.o)

OBJS_BONUS	= $(SRCS_BN:.c=.o)

ifdef WITH_BONUS
A_OBJS = $(OBJS) $(OBJS_BONUS)
else
A_OBJS = $(OBJS)
endif

.PHONY : all
all : $(NAME)

%.o : %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(A_OBJS)
	$(AR) $(ARFLAGS) $@ $^

.PHONY : clean
clean :
	$(RM) $(RMFLAGS) $(OBJS) $(OBJS_BONUS)

.PHONY : fclean
fclean : clean
	$(RM) $(RMFLAGS) $(NAME)

.PHONY : re
re : fclean all

.PHONY : bonus
bonus :
	$(MAKE) WITH_BONUS=1 all
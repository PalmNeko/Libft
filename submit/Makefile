# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/22 17:19:34 by tookuyam          #+#    #+#              #
#    Updated: 2023/11/09 14:34:28 by tookuyam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS += -Wall -Wextra -Werror
CFLAGS += -MP -MMD
SRCS = \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	$(MY_SRC)

MY_SRC = \
	ft_strnlen.c \
	ft_strndup.c \
	ft_abs.c \
	ft_strrev.c \
	ft_swap_chr.c \
	ft_utoa.c \
	ft_utoa_base.c \
	ft_isspace.c \
	ft_mul_l.c \
	ft_add_l.c \
	ft_isupper.c \
	ft_islower.c \
	ft_strtol.c \
	ft_ultoa_base_str.c \
	ft_ltoa_inplace.c \
	ft_memswap.c

BONUS = \
	ft_lstnew_bonus.c \
	ft_lstadd_front_bonus.c \
	ft_lstsize_bonus.c \
	ft_lstlast_bonus.c \
	ft_lstadd_back_bonus.c \
	ft_lstdelone_bonus.c \
	ft_lstclear_bonus.c \
	ft_lstiter_bonus.c \
	ft_lstmap_bonus.c

OBJS = $(SRCS:.c=.o)
DEPENDS = $(SRCS:.c=.d)
BONUS_RULE = bonus
BONUS_OBJS = $(BONUS:.c=.o)
BONUS_DEPENDS = $(BONUS:.c=.d)
RELINK_GURAD_FLIES = $(BONUS_RULE)
CLEAN_FILES = $(OBJS) $(BONUS_OBJS) $(RELINK_GURAD_FLIES) $(DEPENDS) $(BONUS_DEPENDS)

all: $(NAME) $(BONUS_RULE)

-include $(DEPENDS)
-include $(BONUS_DEPENDS)

$(NAME): $(OBJS)
	ar rcs $(NAME) $?

$(BONUS_RULE): $(BONUS_OBJS)
	ar rcs $(NAME) $?
	echo date > $(BONUS_RULE)

clean:
	$(RM) $(CLEAN_FILES)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

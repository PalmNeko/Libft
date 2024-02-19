# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/22 17:19:34 by tookuyam          #+#    #+#              #
#    Updated: 2023/10/11 13:11:10 by tookuyam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft_test
CC = cc
INC = ../submit
CFLAGS += -Wall -Wextra -Werror -I $(INC)
SRCS = \
	main.c \
	ft_isalpha_test.c \
	ft_isdigit_test.c \
	ft_isalnum_test.c \
	ft_isascii_test.c \
	ft_isprint_test.c \
	ft_strlen_test.c \
	ft_memset_test.c \
	ft_bzero_test.c \
	ft_memcpy_test.c \
	ft_memmove_test.c \
	ft_strlcpy_test.c \
	ft_strlcat_test.c \
	ft_toupper_test.c \
	ft_tolower_test.c \
	ft_strchr_test.c \
	ft_strrchr_test.c \
	ft_strncmp_test.c \
	ft_memchr_test.c \
	ft_memcmp_test.c \
	ft_strnstr_test.c \
	ft_atoi_test.c \
	ft_calloc_test.c \
	ft_strdup_test.c \
	ft_substr_test.c \
	ft_strjoin_test.c \
	ft_strtrim_test.c \
	ft_split_test.c \
	ft_itoa_test.c \
	ft_strmapi_test.c \
	ft_striteri_test.c \
	ft_putchar_fd_test.c \
	ft_putstr_fd_test.c \
	ft_putendl_fd_test.c \
	ft_putnbr_fd_test.c \
	ft_lstnew_bonus_test.c \
	ft_lstadd_front_bonus_test.c \
	ft_lstsize_bonus_test.c \
	ft_lstlast_bonus_test.c \
	ft_lstadd_back_bonus_test.c \
	ft_lstdelone_bonus_test.c \
	ft_lstclear_bonus_test.c \
	ft_lstiter_bonus_test.c \
	ft_lstmap_bonus_test.c

LIB_DIR = ../submit
LIB_NAME = ft
LIB = $(LIB_DIR)/lib$(LIB_NAME).a

OBJS = $(SRCS:.c=.o)

all: pre_make $(NAME)

$(NAME): $(OBJS) $(LIB)
	$(CC) $(CFLAGS) -o $(NAME) -L $(LIB_DIR) -l $(LIB_NAME) $(OBJS)

pre_make $(LIB):
	make --directory $(LIB_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $^

norm: norm_c norm_h

norm_c: $(shell find .. -type f -name "*.c")
	@echo "\033[34mcheck norm - source\033[m"
	@echo "norminette $?"
	@norminette $? | sed -E 's/(Error:)/\\033[31m\1\\033[m/g' | xargs -0 printf "%b"
	@norminette $? > /dev/null
	echo "last success norm_h: $(shell date)" > norm_c
	echo "created by make command" >> norm_c

norm_h: $(shell find .. -type f -name "*.h")
	@echo "\033[34mcheck norm - headers\033[m"
	@echo "norminette -R CheckDefine $?"
	@norminette -R CehckDefine $? | sed -E 's/(Error:)/\\033[31m\1\\033[m/g' | xargs -0 printf "%b"
	@norminette -R CheckDefine $? > /dev/null
	echo "last run norm_h: $(shell date)" > norm_h
	echo "created by make command" >> norm_h

norm_clean:
	$(RM) norm_h norm_c

norm_re: norm_clean norm

test: norm all
	@echo "\033[34mstart test\033[m"
	echo "./$(NAME)"
	@./$(NAME) 2>&1 | sed -E 's/(Assertion failed)/\\033[31m\1\\033[m/g' | xargs -0 printf "%b"

clean:
	make --directory $(LIB_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	make --directory $(LIB_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all pre_make norm test clean fclean re

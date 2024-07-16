# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/22 17:19:34 by tookuyam          #+#    #+#              #
#    Updated: 2024/07/16 15:47:59 by tookuyam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = tester
ifeq ($(OS),Windows_NT)
    NAME = tester.exe
endif

CC = cc

LIBS = -L ../submit -L $(LIBTYCTEST) -l ft -l tyctest -l tyctest_main
LIBFT = ../submit/libft.a
LIBTYCTEST = ./tyctest
CFLAGS += -g -O0 -fsanitize=leak -Wall -Wextra -Werror -MMD -MP -I ../submit -I $(LIBTYCTEST)
SRCS = $(shell find . -name "*_test.c")
OBJS = $(SRCS:.c=.o)
DEPENDS = $(SRCS:.c=.d)


all: $(NAME)

-include $(DEPENDS)

$(NAME): $(LIBTYCTESTMAIN) $(LIBTYCTEST) $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

$(LIBFT): export CFLAGS := $(CFLAGS)
$(LIBFT): $(shell find ../submit -name "*.c")
	"$(MAKE)" --directory $(shell dirname $(LIBFT))

$(LIBTYCTEST):
	git clone git@github.com:PalmNeko/tyctest.git tyctest
	cd tyctest && make

.PHONY: test
test: $(NAME)
	./$(NAME)

.PHONY: clean
clean:
	make --directory $(shell dirname $(LIBFT)) clean
	find . -name "*.d" -delete
	find . -name "*.o" -delete
	find . -name "*.gcda" -delete
	find . -name "*.gcov" -delete
	find . -name "*.gcno" -delete

.PHONY: fclean
fclean: clean
	make --directory $(shell dirname $(LIBFT)) fclean
	$(RM) $(NAME)

.PHONY: re
re: fclean all

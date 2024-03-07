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

NAME = tester
ifeq ($(OS),Windows_NT)
    NAME = tester.exe
endif

CC = cc

LIBS = -L ../submit -L ./libs -l ft -l tyctest -l tyctest_main
LIBFT = ../submit/libft.a
LIBTYCTEST = ./libs/libtyctest.a
LIBTYCTESTMAIN = ./libs/libtyctest_main.a
LIBTYCTEST_INCDIR = ./includes/tyctest

INCS = -I ../submit -I $(LIBTYCTEST_INCDIR)
CFLAGS += -coverage -g -O0 -Wall -Wextra -Werror -MMD -MP $(INCS)
SRCS = $(shell find . -name "*_test.c")
OBJS = $(SRCS:.c=.o)
DEPENDS = $(SRCS:.c=.d)


all: $(NAME)

-include $(DEPENDS)

$(NAME): $(LIBTYCTESTMAIN) $(LIBTYCTEST) $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(INCS) -o $(NAME) $(OBJS) $(LIBS)

$(LIBFT): export CFLAGS := $(CFLAGS)
$(LIBFT): $(shell find ../submit -name "*.c")
	"$(MAKE)" --directory $(shell dirname $(LIBFT))

$(LIBTYCTEST) $(LIBTYCTESTMAIN) $(LIBTYCTEST_INCDIR):
	git clone git@github.com:PalmNeko/tyCtest_tool.git tyCtest_tool
	bash tyCtest_tool/install.sh
	rm -rf tyCtest_tool

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

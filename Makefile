# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atemfack <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/10 16:30:05 by atemfack          #+#    #+#              #
#*   Updated: 2020/12/09 21:13:21 by atemfack         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME = libasm.a 

SRCS = ft_strlen.s ft_strcpy.s ft_strcmp.s \
	 ft_write.s ft_read.s ft_strdup.s

OBJS = $(subst .s,.o,$(SRCS))

CC = nasm

CFLAGS = -f elf64

FLAGS = -Wall -Wextra -Werror

EXECUTABLE = exec

LIBASM_PATH := $(shell pwd)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $@ $^
	ranlib $(NAME)

%.o: %.s
	$(CC) $(CFLAGS) -o $@ $<

test: f
	gcc $(FLAGS) -L. -lasm -o $(EXECUTABLE) main.c test.c $(NAME)

test2: 
	@git clone https://github.com/cacharle/libasm_test.git ../_libasmtest
	@sed -i "s|../libasm|$(LIBASM_PATH)|" ../_libasmtest/Makefile
	@$(MAKE) -C ../_libasmtest
	@rm -rf ../_libasmtest

clean:
	/bin/rm -fr $(OBJS) $(EXECUTABLE)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

f: all clean

.PHONY: all clean fclean re f test test2

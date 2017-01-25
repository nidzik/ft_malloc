#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nidzik <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/25 19:13:45 by nidzik            #+#    #+#              #
#    Updated: 2017/01/25 19:28:20 by nidzik           ###   ########.fr        #
#                                                                              #
#******************************************************************************#




ifeq ($(HOSTTYPE),)
HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc.so


NAMEO = libft_malloc
NAMELK = $(NAMEO)_$(HOSTTYPE).so

# LIBFT
LFTPATH = libft/
LFTIPATH = -I $(LFTPATH)
LFT = -L $(LFTPATH) -lft


OBJPATH = obj
SRCPATH = .
INCLUDE = -I ./

# MLX
CC = gcc
#GRAPHLIB = -L/usr/X11/lib -lmlx -lXext -lX11 -framework openGl -framework AppKit
#GRAPHLIB = -lmlx -framework openGl -framework AppKit


LIBS = $(LFT) $(GRAPHLIB)
INCLUDES = $(INCLUDE) $(LFTIPATH) $(GRAPHINC)


BASEFLAGS = -Wall -Wextra
CFLAGS = $(BASEFLAGS) -Werror -O2 -g 


LFTCALL = all
LFTRE = re

SRCSFILES = malloc.c \
			init.c \
			block.c \
			ft_atoi_hex.c \
			show_alloc_mem.c \
			page.c \
			ft_free.c \
			realloc.c \

SRC = $(addprefix $(SRCPATH)/,$(SRCSFILES))
OBJECTS = $(SRC:$(SRCPATH)/%.c=$(OBJPATH)/%.o)

RM = rm -rf

Y = \033[0;33m
R = \033[0;31m
G = \033[0;32m
E = \033[39m

all: l $(NAME)

$(NAME): $(OBJECTS)
	ln -sf $(NAME) $(NAMELK)
	@echo "$(Y)[COMPILING MALLOC] $(G) $(CC) -o $@ $(CFLAGS) objs.o $(LIBS) $(E)"
	@$(CC) -shared -o $@ $(CFLAGS) -g $(OBJECTS) $(INCLUDES) $(LIBS)
	@echo "$(Y)[COMPILING MALLOC DONE]$(E)"

$(OBJECTS): $(OBJPATH)/%.o : $(SRCPATH)/%.c
	@mkdir -p $(dir $@)
	$(CC) -o $@ $(CFLAGS) $(INCLUDES) -c $<

clean:
	$(RM) $(OBJPATH)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAMELK)

l:
	@echo "$(Y)[COMPILING LIBFT] $(G) make -C $(LFTPATH) $(LFTCALL) $(E)"
	@make -C $(LFTPATH) $(LFTCALL)
	@echo "$(Y)[COMPILING LIBFT DONE]$(E)"

re: fclean all

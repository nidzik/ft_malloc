#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nidzik <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/11 10:34:54 by nidzik            #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2016/11/13 20:17:43 by nidzik           ###   ########.fr        #
=======
#    Updated: 2016/11/13 18:27:58 by bbichero         ###   ########.fr        #
>>>>>>> dacd471f465c71e585000113ff03b98fe6dd66f8
#                                                                              #
#******************************************************************************#

NAME = malloc

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

<<<<<<< HEAD

SRCSFILES = main.c \
			malloc.c \
			init.c \
			block.c \

=======
SRCSFILES = malloc.c\
			ft_atoi_hex.c\
			init.c
			
>>>>>>> dacd471f465c71e585000113ff03b98fe6dd66f8
SRC = $(addprefix $(SRCPATH)/,$(SRCSFILES))
OBJECTS = $(SRC:$(SRCPATH)/%.c=$(OBJPATH)/%.o)

RM = rm -rf

Y = \033[0;33m
R = \033[0;31m
G = \033[0;32m
E = \033[39m

all: l $(NAME)

$(NAME): $(OBJECTS)
	@echo "$(Y)[COMPILING MALLOC] $(G) $(CC) -o $@ $(CFLAGS) objs.o $(LIBS) $(E)"
	@$(CC) -o $@ $(CFLAGS) -g $(OBJECTS) $(INCLUDES) $(LIBS)
	@echo "$(Y)[COMPILING MALLOC DONE]$(E)"

$(OBJECTS): $(OBJPATH)/%.o : $(SRCPATH)/%.c
	@mkdir -p $(dir $@)
	$(CC) -o $@ $(CFLAGS) $(INCLUDES) -c $<

clean:
	$(RM) $(OBJPATH)

fclean: clean
	$(RM) $(NAME)

l:
	@echo "$(Y)[COMPILING LIBFT] $(G) make -C $(LFTPATH) $(LFTCALL) $(E)"
	@make -C $(LFTPATH) $(LFTCALL)
	@echo "$(Y)[COMPILING LIBFT DONE]$(E)"

re: fclean all

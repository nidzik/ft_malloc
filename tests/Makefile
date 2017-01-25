# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwalle <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/20 17:39:34 by jwalle            #+#    #+#              #
#    Updated: 2017/01/25 19:49:25 by nidzik           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# launch with LD_PRELOAD=./libft_malloc_x86_64_Darwin make 

LN = -I../libft/libft.h
INC = -L. -lft_malloc_x86_64_Darwin

all :
	make -C ../ re
	cp ../*.so .
	gcc test0.c -o test0 $(INC)
	gcc test1.c -o test1 $(INC)
	gcc test2.c -o test2 $(INC)
	gcc test3.c -o test3 $(INC)
	gcc test3bis.c -o test3bis $(INC)
	gcc test4.c -o test4 $(INC)
	gcc test5.c -o test5 $(INC)


clean :
	rm -rf test0 test1 test2 test3 test3bis test4 test5
	rm -rf *.so

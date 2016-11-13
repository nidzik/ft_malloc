/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 11:24:23 by nidzik            #+#    #+#             */
/*   Updated: 2016/11/13 18:20:34 by nidzik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
t_env		g_env;

void 		*mallocc(size_t size, t_page *p)
{
	size_t type;

	type = get_type(size);
	if (!p)
{
		printf("page do not exist\n");fflush(stdout);
		g_env.page = new_page(type);
}
	else if (p)
{
		printf("page exist \n");fflush(stdout);
		g_env.page->start = find_next_block(type);
}
	else 
		return(NULL);
	//  str = (void *)mmap((void *)0xA0000, size + 1, PROT_READ | PROT_WRITE, MAP_ANON |   MAP_PRIVATE, -1 , 0);
	return (NULL);
}

void		*find_next_block(size_t type)
{
	t_page p;
	while ()
p.start = start-
	while 
}

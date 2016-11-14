/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 11:24:23 by nidzik            #+#    #+#             */
/*   Updated: 2016/11/13 21:11:45 by nidzik           ###   ########.fr       */
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
		g_env.page->start = create_block(size, g_env.page->start);//p->start); not start find whart /
	}
	else if (p)
	{
		printf("page exist \n");fflush(stdout);
		return (create_block(size, g_env.page->start));//p->start);
/* 		if (p.full) */
/* 			g_env.page->next = find_next_page(type, p); */
	}
	else 
		return(NULL);
	return (g_env.page->start);
}

/* void		*find_next_page(size_t type, t_page *p) */
/* { */
/* 	t_page tmp; */

/* 	&tmp = p; */
/* 	while (!p->next) */
/* 	{ */
/* 		&tmp.start = p->next; */
/* 	} */
/* tmp.next  */

/* } */

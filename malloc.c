/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 11:24:23 by nidzik            #+#    #+#             */
/*   Updated: 2016/11/14 14:42:21 by nidzik           ###   ########.fr       */
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
/* 		printf("new page at %p \n", (g_env.page->start));fflush(stdout); */
		return (create_block(size, g_env.page->start));//p->start); not start find whart /
		printf("malloc at %p \n\n", (g_env.page->start));fflush(stdout);
		
	}
	else if (p)
	{
		printf("page exist  p->start : %p \n", p->start);fflush(stdout);
		return (create_block(size, p->start));//p->start);
/* 		if (p.full) */
/* 			g_env.page->next = find_next_page(type, p); */
	}
	else
	{
		ft_putendl("bug");
		return(NULL);
	}
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

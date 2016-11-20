/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 11:24:23 by nidzik            #+#    #+#             */
/*   Updated: 2016/11/20 16:51:51 by nidzik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
t_env		g_env;

void 		*mallocc(size_t size, t_page *p)
{
	size_t type;
//	t_page	*ptr;

	type = get_type(size);
	printf("\n%d\n", (int)type);fflush(stdout);
	if (!p)
	{
		printf("page do not exist %d \n", (int)type);fflush(stdout);
		if (type == 3)
		{
			ft_putchar('f');
			return( mmap(0, size, FLAGS));
		}
		else
			g_env.page = new_page(type);
		return (create_block(size, g_env.page->start));//p->start); not start find whart /
		printf("malloc at %p \n\n", (g_env.page->start));fflush(stdout);
	}
	else if (p)
	{
		printf("page exist  p->start : %p \n", p->start);fflush(stdout);
//		ptr = find_page(size);
		//	if (ptr.size == 0)
		return (create_block(size, find_page(size)));//p->start);
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

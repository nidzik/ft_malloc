/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 15:16:23 by nidzik            #+#    #+#             */
/*   Updated: 2016/11/23 23:00:43 by nidzik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		init_genv()
{
	t_page p;

	p.size = 0;
	p.full = 0;
	p.start = NULL;
	p.type = 0;
	p.next = NULL;
	g_env.page = &p;
	g_env.page = NULL;
	return ;
}

size_t		get_type(size_t size)
{
	if (size < TINY_SIZE)
		return (TINY);
	else if (size >= TINY_SIZE && size < SMALL_SIZE)
		return (SMALL);
	else
	{
// inset getrlimit
		return (LARGE);
	}
}

size_t		get_page_size_max(size_t type)
{
	if (type == TINY)
		return (PAGE_TINY_SIZE);
	if (type == SMALL)
		return (PAGE_SMALL_SIZE);
	return (0);
}

t_page		*new_page(size_t type)
{
	t_page *p;

	p = mmap(0, sizeof(p) + get_page_size_max(type), FLAGS);
	p->type = type;
	if (type == 1 || type == 2)
	{
		p->size = 0;
		p->full = 0;
		p->start =  p + sizeof(p);//mmap(0, get_page_size_max(type), FLAGS);
//		p->start = p->start + 1;
		p->next = NULL;
		printf("new page type %d created %p\nstart at %p\nto %p, size of %d\n",(int)type, p,p->start,p->start + get_page_size_max(type), (int)p->size);fflush(stdout);
	}
	return (p);
}

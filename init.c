/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 15:16:23 by nidzik            #+#    #+#             */
/*   Updated: 2017/01/25 20:12:50 by nidzik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		init_genv(void)
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

t_page		*new_page(size_t type, size_t size)
{
	t_page *p;

	if (type != 3)
	{
		p = mmap(0, sizeof(p) + get_page_size_max(type), FLAGS);
		p->type = type;
	}
	if (type == 1 || type == 2)
	{
		p->size = 0;
		p->full = 0;
		p->start = p + sizeof(p);
		p->next = NULL;
	}
	else
	{
		p = mmap(0, sizeof(p) + size + 24, FLAGS);
		p->type = type;
		p->size = 0;
		p->full = 1;
		p->start = p + sizeof(p);
		p->next = NULL;
	}
	return (p);
}

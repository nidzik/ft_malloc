/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 15:16:23 by nidzik            #+#    #+#             */
/*   Updated: 2016/11/13 17:01:12 by nidzik           ###   ########.fr       */
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
//	g_env.page = &p;
	g_env.page = NULL;
	printf("environement created\n");fflush(stdout);
}

size_t		get_type(size_t size)
{
	if (size < TINY_SIZE)
		return (TINY);
	else if (size >= TINY_SIZE && size < SMALL_SIZE)
		return (SMALL);
	else {
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
	static	t_page p;

	p.type = type;
	p.size = get_page_size_max(type);
	p.full = 0;
	p.start = mmap(0, p.size, FLAGS);
	p.next = p.start + sizeof(p) + 1;
	printf("new page created\n");fflush(stdout);
	return (&p);
}

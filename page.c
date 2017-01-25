/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   page.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 14:43:29 by nidzik            #+#    #+#             */
/*   Updated: 2017/01/25 20:33:41 by nidzik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_page		*putthis(size_t size, t_page *page, size_t type)
{
	if (page->type == type && page->full == 0)
	{
		if ((size_t)(page->size + size + 32) > \
			(size_t)(get_page_size_max(type)))
		{
			page->full = 1;
			page->next = new_page(type, size);
			page = page->next;
			page->size += size + 32;
			return (page->start);
		}
		else
		{
			page->size += size + 32;
			return (page->start);
		}
	}
	return (NULL);
}

t_page		*find_page(size_t size)
{
	size_t		type;
	t_page		*page;

	type = get_type(size);
	page = g_env.page;
	while (page)
	{
		if (page->type == type && page->full == 0)
		{
			return (putthis(size, page, type));
		}
		if (page->next)
			page = page->next;
		else
			break ;
	}
	page->next = new_page(type, size);
	page = page->next;
	page->size += size + 32;
	return (page->start);
}

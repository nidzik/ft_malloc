/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 11:24:23 by nidzik            #+#    #+#             */
/*   Updated: 2017/01/27 19:08:29 by nidzik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_env		g_env;

void		*malloc(size_t size)
{
	return (mallocc(size, g_env.page));
}

void		*mallocc(size_t size, t_page *p)
{
	size_t	type;

	type = get_type(size);
	if (!p)
	{
		g_env.page = new_page(type, size);
		g_env.page->size += size + 32;
		return (create_block(size, g_env.page->start));
	}
	else if (p)
		return (create_block(size, find_page(size)));
	else
		return (NULL);
	return (g_env.page->start);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 12:09:44 by nidzik            #+#    #+#             */
/*   Updated: 2017/01/28 12:18:43 by nidzik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		*super_fusion(t_header *header, t_header *next, \
							size_t ohsz, void *ptr)
{
	void		*end;
	t_header	*new_head;

	(void)ptr;
	if (header->size <= ohsz)
	{
		end = (void *)(header + 1) + header->size;
		new_head = end;
		new_head->size = ohsz - header->size - 24;
		new_head->next = next;
	}
	else if ((next->size - (header->size - ohsz) != 0))
	{
		end = (void *)header + 1 + header->size;
		new_head = end;
		new_head->size = next->size - (header->size - ohsz);
		new_head->next = next->next;
	}
	else
		return (header + 1);
	new_head->free = 1;
	header->next = new_head;
	header->free = 0;
	return (header + 1);
}

size_t		resize_size(size_t size)
{
	if (size % 16 != 0)
		size = (16 - (size % 16)) + size;
	return (size);
}

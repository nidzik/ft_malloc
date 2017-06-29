/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 19:11:17 by nidzik            #+#    #+#             */
/*   Updated: 2017/01/25 20:48:21 by nidzik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		*create_block(size_t size, void *start_page)
{
	t_header	*head;
	char		*next;

	head = start_page;
	while (head)
	{
		if (head->free == 1 && head->size >= size)
		{
			create_head(size, head, head->next);
			return (head + 1);
		}
		if (head->next)
			head = head->next;
		else
			break ;
	}
	if (head->size)
	{
		next = (char *)(head) + head->size + 32;
		head->next = (void *)next;
		head = head->next;
	}
	create_head(size, head, NULL);
	return (head + 1);
}

void		create_head(size_t size, t_header *head, t_header *next)
{
	if (size % 16 != 0)
		head->size = (16 - (size % 16)) + size;
	else
		head->size = size;
	head->free = 0;
	head->next = next;
}

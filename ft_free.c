/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 23:39:39 by nidzik            #+#    #+#             */
/*   Updated: 2017/01/27 20:16:20 by nidzik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void			free(void *ptr)
{
	t_page		*page;

	if (!ptr)
	{
		return ;
	}
	(page = find_page_free(g_env.page, ptr));
	(find_head_free(page, ptr));
	return ;
}

t_page			*find_page_free(t_page *page, void *ptr)
{
	t_page *psav;

	psav = NULL;
	if (page)
		while (page)
		{
			if (page->full == 1)
				free_page(page, psav);
			else
				psav = page;
			if (ptr > ((void *)page->start + page->size))
			{
				page = page->next;
			}
			else if (ptr >= (void *)page && \
					(ptr < ((void *)page->start) + page->size))
			{
				return (page);
			}
			else
				return (NULL);
		}
	return (NULL);
}

t_header		*find_head_free(t_page *page, void *ptr)
{
	t_header	*head;

	if (page)
	{
		head = page->start;
		while (head)
		{
			if (ptr >= (void *)head && ptr < ((void *)(head + 1) + head->size))
			{
				free_head(head, ptr);
				return (head);
			}
			head = head->next;
		}
	}
	return (NULL);
}

void			free_head(t_header *head, void *ptr)
{
	t_header	*tmp;

	(void)ptr;
	if (head)
	{
		if (head->next)
			tmp = head->next;
		head->free = 1;
		if (head->next)
		{
			tmp = head->next;
			if (tmp->free == 1)
				merge(head, tmp, ptr);
		}
	}
	return ;
}

void			merge(t_header *head, t_header *next, void *ptr)
{
	(void)ptr;
	head->size += next->size + 24;
	head->next = next->next;
	return ;
}

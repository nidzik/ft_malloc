/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 19:59:35 by nidzik            #+#    #+#             */
/*   Updated: 2017/01/27 21:06:38 by nidzik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void			*find_head(t_page *page, void *ptr)
{
	t_header	*head;

	if (page)
	{
		head = page->start;
		while (head)
		{
			if (ptr >= (void *)head && ptr < ((void *)(head + 1) + head->size))
				return (head);
			head = head->next;
		}
	}
	return (NULL);
}

void			*realloc(void *ptr, size_t size)
{
	t_page		*page;
	t_header	*header;
	void		*fresh_ptr;

	if (!ptr)
		return (ptr = mallocc(size, g_env.page));
	else if (!resize_size(size) && ptr)
	{
		free(ptr);
		ptr = mallocc(1, g_env.page);
		return (ptr);
	}
	else if (ptr && size)
	{
		page = find_page_free(g_env.page, ptr);
		header = find_head(page, ptr);
		if (header && header->free == 0)
		{
			fresh_ptr = check_size_ptr(header, resize_size(size), ptr);
			if (fresh_ptr != ptr)
				free(ptr);
			return (fresh_ptr);
		}
	}
	return (NULL);
}

void			*check_size_ptr(t_header *header, size_t size, void *ptr)
{
	void		*new_ptr;
	t_header	*next;

	if (header->size)
	{
		if (header->next)
			next = header->next;
		else
		{
			next = NULL;
			new_ptr = check_next_null(size, header, ptr);
			if (new_ptr)
				return (new_ptr);
		}
		new_ptr = check_next(size, header, ptr,next);
		if (new_ptr)
			return (new_ptr);
	}
	else if (header->size == size)
		return (ptr);
	return (NULL);
}

void			*check_next(size_t size, t_header *header, void *ptr, t_header *next)
{
	size_t		old_header_size;

	if (size <= header->size)
	{
		header->free = 0;
		return (ptr);
	}
	if ((next->free == 1 && size <= (next->size + header->size + 24)))
	{
		if (next->next)
			header->next = next->next;
		else
			header->next = NULL;
		old_header_size = header->size;
		header->size = size;
		header->free = 0;
		return (super_fusion(header, next, old_header_size, ptr));
	}
	else if (next->free == 0 || (size > (next->size + header->size)))
	{
		header->free = 1;
		return (mallocc(size, g_env.page));
	}
	return (NULL);
}

void		*check_next_null(size_t size, t_header *header, void *ptr)
{
	void	*ret;
	void	*sav;

	ret = NULL;
	sav = NULL;
	if (size >= header->size)
	{
		ret = mallocc(size, g_env.page);
		sav = ret;
		ft_memmove(sav, ptr, size);
		return (sav);
	}
	else if (size <= header->size - 32)
	{
		header->next = NULL;
		header->size = size;
		header->free = 0;
		ret = super_fusion(header, NULL, header->size, ptr);
	}
	return (ret);
}

void			*super_fusion(t_header *header, t_header *next, \
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

size_t			resize_size(size_t size)
{
	if (size % 16 != 0)
		size = (16 - (size % 16)) + size;
	return (size);
}

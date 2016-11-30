/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 19:59:35 by nidzik            #+#    #+#             */
/*   Updated: 2016/11/30 21:16:47 by nidzik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	       *find_head(t_page *page, void *ptr)
{
	t_header   *head;

	if (page)
	{
		head = page->start;
		while (head)
		{
			printf("head %p  to %p , ptr : %p\n",head, ((void *)head +sizeof(head) + head->size), ptr);
			if (ptr >= (void *)head && ptr < ((void *)(head + 1) + head->size))
			{
				ft_putendl("find");
				return (head);}
			head = head->next;
		}
	}
	return NULL;
}

void		*realloc(void *ptr, size_t size)
{
	t_page		*page;
	t_header	*header;
	void		*fresh_ptr;
	ft_putendl("STARTING REALLOC");
	size = resize_size(size);
	if (!ptr)
	{
		ft_putendl("no ptr go to mall(size)");
		return (ptr = mallocc(size, g_env.page));
	}
	else if (!size && ptr)
	{
		ft_putendl("!size && ptr go to mall(1)");
		free(ptr);
		ptr = mallocc(1, g_env.page);
		return (ptr);
	}
	else if (ptr && size)
	{
		ft_putendl("go ti reall");
		page = find_page_free(g_env.page, ptr);
		header = find_head(page, ptr);
		if (header == NULL || header->free == 1)
			return NULL;
		else 
		{
			fresh_ptr = check_size_ptr(header, size, ptr);
	ft_putendl("haphap");
	printf("\n%p  %p \n", ptr, fresh_ptr);fflush(stdout);
/* 			free(ptr); */
			ft_putnbr(header->free);
			return (fresh_ptr);
		}
	}
	else
	{
		ft_putendl("realloc failed for unknow reason");
		return (NULL);
	}

	return(NULL);
}

void			*check_size_ptr(t_header *header, size_t size, void *ptr)
{
	(void)ptr;
	void 	*new_ptr;

	ft_putendl("check_size_ptr");
 	if (header->size )
	{
	ft_putendl("check_head_size");
	new_ptr = check_next(size, header);
/* 	free(ptr); */
/* 			printf("\n\n\n\nssssssssssss%d",new_ptr->free); */
		if (new_ptr)
			return (new_ptr);
	}
/* 	else if (header->size > size)// ou sup a size +sizeof(head) + 4; */
/* 	{ */
/* 	ft_putendl("superfus rm > ptr"); */
//superfusion
/* 	} */
	else if (header->size == size)
		return (ptr);
	return (NULL);
}

void 			*check_next(size_t size, t_header *header)
{
	t_header 	*next ;
	size_t 		old_header_size;

	ft_putendl("check_next");
	if (header->next)
	{
		ft_putendl("yes");
		next = header->next;
		//		next->free = 1;
//			ft_putnbr(next->free);
		ft_putendl("yes");
	}
	else 
	{
		next = NULL;
		ft_putendl("ololol");
	}
	/*if (next->free == 1 && size < (next->size + size) && (header->size + next->size) <= (size + sizeof(header) + 4))
	{
	ft_putendl("if1");
		if (next->next)
			header->next = next->next;
		else
			header->next = NULL;
		header->size = size;
		header->free = 0;
		}*/

		
	if ((next->free == 1 && size <= (next->size + header->size + 24)) || size <= header->size)// && (header->size + next->size + 16) > (size))
	{
	ft_putendl("if2");
		if (next->next)
			header->next = next->next;
		else
			header->next = NULL;
		old_header_size = header->size;
		header->size = size;
		header->free = 0;
		return (super_fusion(header, next, size, old_header_size));
	}
	else if (next->free == 0 || (size > (next->size + header->size))){
		ft_putendl("if3");
		ft_putnbr(size);
		header->free = 1;
//		free(header+1);
		return (mallocc(size, g_env.page));}
	return (NULL);
}

void 			*super_fusion(t_header *header, t_header *next, size_t size, size_t old_header_size)
{
	void 		*end;
	t_header 	*new_head;

	if (size <= old_header_size)
	{
/* 		if (size < (size + old_header_size + 32 )) */
/* 			fusion_la_fusion() */
		end = (void *)(header + 1) + size;
		new_head = end;
		new_head->size = old_header_size - size - 24;
		new_head->next = next;
		printf("\n\n\n\n 1 head->size : %lu   sizze : %lu   new : %d    %lu \n",header->size, size, header->free, old_header_size);
	}
	else if ((next->size - (size - old_header_size) != 0))
	{

		end = (void *)header + 1 + header->size;
		new_head = end;
		new_head->size = next->size - (size - old_header_size);

		printf("\n\n\n\n 2 head->size : %lu   sizze : %lu   new : %lu   %lu",header->size, size, new_head->size, old_header_size);
		new_head->next = next->next; 

	}
		else 
			return (header +1);
	new_head->free = 1;
/* 	new_head->next = next->next;  */
//(void *)new_head + 1 + next->size;
	header->next = new_head;
	header->free = 0;
	show_alloc_mem();
	return (header + 1);
}


size_t 		resize_size(size_t size)
{
	if (size % 16 != 0)
		size = (16 -(size % 16) ) + size ;
	ft_putendl("HEEEEEEEEEERE");
	ft_putnbr(size);
	return (size);
}

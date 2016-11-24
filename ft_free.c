/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 23:39:39 by nidzik            #+#    #+#             */
/*   Updated: 2016/11/23 22:59:30 by nidzik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void        free(void *ptr)
{
    t_header	*header;
	t_page		*page;

	page = g_env.page;
	if (!ptr)
		return ;
	if ((page = find_page_free(page, ptr)) == NULL)
		return ;
	if ((header = find_head_free(page, ptr)) == NULL)
		return ;
    // Check if header and page exist
/*     if (ptr && ft_page(page) && ft_header(header)) */
/*     { */
/*         pthread_mutex_lock(&g_lock); // Lock mutex before use it */



/*         pthread_mutex_unlock(&g_lock); // Unlock mutex to let it use by other process */
/*     } */
/*     header->free = 1; */
}

t_page 			*find_page_free(t_page *page, void *ptr)
{

	if (page)
		while (page)
		{
			printf("\n\npage : %p    %p  ptr : %p   pstart+=psize %p   size : %d \n\n", page,((void *) page + sizeof(t_page)),ptr,(void *)page->start + page->size, (int)page->size );fflush(stdout);
			if (ptr > ((void *)page->start + page->size)){ft_putchar('a');
				page = page->next;}
			else if (ptr >= (void *)page && (ptr < ((void *)page->start) + page->size)){ft_putchar('b');
				return (page);}
			else 
				return (NULL);
		}
	return NULL;
}

t_header		*find_head_free(t_page *page, void *ptr)
{
	t_header	*head;
	ft_putendl("wdljqhwdkuhqkuhqkwdh");
		//while (page)
	if (page)
	{
		//ft_putendl("a");
		head = page->start;
		while (head)
		{
			printf("head+1 %p , ptr : %p\n",((void *)head +1 + head->size), ptr);
			if (ptr >= (void *)head && ptr <= ((void *)head +1 + head->size))
			{
				free_head(head, ptr);
				return NULL;
			}
			head = head->next;
		}
	}
		return NULL;
	}


void		free_head(t_header *head, void *ptr)
{
	t_header	*tmp;

	if (head)
	{
		head->free = 1;
		munmap(ptr, head->size);
		ft_putnbr(head->size);
		ft_putendl("freed");
		if (head->next)
		{
			tmp = head->next;
			if (tmp->free == 1 )
				ft_putendl("rdy to merge");
			else
				ft_putendl("next not free");
		}
	}
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 23:39:39 by nidzik            #+#    #+#             */
/*   Updated: 2017/01/25 00:57:43 by nidzik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void        free(void *ptr)
{
    t_header	*header;
	t_page		*page;


	if (!ptr)
		return ;
	(void)header;
	(page = find_page_free(g_env.page, ptr)) ;
	(find_head_free(page, ptr)) ;
	ft_putchar('\n');
/* 	ft_putnbr(header->free); */
	ft_putendl("endfree");
	return ;
/* 	if ((page = find_page_free(page, ptr)) == NULL) */
/* 		return ; */
/* 	if ((header = find_head_free(page, ptr)) == NULL) */
/* 		return ; */
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
	ft_putendl("start find_page_free");
	printf("page %p   ptr : %p\n", page , ptr);
	if (page)
		while (page)
		{
//			printf("\n\npage : %p    %p  ptr : %p   pstart+=psize %p   size : %d \n\n", page,((void *) page + sizeof(t_page)),ptr,(void *)page->start + page->size, (int)page->size );fflush(stdout);
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
			//	printf(" h : %p  h+1 %p,*h %p,  h+sof %p,  head+1 %p , ptr : %p   %lu  next : %p\n",head, (void *)head, (head + 1), (void *)head + sizeof(head),(void*)(head +1)  + head->size, ptr, head->size, head->next);fflush(stdout);
			if (ptr >= (void *)head && ptr < ((void *)(head +1) + head->size))
			{
				ft_putendl("ggufoubndit");
				printf("  %p \n",head->next);fflush(stdout);
				free_head(head, ptr);
//				page->size -= head->size + 32;
				//ft_putnbr(head->free);
				return (head);
			}
			head = head->next;
		}
		ft_putendl("not found ");
	}
		ft_putendl("page null while search for head to free");
	return NULL;
}


void		free_head(t_header *head, void *ptr)
{
	t_header	*tmp;
	ft_putendl("entering free_head");
	if (head)
	{
		ft_putendl("1");
		(void)ptr;
		if (head->next)
		{
		ft_putendl("2");
			tmp = head->next;
			//printf("\nyolo  here->%lu  next->%lu", head->size, tmp->size);fflush(stdout);		
		}

		head->free = 1;
//		ft_putnbr(head->size);		
		ft_putendl("freed");
		printf("  %p \n",head->next);
		if (head->next == NULL )
		{
			ft_putendl ("before numap ");
			munmap(ptr, head->size);
			ft_putendl ("numap done ");
		}
		else if (head->next)
		{
			ft_putendl(":ooooooooooooO");
			tmp = head->next;
			if (tmp->free == 1 )
				merge(head, tmp, ptr);
/* 				ft_putendl("rdy to merge"); */
			else
				ft_putendl("next not free");
		}
		ft_putendl("freed anyway");
	}
		ft_putendl("4");
	return ;
}

void 		merge(t_header *head, t_header *next, void *ptr)
{

	head->size += next->size + 24;
	head->next = next->next;
	munmap(ptr, head->size);
	ft_putendl("merge ok.");
	return ;
}

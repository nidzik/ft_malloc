/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 19:11:17 by nidzik            #+#    #+#             */
/*   Updated: 2017/01/25 05:46:50 by nidzik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		*create_block(size_t size, void *start_page)
{
	t_header 	*head;
	char		*next;
	t_page *page;

/* 	static int h = 0; */

	head = start_page;
	page =(void * )( (char *)(head) - sizeof(page) + 8);
	printf("   youlou%p \n",page);fflush(stdout);
	while (head)
	{
		
		//printf("search for next head avalible checking : %p, head-next : %p \n",head, head->next ); fflush(stdout);
		if (head->free == 1 && head->size >= size)
		{
			//		printf("head free and > size\n");fflush(stdout);
			create_head(size, head , head->next);
			return (head + 1);
		}
		if (!head->next )
			ft_putendl("NULL");
/* 		printf("end while in create block before head %p = next %p \n", head, head->next);fflush(stdout); */
		if (head->next)
			head = head->next; 
		else 
			break;
	}
	if (head->size)
	{
		ft_putendl("atf NULL condition head->size");
		next = (char *)(head) + head->size + 32;
		head->next = (void *)next;
/* 		printf("header->size  start at %p end at %p  test : %p\n",head ,head->next,  head + head->size );fflush(stdout); */
		head = head->next;
ft_putendl("end atf ");
		}
/* 	printf("no head avalible found\n");fflush(stdout); */
	create_head(size, head, NULL);
//	page->size += head->size + sizeof(head);
//	printf(" page : %p \n",page);fflush(stdout);
	printf("head : %p   head + sizeof head : %p \n",head, head + sizeof(head));fflush(stdout);
	printf("head + 1 = %p   head->next : %p \n\n\n",head + 1, head->next);fflush(stdout);
	printf("\n\n SIZEOF %lu HEAD \n\n",sizeof(head));fflush(stdout);
	
	return (head + 1);
}

void		create_head(size_t size, t_header *head, t_header *next)
{
	printf("-> size %lu", size);fflush(stdout);
	if (size % 16 != 0)
		head->size = (16 -(size % 16) ) + size ;
	else 
	{	ft_putendl("hh");fflush(stdout);
		head->size = size;
	ft_putendl("hh");fflush(stdout);
}
/* 	printf("\n\n SIZEOF %lu HEAD \n\n",sizeof(head));fflush(stdout); */
	ft_putendl("hh");fflush(stdout);
	head->free = 0;
	head->next = next;
	printf("creating header at %p \nhstart : %p/!\\ headsizeof+size : %p \n", head, head + sizeof(head), (void *)head + sizeof(head) + size );fflush(stdout);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 11:55:25 by nidzik            #+#    #+#             */
/*   Updated: 2017/01/27 21:20:41 by nidzik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <mach/vm_statistics.h>
# include "libft/libft.h"
# include <sys/mman.h>
# include <stdio.h>
# include <string.h>
# include <pthread.h>

# define FLAGS_PROT		PROT_READ | PROT_WRITE
# define FLAGS_MAP 		MAP_ANON | MAP_PRIVATE
# define FLAGS 			FLAGS_PROT ,FLAGS_MAP, -1, 0

# define TINY			1
# define SMALL			2
# define LARGE			3

# define PAGE_SIZES 	getpagesize()

# define TINY_SIZE 		(size_t) (PAGE_SIZES)
# define SMALL_SIZE 	(size_t) (PAGE_SIZES * 20)

# define PAGE_TINY_SIZE	TINY_SIZE * 100
# define PAGE_SMALL_SIZE 	SMALL_SIZE * 100

# define PHEXA(...) 	ft_atoi_hex(ret)

typedef struct			s_page
{
	size_t				size;
	int					full;
	void				*start;
	size_t				type;
	void				*next;
}						t_page;

typedef struct			s_header
{
	size_t				size;
	int					free;
	void				*next;
}						t_header;

typedef struct			s_env
{
	t_page				*page;
	int					set;
}						t_env;

extern t_env			g_env;

pthread_mutex_t			g_lock;

void					show_alloc_mem();
void					ft_header_info(void *header, size_t size);
void					ft_atoi_hex(void *ptr);

void					*malloc(size_t size);
void					*mallocc(size_t size, t_page *p);

void					init_genv();
size_t					get_type(size_t size);
t_page					*new_page(size_t type, size_t size);
void					*create_block(size_t size, void *start_page);
void					create_head(size_t size, t_header *head,\
									t_header *next);
t_page					*find_page(size_t type);

size_t					get_page_size_max(size_t type);

void					free(void *ptr);
t_page					*find_page_free(t_page *page, void *ptr);
t_header				*find_head_free(t_page *page, void *ptr);
void					free_head(t_header *head, void *ptr);
void					merge(t_header *head, t_header *next, void *ptr);
void					free_page(t_page *p, t_page *prev);

void					*find_head(t_page *page, void *ptr);
void					*check_size_ptr(t_header *header, size_t size,\
										void *ptr);
void					*check_next(size_t size, t_header *header, void *ptr,\
															t_header *next);
void					*realloc(void *ptr, size_t size);
void					*super_fusion(t_header *header, t_header *next,\
								size_t ohsz, void *ptr);
size_t					resize_size(size_t s);
void					*check_next_null(size_t size, t_header *header,\
									void *ptr);

#endif

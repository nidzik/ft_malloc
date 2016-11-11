/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 11:55:25 by nidzik            #+#    #+#             */
/*   Updated: 2016/11/11 12:18:20 by nidzik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mach/vm_statistics.h>
#include "libft/libft.h"
#include <sys/mman.h>
#include <stdio.h>
#include <string.h>

void *mallocc(size_t size);

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 19:59:23 by nidzik            #+#    #+#             */
/*   Updated: 2017/01/25 20:00:21 by nidzik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void					ft_atoi_hex(void *ptr)
{
	char				*base;
	unsigned long long	address;
	char				hex[10];
	int					i;

	base = "0123456789abcdef";
	address = (unsigned long long)ptr;
	ft_bzero(hex, 10);
	i = 8;
	while (address)
	{
		hex[i] = base[address % 16];
		address = address / 16;
		i--;
	}
	ft_putstr("0x");
	ft_putstr(hex);
}

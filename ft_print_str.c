/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:17:42 by molapoug          #+#    #+#             */
/*   Updated: 2025/05/06 17:32:15 by molapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putcharp(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstrp(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		count += ft_putcharp(str[i]);
		i++;
	}
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <molapoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 18:09:10 by molapoug          #+#    #+#             */
/*   Updated: 2025/04/13 17:43:49 by molapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbrp(int nbr)
{
	long    nb;
	unsigned int	i;

	nb = nbr;
	i = 0;
	if (nb < 0)
	{
		i += ft_putcharp('-');
		nb = -nb;
	}
	if (nb >= 10)
		i += ft_putnbrp(nb / 10);
	i += ft_putcharp(nb % 10 + '0');
	return (i);
}

int	ft_putnbrpi(long nb)
{
	unsigned int	i;

	i = 0;
	/*if (nb < 0)
	{
		i += ft_putcharp('-');
		nb = -nb;
	}*/
	if (nb >= 10)
		i += ft_putnbrpi(nb / 10);
	i += ft_putcharp(nb % 10 + '0');
	return (i);
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

int	ft_putcharp(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr_base(unsigned long nbr, char *base)
{
	char	buf[16];
	int		i;
	int		count;

	i = 15;
	count = 0;
	if (!base)
		return (count);
	while (nbr > 0 || i == 15)
	{
		buf[i] = base[nbr % 16];
		nbr /= 16;
		i--;
	}
	count += write(1, "0x", 2);
	while (++i < 16)
		count += ft_putcharp(buf[i]);
	return (count);
}

int	ft_base16(char *str)
{
	int	count;

	count = ft_putnbr_base((unsigned long)str, "0123456789abcdef");
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <molapoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:56:01 by molapoug          #+#    #+#             */
/*   Updated: 2025/04/14 15:52:33 by molapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			i++;
			if (str[i] == 's')
				count += ft_putstrp(va_arg(args, char *));
			else if (str[i] == 'c')
				count += ft_putcharp(va_arg(args, int));
			else if (str[i] == 'd')
				count += ft_putnbrp(va_arg(args, int));
			else if (str[i] == 'p')
				count += ft_base16(va_arg(args, char *));
			else if (str[i] == 'i')
				count += ft_putnbrpi(va_arg(args, int));
		}
		else
			count += ft_putcharp(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}

int	main(void)
{
	void	*ptr;

	ptr = (void *)"42";
	ft_printf("%s%d\n", "je test mes fonctions : ", 42);
	printf("%s%d\n", "je test mes fonctions : ", 42);
	printf("%c\n", 'j');
	ft_printf("%c\n", 'j');
	printf("%p\n", ptr);
	ft_printf("%p\n", ptr);
	printf("%i\n", 34);
	ft_printf("%i\n", 34);
}

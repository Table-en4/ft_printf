/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <molapoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:09:10 by molapoug          #+#    #+#             */
/*   Updated: 2025/04/13 17:51:18 by molapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <unistd.h>
#include <stdarg.h>
#include <limits.h>

/* toutes les fonctions int*/
int     ft_putnbrp(int nbr);
int     ft_putstrp(char *str);
int     ft_putcharp(char c);
int	    ft_putnbr_base(unsigned long nbr, char *base);
int	    ft_base16(char *str);
int     ft_putnbrpi(long nb);
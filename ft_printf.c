/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <molapoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:56:01 by molapoug          #+#    #+#             */
/*   Updated: 2025/04/13 17:56:04 by molapoug         ###   ########.fr       */
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
	ft_printf("%i\n", -123); // error output : 0 result -123
	printf("%i\n", -123);
	// Test 1 : Test avec une adresse mémoire valide
	int x = 42;
	ft_printf("Adresse de x : %p\n", &x);
	printf("Adresse de x : %p\n", &x);

	// Test 2 : Test avec un entier négatif
	ft_printf("%i\n", -987);
	printf("%i\n", -987);

	// Test 3 : Test avec un pointeur NULL
	ft_printf("Pointeur NULL : %p\n", NULL);
	printf("Pointeur NULL : %p\n", NULL);

	// Test 4 : Test avec un entier égal à zéro
	ft_printf("%i\n", 0);
	printf("%i\n", 0);

	// Test 5 : Test avec des entiers limites
	ft_printf("Limite basse : %i, Limite haute : %i\n", INT_MIN, INT_MAX);
	printf("Limite basse : %i, Limite haute : %i\n", INT_MIN, INT_MAX);

	// Test 6 : Test avec des entiers multiples
	ft_printf("Entiers : %i, %i, %i\n", 1, -2, 3);
	printf("Entiers : %i, %i, %i\n", 1, -2, 3);

	// Test 7 : Test avec un pointeur sur une fonction
	void (*func)(void) = NULL;
	ft_printf("Pointeur sur fonction : %p\n", func);
	printf("Pointeur sur fonction : %p\n", func);

	// Test 8 : Test avec des valeurs aléatoires pour des entiers
	ft_printf("Entiers aléatoires : %i et %i\n", rand() % 100, rand() % -100);
	printf("Entiers aléatoires : %i et %i\n", rand() % 100, rand() % -100);

	// Test 9 : Test avec un tableau et un pointeur vers son premier élément
	int tab[3] = {10, 20, 30};
	ft_printf("Pointeur du tableau : %p\n", tab);
	printf("Pointeur du tableau : %p\n", tab);

	// Test 10 : Test avec une variable locale
	int local_var = 123;
	ft_printf("Pointeur variable locale : %p\n", &local_var);
	printf("Pointeur variable locale : %p\n", &local_var);

}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:53:31 by tlemos-m          #+#    #+#             */
/*   Updated: 2022/11/15 11:55:12 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check_var(char c, va_list args)
{
	if (c == 'c')
		ft_putchar(args);
	else if (c == 's')
	{
		ft_putstr(args);
	}
	else if (c == 'p')
	{
		write(1, "0x", 2);
	}
	else if (c == 'd' || c == 'i')
		ft_putnbr_base(args, "0123456789");
	else if (c == 'u')
		ft_putnbr_base((unsigned int)args, "0123456789");
	else if (c == 'x')
		ft_putnbr_base((unsigned int)args, "0123456789abcdef");
	else if (c == 'X')
		ft_putnbr_base((unsigned int)args, "0123456789ABCDEF");
	else if (c == '%')
		ft_putchar(c);
	return ;
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;

	va_start(args, s);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			i++;
			check_var(s[i], args);
		}
		else
			ft_putchar(s[i]);
		i++;
	}
	va_end(args);
}

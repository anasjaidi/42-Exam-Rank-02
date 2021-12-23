/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajaidi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 17:52:09 by ajaidi            #+#    #+#             */
/*   Updated: 2021/12/23 17:59:38 by ajaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	len;

	len = 0;
	if (!str)
		str = "(null)";
	while (*str)
		len += write(1, str++, 1);
	return (len);
}

int	ft_putnbr(int nb)
{
	long	n;
	int	len;

	len = 0;
	n = nb;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		len += ft_putchar(n + 48);
	return (len);
}

int	ft_puthex(unsigned int n)
{
	int	len;

	len = 0;
	if (n > 15)
	{
		ft_puthex(n / 16);
		ft_puthex(n % 16);
	}
	else if (n > 9)
		len += ft_putchar(n + 87);
	else
		len += ft_putchar(n + 48);
	return (len);
}

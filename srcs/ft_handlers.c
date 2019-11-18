/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <llaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:12:14 by llaurent          #+#    #+#             */
/*   Updated: 2019/11/18 14:48:58 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	ft_putchar_count(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

void	ft_putnbr_count(int nb, int *count)
{
	unsigned int	a;

	a = (nb < 0) ? -nb : nb;
	(nb < 0) ? ft_putchar_count('-', count) : 0;
	(a > 9) ? ft_putnbr_count((int)(a/10), count) : 0;
	ft_putchar_count(a % 10 + '0', count);
}

void	ft_putnbr_unsigned_count(unsigned int nb, int *count)
{
	unsigned int	a;

	a = (nb < 0) ? -nb : nb;
	(nb < 0) ? ft_putchar_count('-', count) : 0;
	(a > 9) ? ft_putnbr_count((unsigned int)(a/10), count) : 0;
	ft_putchar_count(a % 10 + '0', count);
}

void	ft_putstr_count(char *str, int *count)
{
	int	index;

	index = 0;
	while (str[index])
	{
		write(1, &str[index++], 1);
		(*count)++;
	}
}

void	ft_puthexa_count(long int nb, int *count, arg_param *arg)
{
	unsigned long int	a;
	char				*base;

	base = (arg->conv == 'X') ? "0123456789ABCDEF" : "0123456789abcdef";
	if (arg->flag == '#' || arg->conv =='p')
	{
		ft_putstr_count("0x", count);
		arg->flag = 0;
		arg->conv = (arg->conv == 'p') ? 'x' : arg->conv ;
	}
	a = (nb < 0) ? -nb : nb;
	(nb < 0) ? ft_putchar_count('-', count) : 0;
	(a >= 16) ? ft_puthexa_count((long int)(a/16), count, arg) : 0;
	ft_putchar_count(base[a % 16], count);
}

void	ft_putoctal_count(int nb, int *count)
{
	unsigned int	a;
	char			*base;

	base = "01234567";
	a = (nb < 0) ? -nb : nb;
	(nb < 0) ? ft_putchar_count('-', count) : 0;
	(a >= 8) ? ft_putoctal_count((int)(a/8), count) : 0;
	ft_putchar_count(base[a % 8], count);
}


void	ft_putfloat_count(double nb, int *count, arg_param *arg)
{
	unsigned int	a;

	a = (nb < 0) ? -nb : nb;
	(nb < 0) ? ft_putchar_count('-', count) : 0;
	(a > 9) ? ft_putfloat_count((double)(a/10), count, arg) : 0;
	ft_putchar_count(a % 10 + '0', count);
	if ((nb = nb - (double)a) > 0)
	{
		ft_putchar_count('.', count);
		while (arg->width2-- > 0)
			nb = nb * 10;
		ft_putnbr_count((int)(nb), count);
    }
}

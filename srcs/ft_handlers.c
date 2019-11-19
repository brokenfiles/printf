/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <llaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:12:14 by llaurent          #+#    #+#             */
/*   Updated: 2019/11/19 15:20:51 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int		get_nbr_length(unsigned int nb)
{
	unsigned int	index;

	index = 0;
	while (nb >= 10)
	{
		nb /= 10;
		index++;
	}
	return (index + 1);
}

void	ft_putchar_count(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

void	ft_putnbr_count(long int nb, int *count, arg_param *param)
{
	unsigned int	a;
	int 			index;
	int 			pre_cpy;
	int 			width_cpy;

	a = (nb < 0) ? -nb : nb;
	pre_cpy = param->precision;
	width_cpy = param->width2;
	index = 0;
	while ((param->width2) > 0)
	{
		if (index < (width_cpy - get_nbr_length(a) + (nb < 0 ? -1 : 0) - (pre_cpy > 0 ? pre_cpy - get_nbr_length(a) : 0)))
		{
			index++;
			ft_putchar_count(' ', count);
		}
		param->width2--;
	}
	index = 0;
	param->width2 = 0;
	(nb < 0) ? ft_putchar_count('-', count) : 0;
	while ((param->precision) > 0)
	{
		if (index < (pre_cpy - get_nbr_length(a)))
		{
			index++;
			ft_putchar_count('0', count);
		}
		param->precision--;
	}
	param->precision = 0;
	(a > 9) ? ft_putnbr_count((int)(a/10), count, param) : 0;
	ft_putchar_count(a % 10 + '0', count);
}

void	ft_putstr_count(char *str, int *count, arg_param *param)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (param->precision > 0)
		{
			if (index < param->precision)
				write(1, &str[index], 1);
		}
		else
			write(1, &str[index], 1);
		(*count)++;
		index++;
	}
}

void	ft_puthexa_count(long int nb, int *count, arg_param *arg)
{
	unsigned long int	a;
	char				*base;

	base = (arg->conv == 'X') ? "0123456789ABCDEF" : "0123456789abcdef";
	if (arg->flag == '#' || arg->conv =='p')
	{
		ft_putstr_count("0x", count, arg);
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
	//int 			index;
	//int 			pre_copy;

	base = "01234567";
	//index = 0;
	a = (nb < 0) ? -nb : nb;
	(nb < 0) ? ft_putchar_count('-', count) : 0;
	//pre_cpy = param->precision;
	//param->precision = 0;
	(a >= 8) ? ft_putoctal_count((int)(a/8), count) : 0;
	ft_putchar_count(base[a % 8], count);
}

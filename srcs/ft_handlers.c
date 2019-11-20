/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handlers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <llaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:12:14 by llaurent          #+#    #+#             */
/*   Updated: 2019/11/20 13:12:48 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	ft_putchar_count(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

void	ft_putchar_buff(char **buffer, int c)
{
	ft_strjoin_c(buffer, c);
}

void	ft_putnbr_buff(char **buffer, int nb)
{
	unsigned int	a;

	a = (nb < 0) ? -nb : nb;
	(nb < 0) ? ft_strjoin_c(buffer, '-') : 0;
	(a > 9) ? ft_putnbr_buff(buffer, (int)(a/10)) : 0;
	ft_strjoin_c(buffer, a % 10 + '0');
}

void	ft_putnbr_u_buff(char **buffer, unsigned int nb)
{
	(nb > 9) ? ft_putnbr_u_buff(buffer, (unsigned int)(nb/10)) : 0;
	ft_strjoin_c(buffer, nb % 10 + '0');
}

void	ft_putstr_buff(char **buffer, char *str)
{
	int	index;

	index = 0;
	while (str[index])
		ft_strjoin_c(buffer, str[index++]);
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

void	ft_putstr_count_number(char *str, int *count, int n)
{
	int	index;

	index = 0;
	while (str[index] && index < n)
	{
		write(1, &str[index++], 1);
		(*count)++;
	}
}

void	ft_puthexa_buff(char **buffer, long int nb, arg_param *arg)
{
	unsigned long int	a;
	char				*base;

	base = (arg->conv == 'X') ? "0123456789ABCDEF" : "0123456789abcdef";
	if (arg->conv =='p')
	{
		ft_putstr_buff(buffer, "0x");
		arg->conv = (arg->conv == 'p') ? 'x' : arg->conv ;
	}
	a = (nb < 0) ? -nb : nb;
	(nb < 0) ? ft_strjoin_c(buffer, '-') : 0;
	(a >= 16) ? ft_puthexa_buff(buffer, (long int)(a/16), arg) : 0;
	ft_strjoin_c(buffer, base[a % 16]);
}

void	ft_putoctal_buff(char **buffer, int nb)
{
	unsigned int	a;
	char			*base;

	base = "01234567";
	a = (nb < 0) ? -nb : nb;
	(nb < 0) ? ft_putchar_buff(buffer, '-') : 0;
	(a >= 8) ? ft_putchar_buff(buffer, (int)(a/8)) : 0;
	ft_putchar_buff(buffer, base[a % 8]);
}
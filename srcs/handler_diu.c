/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_diu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <llaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:18:26 by llaurent          #+#    #+#             */
/*   Updated: 2019/11/20 13:03:03 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void handle_u(char *buffer, arg_param *arg, int *count, int i)
{
	if (arg->width1 < 0)
	{
		arg->width1 = -arg->width1;
		arg->flag = '-';
	}
	if (arg->flag != '-' && arg->width1 && ((arg->width2 > 0 && arg->flag == '0') || arg->flag != '0'))
		padding(' ', arg->width1 - ((arg->width2 > i) ? arg->width2 : i), count);
	if (arg->flag != '-' && !arg->width2 &&
		((arg->width2 < i && arg->width2) || (arg->width2 == 0 && arg->flag == '0')))
		padding('0', arg->width1 - ((arg->width2 > i) ? arg->width2 : i), count);
	else if (arg->width2 > 0)
		padding('0', arg->width2 - i, count);
	if (!(buffer[0] == '0' && arg->precision == '.'))
		ft_putstr_count(buffer, count, 0);
	else if (arg->width1 && arg->width2 && arg->precision == '.')
		ft_putchar_count('0', count);
	else
		i--;
	if (arg->width1 && arg->flag == '-')
		padding(' ', arg->width1 - ((arg->width2 > i) ? arg->width2 : i), count);
}

void handle_di(char *buffer, arg_param *arg, int *count, int i)
{
	int neg;

	neg = 0;
	if (buffer[0] == '-')
	{
		buffer++;
		if (arg->precision == '.')
			i--;
		neg = 1;
	}
	if (arg->width1 < 0)
	{
		arg->width1 = -arg->width1;
		arg->flag = '-';
	}
	if (arg->flag != '-' && arg->width1 > 0 && ((arg->width2 > 0 && arg->flag == '0') || arg->flag != '0'))
		padding(' ', arg->width1 - ((arg->width2 > i) ? arg->width2 + neg : i), count);
	if (neg == 1)
		ft_putchar_count('-', count);
	if (arg->flag != '-' && !arg->width2 && ((arg->width2 < i && arg->width2) || (arg->width2 == 0 && arg->flag == '0')))
		padding('0', arg->width1 - ((arg->width2 > i) ? arg->width2 : i),count);
	else if (arg->width2 > 0)
		padding('0', arg->width2 - i, count);
	if (!(buffer[0] == '0' && arg->precision == '.'))
		ft_putstr_count(buffer, count, 0);
	else if (arg->width1 && arg->width2 &&arg->precision == '.')
		ft_putchar_count('0', count);
	else
		i--;
	if (arg->width1 && arg->flag == '-')
		padding(' ', arg->width1 - ((arg->width2 > i) ? arg->width2 + neg : i + neg), count);
}

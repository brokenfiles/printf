/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_pxX.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <llaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:18:26 by llaurent          #+#    #+#             */
/*   Updated: 2019/11/20 13:03:03 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	handle_p(char *buffer, arg_param *arg, int *count, int i)
{
	if (arg->width1 && arg->flag != '-')
		(arg->flag == '0') ? padding('0', arg->width1 - i ,count) : padding(' ', arg->width1 - i ,count);
	ft_putstr_count(buffer, count, arg->width2);
	if (arg->width1 && arg->flag == '-')
		padding(' ', arg->width1 - i,count);
}

void	handle_xX(char *buffer, arg_param *arg, int *count, int i)
{
	int j;

	j = i;
	if (buffer[0] == '-')
		i = 8;
	if (arg->flag != '-' && arg->width1 && (arg->precision == '.' || arg->flag != '0'))
		padding(' ', arg->width1 - ((arg->width2 > i) ? arg->width2 : i), count);
	else if (arg->width1 && arg->flag != '-')
		padding('0', arg->width1 - ((arg->width2 > i) ? arg->width2 : i),count);
	if (arg->width2 > 0)
		padding('0', arg->width2 - i, count);
	if (buffer[0] == '-')
	{
		buffer++;
		padding((arg->conv == 'x') ? 'f' : 'F', 8 - j + 1, count);
	}
	if (!(buffer[0] == '0' && arg->precision == '.' && !arg->width2))
		ft_putstr_count(buffer, count, 0);
	else if (arg->width1 && arg->precision == '.')
		ft_putchar_count(' ', count);
	if (arg->width1 && arg->flag == '-')
		padding(' ', arg->width1 - ((arg->width2 > i) ? arg->width2 : i), count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <llaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:18:26 by llaurent          #+#    #+#             */
/*   Updated: 2019/11/20 13:03:03 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	padding(char c, int len, int *count)
{
	while (len-- > 0)
		ft_putchar_count(c, count);
}

void	handle_100(char *buffer, arg_param *arg, int *count, int i)
{
	if (arg->width1 && arg->flag != '-')
		(arg->flag == '0') ? padding('0', arg->width1 - i ,count) : padding(' ', arg->width1 - i ,count);
	ft_putstr_count(buffer, count, arg->width2);
	if (arg->width1 && arg->flag == '-')
		padding(' ', arg->width1 - i, count);
}

void	handler_arg(va_list va, arg_param *arg, int *count)
{
	char *buffer;
	if (!(buffer = (char *)malloc(sizeof(char) * 1)))
		return ;
	if (arg->conv == 'c')
		ft_strjoin_c(&buffer, (char)(va_arg(va, int)));
	else if (arg->conv == '%')
		ft_strjoin_c(&buffer, '%');
	else if (arg->conv == 'd' || arg->conv == 'i')
		ft_putnbr_buff(&buffer, va_arg(va, int));
	else if (arg->conv == 'u')
		ft_putnbr_u_buff(&buffer, va_arg(va, unsigned int));
	else if (arg->conv == 's')
		ft_putstr_buff(&buffer, va_arg(va, char *));
	else if (arg->conv == 'x' || arg->conv == 'X')
		ft_puthexa_buff(&buffer, (long int)va_arg(va, int), arg, 0);
	else if (arg->conv == 'p')
		ft_puthexa_buff(&buffer, va_arg(va, long int), arg, 0);
	else if (arg->conv == 'o')
		ft_putoctal_buff(&buffer, va_arg(va, int));
	handler_buff(buffer, arg, count);
	ft_bzero((void *)buffer, ft_strlen(buffer));
	free(buffer);
}

int		set_arg_param(arg_param *arg, char *handler, va_list va)
{
	if (ft_strchr("#0-", *handler) && (!arg->flag || (arg->flag == '-' && *handler == '-')) &&
		!arg->width1 && !arg->width2)
		arg->flag = *handler;
	else if (ft_isdigit(*handler) && !arg->width1 && !arg->precision)
		arg->width1 = ft_atoi((const char *)handler);
	else if (ft_isdigit(*handler) && !arg->precision)
		return (1);
	else if (ft_strchr(".*", *handler) && !arg->conv)
	{
		if (*handler == '*' && arg->width1 == 0 && !arg->flagS && arg->precision != '.')
		{
			arg->width1 = va_arg(va, int);
			arg->flagS = 1;
		}
		else if (*handler == '*' && !arg->width2)
			arg->width2 = va_arg(va, int);
		else
		arg->precision = '.';
	}
	else if (ft_isdigit(*handler) && !arg->width2 && !arg->modi )
		arg->width2 = ft_atoi((const char *)handler);
	else if (ft_isdigit(*handler) && !arg->modi)
		return (1);
	else if (ft_strchr("hl", *handler) && (!arg->modi || arg->modi == 'h' || arg->modi == 'l' ) && !arg->conv)
		arg->modi = (arg->modi == *handler) ? (*handler - 32) : *handler;
	else if (ft_strchr("diuxXcspo%", *handler) && !arg->conv)
		arg->conv = *handler;
	else
		return (0);
	return (1);
}

void	handler_buff(char *buffer, arg_param *arg, int *count)
{
	int i;

	i = ft_strlen(buffer);
	if (arg->conv == 'c')
		handle_c(buffer, arg, count, i);
	else if (arg->conv == '%')
		handle_100(buffer, arg, count, i);
	else if (arg->conv == 'd' || arg->conv == 'i')
		handle_di(buffer, arg, count, i);
	else if (arg->conv == 'u')
		handle_u(buffer, arg, count, i);
	else if (arg->conv == 's')
		handle_s(buffer, arg, count, i);
	else if (arg->conv == 'x' || arg->conv == 'X')
		handle_xX(buffer, arg, count, i);
	else if (arg->conv == 'P')
		handle_p(buffer, arg, count, i);
	else if (arg->conv == 'o')
		handle_o(buffer, arg, count, i);
}

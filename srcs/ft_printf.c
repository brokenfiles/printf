/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <llaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:18:26 by llaurent          #+#    #+#             */
/*   Updated: 2019/11/20 18:16:39 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	debug(arg_param *arg)
{
	printf("arg->width1 : %d\n", arg->width1);
	printf("arg->width2 : %d\n", arg->width2);
	printf("arg->flag : %c\n", arg->flag);
	printf("arg->conversion : %c\n", arg->conv);
	printf("arg->precision : %c\n", arg->precision);
	printf("arg->modi : %c\n", arg->modi);
}

void reset_arg_param(arg_param *arg)
{
	arg->conv = 0;
	arg->flag = 0;
	arg->precision = 0;
	arg->modi = 0;
	arg->width1 = 0;
	arg->width2 = 6;
}

int set_arg_param(arg_param *arg, char *handler, va_list va)
{
	if (ft_strchr("-.", *handler) && arg->flag && arg->flag != *handler)
		arg->flag = arg->flag + *handler;
	else if (ft_strchr("0-.", *handler) && !arg->flag)
		arg->flag = *handler;
	else if (ft_isdigit(*handler) && !arg->width1)
	{
		if (arg->width2 == 6)
			arg->width2 = ft_atoi((const char *) handler);
		arg->width1 = ft_atoi((const char *) handler) + (arg->flag == '.' ? 1 : 0);
	}
	else if (ft_isdigit(*handler) && !arg->precision)
		return (1);
	else if (*handler == '*')
	{
		arg->flag = *handler;
		arg->width1 = va_arg(va, int);
	}
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

void	ft_padding(arg_param *arg, int *count, int i, char c, char *buffer)
{
	if (arg->flag == '-')
	{
		ft_putstr_count(buffer, count);
		while (arg->width1-- > i)
			ft_putchar_count(c, count);
	}
	else
	{
		while (arg->width1-- > i)
			ft_putchar_count(c, count);
		ft_putstr_count(buffer, count);
	}
}

void ft_pad_n_buf(char *buffer, arg_param *arg, int *count)
{
	int i;

	i = ft_strlen(buffer);
	//debug(arg);
	if (!buffer)
		return ;
	if (arg->flag == '0' && arg->width1 >= 0)
	{
		if (buffer[0] == '-' && buffer++)
			ft_putchar_count('-', count);
		ft_padding(arg, count, i, '0', buffer);
	}
	else if ((arg->flag == '-' || arg->flag == '*') && arg->width1 >= 0)
		ft_padding(arg, count, i, ' ', buffer);
	else if (arg->flag == '.' && arg->width1 >= 0)
	{
		if (ft_strchr("diuxX", arg->conv))
		{
			if (buffer[0] == '-' && buffer++)
				ft_putchar_count('-', count);
			else
				arg->width1--;
			ft_padding(arg, count, i, '0', buffer);
		}
		else if (ft_strchr("%", arg->conv))
			ft_putchar_count('%', count);
		else
		{
			while (arg->width2-- > (arg->width1 < i ? arg->width1 - 1 : i))
				ft_putchar_count(' ', count);
			ft_putstr_count_number(buffer, count, arg->width1 - 1);
		}
	}
	else if (arg->flag == ('.' + '-') && arg->width1 >= 0)
	{
		ft_putstr_count_number(buffer, count, arg->width2);
		while (arg->width1-- > arg->width2)
			ft_putchar_count(' ', count);
	}
	else
		ft_putstr_count(buffer, count);
}

void handler_arg(va_list va, arg_param *arg, int *count)
{
	char *buffer;
	if (!(buffer = (char *)malloc(sizeof(char) * 1)))
		return ;
	//buffer = "\0";
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
		ft_puthexa_buff(&buffer, (long int)va_arg(va, int), arg);
	else if (arg->conv == 'p')
		ft_puthexa_buff(&buffer, va_arg(va, long int), arg);
	else if (arg->conv == 'o')
		ft_putoctal_buff(&buffer, va_arg(va, int));
	ft_pad_n_buf(buffer, arg, count);
	ft_bzero((void *)buffer, ft_strlen(buffer));
	free(buffer);
}

int ft_printf(char *str, ...)
{
	va_list		va;
	arg_param	arg;
	int			count;

	count = 0;
	va_start(va, str);
	while (*str)
	{
		if (*str == '%')
		{
			reset_arg_param(&arg);
			str++;
			while (set_arg_param(&arg, &*(str), va) && *str)
				str++;
			handler_arg(va, &arg, &count);
		}
		else
			ft_putchar_count(*(str++), &count);
	}
	va_end(va);
	return (count);
}

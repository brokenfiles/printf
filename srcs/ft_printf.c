/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <llaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:18:26 by llaurent          #+#    #+#             */
/*   Updated: 2019/11/18 16:14:04 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/printf.h"

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
	if (ft_strchr("#0-", *handler) && !arg->flag && !arg->width1)
		arg->flag = *handler;
	else if (ft_isdigit(*handler) && !arg->width1 && !arg->precision)
		arg->width1 = ft_atoi((const char *)handler);
	else if (ft_isdigit(*handler) && !arg->precision)
		return (1);
	else if (ft_strchr(".*", *handler) && !arg->precision && arg->width2 == 6)
	{
		arg->precision = *handler;
		arg->width2 = (arg->precision == '*') ? va_arg(va, int) : 0;
	}
	else if (ft_isdigit(*handler) && arg->width2 == 6 && !arg->modi)
		arg->width2 = ft_atoi((const char *)handler);
	else if (ft_isdigit(*handler) && !arg->modi)
		return (1);
	else if (ft_strchr("hljz", *handler) && (!arg->modi || arg->modi == 'h' || arg->modi == 'l' ) && !arg->conv)
		arg->modi = (arg->modi == *handler) ? (*handler - 32) : *handler;
	else if (ft_strchr("diuxXcspof%", *handler) && !arg->conv)
		arg->conv = *handler;
	else
		return (0);
	return (1);
}

void handler_arg(va_list va, arg_param *arg, int *count)
{
	if (arg->conv == 'c')
		ft_putchar_count((char)va_arg(va, int), count);
	else if (arg->conv == '%')
		ft_putchar_count('%', count);
	else if (arg->conv == 'd' || arg->conv == 'i')
		ft_putnbr_count(va_arg(va, int), count);
	else if (arg->conv == 'u')
		ft_putnbr_unsigned_count(va_arg(va, unsigned int), count);
	else if (arg->conv == 's')
		ft_putstr_count(va_arg (va, char *), count);
	else if (arg->conv == 'x' || arg->conv == 'X')
		ft_puthexa_count((long int)va_arg(va, int), count, arg);
	else if (arg->conv == 'p')
		ft_puthexa_count(va_arg(va, long int), count, arg);
	else if (arg->conv == 'o')
		ft_putoctal_count(va_arg(va, int), count);
	else if (arg->conv == 'f')
		ft_putfloat_count(va_arg(va, double), count, arg);
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


int main (void)
{
	int number;

	number = 123456789;
	/*printf(" %-10d \n", number);
	printf(" %010d \n", number);
	printf(" %-#10x \n", number);
	printf(" %#x \n\n", number);
*/
	ft_printf("d %.2f", 500.50687);
	//printf("\nd %s\n", "bonjour");


	//printf("count réel : %d\n\n", printf("char : %c\nstring : %s\npointeur : %p\nint : %i\ndecimal : %d\nhexa : %#x\nHEXA : %X\npourcent : %%\n", '%', "hello", &number, 123, 1234, number, number));
	//printf("count new  : %d\n", ft_printf("char : %c\nstring : %s\npointeur : %p\nint : %i\ndecimal : %d\nhexa : %#x\nHEXA : %X\npourcent : %%\n", '%', "hello", &number, 123, 1234, number, number));


	// "." : f to do : s
	// attention aux conversions x et X négative
	// "*" : rajoute x ' ' devant pour avoir n char total, avec n passé en parametre
	// "0" : rajoute x '0' devant pour avoir n char total, avec n en width;
	// demander pour le "-"
	// demander pour le const char * str du prototype de ft_printf()
	// rajouter un buffer, le résultat et d'abord écrit dedans afin de rajouter les zéros ou espaces
   	return (0);
}

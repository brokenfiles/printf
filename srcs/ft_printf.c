/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <llaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:18:26 by llaurent          #+#    #+#             */
/*   Updated: 2019/11/21 16:57:13 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	debug(arg_param *arg)
{
	printf("\n\narg->width1 : %d\n", arg->width1);
	printf("arg->width2 : %d\n", arg->width2);
	printf("arg->flag : %c\n", arg->flag);
	printf("arg->flagS : %d\n", arg->flagS);
	printf("arg->conversion : %c\n", arg->conv);
	printf("arg->precision : %c\n", arg->precision);
	printf("arg->modi : %c\n\n", arg->modi);
}

void	reset_arg_param(arg_param *arg)
{
	arg->conv = 0;
	arg->flag = 0;
	arg->precision = 0;
	arg->modi = 0;
	arg->width1 = 0;
	arg->width2 = 0;
	arg->flag = 0;
	arg->flagS = 0;
}

int		set_arg_param(arg_param *arg, char *handler, va_list va)
{
	if (ft_strchr("#0-", *handler) && !arg->flag && !arg->width1 && !arg->width2)
		arg->flag = *handler;
	else if (ft_isdigit(*handler) && !arg->width1 && !arg->precision)
		arg->width1 = ft_atoi((const char *) handler);
	else if (ft_isdigit(*handler) && !arg->precision)
		return (1);
	else if (ft_strchr(".*", *handler) && !arg->conv)
	{
		arg->flagS = (arg->precision == '*' && *handler == '.') ? 1 : arg->flagS;
		arg->precision = *handler;
		arg->width2 = (arg->precision == '*' && !arg->flagS) ? va_arg(va, int) : arg->width2;
		if (arg->flagS)
		{
			arg->width1 = arg->width2;
			arg->width2 = ft_atoi((const char *) ++handler);
			//debug(arg);
			if (!arg->width2)
				arg->flagS = 0;
		}
	}
	else if (ft_isdigit(*handler) && !arg->width2 && !arg->modi)
		arg->width2 = ft_atoi((const char *) handler);
	else if (ft_isdigit(*handler) && !arg->modi)
		return (1);
	else if (ft_strchr("hl", *handler) && (!arg->modi || arg->modi == 'h' || arg->modi == 'l') && !arg->conv)
		arg->modi = (arg->modi == *handler) ? (*handler - 32) : *handler;
	else if (ft_strchr("diuxXcspo%", *handler) && !arg->conv)
		arg->conv = *handler;
	else
		return (0);
	return (1);
}

void	ft_padding(arg_param *arg, int *count, int i, char c, char *buffer)
{
	int	index;

	index = 0;
	if ((!arg->width1 && (arg->conv != '%' || arg->precision != '.') && arg->conv != 's') ||
		(arg->precision == '*' && arg->conv == 's'))
	{
		while (arg->width2 > i) //rajoute à gauche
		{
			ft_putchar_count(c, count);
			arg->width2--;
		}
		ft_putstr_count(buffer, count, 0);
	}
	else if (arg->precision == '.' && (!arg->flagS || arg->conv == '%') && arg->flag != '-' && arg->flag) //rajoute à gauche et coupe
	{
		//debug(arg);
		//ft_printf("int : ");
		if (arg->width1 < arg->width2 && arg->conv != '%' && arg->conv != 's')
			arg->width1 = arg->width2;
		index = arg->width1;
		while (arg->width1 > i)
		{
				if (arg->conv == '%')
					ft_putchar_count(c, count);
				else if (index > arg->width2)
					ft_putchar_count(' ', count);
				else
					ft_putchar_count(c, count);
			arg->width1--;
			index--;
		}
		ft_putstr_count(buffer, count, i);
	}
	else if (arg->precision == '.' && (arg->conv == '%') && arg->flag == '-')
	{
		ft_putstr_count(buffer, count, arg->width2);
		while (arg->width1 > i || arg->width1 > arg->width2)
		{
			ft_putchar_count(c, count);
			arg->width1--;
		}
	}
	else if (!arg->precision && arg->flag == '-')
	{
		ft_putstr_count(buffer, count, arg->width2);
		while (arg->width1 > i && arg->width1 > arg->width2) //rajoute à droite
		{
			ft_putchar_count(c, count);
			arg->width1--;
		}
	}
	else if (arg->conv == '%' && arg->precision == '.' && !arg->flagS && !arg->flag) // dans le cas ou on a
	{
		//debug(arg);
		while (arg->width1 > i) //rajoute à gauche
		{
			ft_putchar_count(c, count);
			arg->width1--;
		}
		ft_putstr_count(buffer, count, arg->width2);
	}
	else
	{
		//debug(arg);
		if (arg->width1 < arg->width2) //oui, ce cas la est différent des autres :(
		{
			while (arg->width2 > i)                         //rajoute à gauche les 0 dans le cas '*.'
			{
				ft_putchar_count(!ft_strchr("s%", arg->conv) ? '0' : ' ', count);
				arg->width2--;
			}
		}
		while (arg->width1 > i && arg->width1 > arg->width2) //rajoute à gauche
		{
			ft_putchar_count(c, count);
			arg->width1--;
		}
		if (arg->conv == 's' && arg->width2 < i)
			arg->width1++;
		if (arg->flagS && arg->width1)
		{
			while (arg->width1 > i)                         //rajoute à gauche les 0 dans le cas '*.'
			{
				ft_putchar_count(!ft_strchr("s%", arg->conv) ? '0' : ' ', count);
				arg->width1--;
			}
		}
		ft_putstr_count(buffer, count, (!arg->flag && arg->flagS && ft_strchr("duixX", arg->conv)) ? i : arg->width2);
	}
}

void	ft_pad_n_buf(char *buffer, arg_param *arg, int *count)
{//gere le type de char à mettre pour le padding
	int i;

	i = ft_strlen(buffer);
	if (!buffer)
		return;
	if (((arg->flag == '0' && arg->width1 >= 0) ||
		 (arg->precision == '.' && arg->width1 == 0)))      //padding à gauche en 0
	{
		//printf("HERE 1");
		if (buffer[0] == '-' && buffer++)
			ft_putchar_count('-', count);
		ft_padding(arg, count, i, '0', buffer);
	}
	else if ((((arg->width2 && arg->precision == '.') || arg->precision == '*')
			&& arg->conv == 's' && !arg->flag)
			|| ft_strchr("cdiuxX%", arg->conv))  //padding à gauche de ' '
		ft_padding(arg, count, i, ' ', buffer);
	else if ((arg->flag == '-' && arg->width1 > 0)) //padding à droite
	{
		ft_putstr_count(buffer, count, arg->width2);
		if (arg->precision == '.')
		{
			while (arg->width1-- > ((i < arg->width2) ? i : arg->width2))
				ft_putchar_count(' ', count);
		}
		else
		{
			while (arg->width1-- > i)
				ft_putchar_count(' ', count);
		}
	}
	else
		ft_putstr_count(buffer, count, arg->width2);
}

void	handler_arg(va_list va, arg_param *arg, int *count)
{
	char *buffer;
	if (!(buffer = (char *) malloc(sizeof(char) * 1)))
		return;
	if (arg->conv == 'c')
		ft_strjoin_c(&buffer, (char) (va_arg(va, int)));
	else if (arg->conv == '%')
		ft_strjoin_c(&buffer, '%');
	else if (arg->conv == 'd' || arg->conv == 'i')
		ft_putnbr_buff(&buffer, va_arg(va, int));
	else if (arg->conv == 'u')
		ft_putnbr_u_buff(&buffer, va_arg(va, unsigned int));
	else if (arg->conv == 's')
		ft_putstr_buff(&buffer, va_arg(va, char *));
	else if (arg->conv == 'x' || arg->conv == 'X')
		ft_puthexa_buff(&buffer, (long int) va_arg(va, int), arg);
	else if (arg->conv == 'p')
		ft_puthexa_buff(&buffer, va_arg(va, long int), arg);
	else if (arg->conv == 'o')
		ft_putoctal_buff(&buffer, va_arg(va, int));
	ft_pad_n_buf(buffer, arg, count);
	ft_bzero((void *) buffer, ft_strlen(buffer));
	free(buffer);
}

int		ft_printf(char *str, ...)
{
	va_list va;
	arg_param arg;
	int count;

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


/*

int main (void)
{
	int number;

	number = 1234;
 
    
    printf("%.3s.\n", "forty-two");
    ft_printf("%.3s.\n", "forty-two");
    printf("real : %5.3s.\n", "forty-two");
    ft_printf("fake : %5.3s.\n", "forty-two");

	//int first, second;
	//second = ft_printf("---- FAKE PRINTF ----\nint : %d %u\n---- PRINTF ---- ", -1337, (unsigned int)45);
	//first =     printf("\n---- REAL PRINTF ----\nint : %.10d %-5u\n---- PRINTF ----",  -1337, (unsigned int)45);
	//printf("\nfirst: %d, second: %d, equals: %s\n", first, second, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO]");

    //printf("count réel : %d\n\n", printf("char : %c\nstring : %s\npointeur : %p\nint : %i\nunsigned : %010u\nhexa : %#x\nHEXA : %X\npourcent : %%\n", '%', "hello", &number, 123, 1234, number, number));
    //printf("count new  : %d\n", ft_printf("char : %c\nstring : %s\npointeur : %p\nint : %i\nunsigned : %010u\nhexa : %#x\nHEXA : %X\npourcent : %%\n", '%', "hello", &number, 123, 1234, number, number));
    
    

 
 
	// demander pour le const char * str du prototype de ft_printf()
   	return (0);
}

*/

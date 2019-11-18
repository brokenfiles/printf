/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <llaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:12:16 by llaurent          #+#    #+#             */
/*   Updated: 2019/11/18 14:13:34 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdarg.h>
#include <stdio.h>
#include "libft.h"

typedef struct struct_arg
{
	char	conv;
	char	flag;
	char	precision;
	char	modi;
	int 	width1;
	int		width2;
}				arg_param;

void		ft_putchar_count(char c, int *count);
void		ft_putnbr_count(int nb, int *count);
void		ft_putnbr_unsigned_count(unsigned int nb, int *count);
void		ft_putstr_count(char *str, int *count);
void		ft_puthexa_count(long int nb, int *count, arg_param *arg);
void		ft_putoctal_count(int nb, int *count);
void		ft_putfloat_count(double nb, int *count, arg_param *arg);

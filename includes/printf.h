/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <llaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:12:16 by llaurent          #+#    #+#             */
/*   Updated: 2019/11/19 13:14:17 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdarg.h>
#include <stdio.h>
#include "libft.h"

typedef struct struct_arg
{
	char	conv;
	char	flag;
	char	modi;
	int		precision;
	int 	width1;
	int		width2;
}				arg_param;

void		ft_putchar_count(char c, int *count);
void		ft_putnbr_count(long int nb, int *count, arg_param *arg);
void		ft_putstr_count(char *str, int *count, arg_param *param);
void		ft_puthexa_count(long int nb, int *count, arg_param *arg);
void		ft_putoctal_count(int nb, int *count);

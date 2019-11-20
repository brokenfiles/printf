/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <llaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:12:16 by llaurent          #+#    #+#             */
/*   Updated: 2019/11/20 13:09:54 by llaurent         ###   ########.fr       */
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
void		ft_putnbr_buff(char **buffer, int nb);
void		ft_putnbr_u_buff(char **buffer, unsigned int nb);
void		ft_putstr_count(char *str, int *count);
void		ft_puthexa_buff(char **buffer, long int nb, arg_param *arg);
void		ft_putoctal_buff(char **buffer, int nb);
void		ft_strjoin_c(char **s1, char s2);
void		ft_putchar_buff(char **buffer, int c);
void		ft_putstr_buff(char **buffer, char *str);
void		ft_putstr_count_number(char *str, int *count, int n);
int 		ft_printf(char *str, ...);

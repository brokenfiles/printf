/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <llaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:12:16 by llaurent          #+#    #+#             */
/*   Updated: 2019/11/20 12:07:11 by llaurent         ###   ########.fr       */
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
    char	pchar;
    int		flagS;
}				arg_param;

void		handle_c(char *buffer, arg_param *arg, int *count, int i);
void		handle_u(char *buffer, arg_param *arg, int *count, int i);
void		handle_di(char *buffer, arg_param *arg, int *count, int i);
void 		handle_o(char *buffer, arg_param *arg, int *count, int i);
void 		handle_p(char *buffer, arg_param *arg, int *count, int i);
void		handle_xX(char *buffer, arg_param *arg, int *count, int i);
void		handle_s(char *buffer, arg_param *arg, int *count, int i);
void 		padding(char c, int len, int *count);
void		handle_100(char *buffer, arg_param *arg, int *count, int i);
void 		handler_arg(va_list va, arg_param *arg, int *count);
int			set_arg_param(arg_param *arg, char *handler, va_list va);
void 		handler_buff(char *buffer, arg_param *arg, int *count);
void 		reset_arg_param(arg_param *arg);
void		ft_putchar_count(char c, int *count);
void		ft_putnbr_buff(char **buffer, int nb);
void		ft_putnbr_u_buff(char **buffer, unsigned int nb);
void		ft_putstr_count(char *str, int *count, int len);
void        ft_putstr_buff(char **buffer, char *str);
void		ft_puthexa_buff(char **buffer, long int nb, arg_param *arg, int flag);
void		ft_putoctal_buff(char **buffer, int nb);
void		ft_strjoin_c(char **s1, char s2);
void		ft_putchar_buff(char **buffer, int c);
int         ft_printf(char *str, ...);

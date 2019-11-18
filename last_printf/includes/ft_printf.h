/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <llaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 10:27:55 by llaurent          #+#    #+#             */
/*   Updated: 2019/11/18 10:43:17 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# define AVAILABLE_CONVERSION "cspdiuxX%"

int	ft_strlen(char *str);
int	ft_atoi(const char *str);
int	ft_isdigit(int c);

typedef struct	s_param
{
	int		position;
	char	type;
	int		precision;
	int		width;
}				t_param;
#endif

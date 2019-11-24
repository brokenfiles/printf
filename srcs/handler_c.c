/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <llaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:18:26 by llaurent          #+#    #+#             */
/*   Updated: 2019/11/20 13:03:03 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	handle_c(char *buffer, arg_param *arg, int *count, int i)
{
	i = 0;
	if (arg->width1 && arg->flag != '-')
		padding(' ', arg->width1 - 1, count);
	ft_putchar_count(buffer[0], count);
	if (arg->width1 && arg->flag == '-')
		padding(' ', arg->width1 - 1, count);
}

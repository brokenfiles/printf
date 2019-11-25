/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <llaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 12:31:44 by llaurent          #+#    #+#             */
/*   Updated: 2019/11/25 12:31:44 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	handle_c(char *buffer, t_arg *arg, int *count, int i)
{
	i = 0;
	if (arg->width1 && arg->flag != '-')
		padding(' ', arg->width1 - 1, count);
	ft_putchar_count(buffer[0], count);
	if (arg->width1 && arg->flag == '-')
		padding(' ', arg->width1 - 1, count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <llaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:18:26 by llaurent          #+#    #+#             */
/*   Updated: 2019/11/20 13:03:03 by llaurent         ###   ########.fr       */
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
	arg->width2 = 0;
	arg->flagS = 0;
}

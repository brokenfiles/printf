/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <llaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 10:25:55 by llaurent          #+#    #+#             */
/*   Updated: 2019/11/18 11:09:14 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	get_nbr_length(unsigned int nb)
{
	unsigned int	index;

	index = 0;
	while (nb >= 10)
	{
		nb /= 10;
		index++;
	}
	return (index + 1);
}

char	*ft_strdup(const char *s1)
{
	int		index;
	char	*returned_string;

	index = 0;
	if (!(returned_string = (char *)malloc(sizeof(char) * ft_strlen((char *)s1) + 1)))
		return (NULL);
	while (s1[index])
	{
		returned_string[index] = s1[index];
		index++;
	}
	returned_string[index] = '\0';
	return (returned_string);
}

int		is_valid_conversion(char c)
{
	int		index;
	char	*conversion_list;

	conversion_list = AVAILABLE_CONVERSION;
	index = 0;
	while (conversion_list[index])
	{
		if (c == conversion_list[index])
			return (1);
		index++;
	}
	return (0);
}

int		count_purcents(const char *format)
{
	int		purcent;
	int		index;

	index = 0;
	purcent = 0;
	if (ft_strlen((char *) format) <= 1)
		return (0);
	while (format[index] && format[index + 1])
	{
		if (format[index] == '%' && format[index + 1] != '%'
		&& is_valid_conversion(format[index + 1]))
			purcent++;
		index++;
	}
	return (purcent);
}

t_param	*get_purcents(const char *format, va_list ap)
{
	int		purcent;
	int		index;
	t_param	tmp;
	t_param *list;

	index = 0;
	purcent = 0;
	if (ft_strlen((char *) format) <= 1)
	return (0);
	if (!(list = (t_param *) malloc(sizeof(t_param) * (count_purcents(format) + 1))))
	return (NULL);
	while (format[index] && format[index + 1])
	{
		if (format[index] == '%' && format[index + 1] != '%')
		{
			tmp.position = index;
			tmp.type = format[index + 1];
			if (is_valid_conversion(tmp.type))
			{
				list[purcent] = tmp;
				purcent++;
			}
		}
		index++;
	}
	return (list);
}

char	*ft_strjoin_printf(char	*sub1, char	*add, char *sub2)
{
	int		index_subs;
	int		index_str;
	int		size;
	char	*new;

	index_subs = 0;
	index_str = 0;
	size = ft_strlen(sub1) + ft_strlen(add) + ft_strlen(sub2) + 1;
	if (!(new = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	while (sub1[index_subs])
		new[index_str++] = sub1[index_subs++];
	index_subs = 0;
	while (add[index_subs])
		new[index_str++] = add[index_subs++];
	index_subs = 0;
	while (sub2[index_subs])
		new[index_str++] = sub2[index_subs++];
	new[index_str] = 0;
	return (new);
}

/*
 *
 * how to push a char* in a str:
 * Bonjour c'est moi : 17chars
 * char* to push : " a", pos : 13
 * malloc : 17 + 2 + 1 (\0)
 *
 * cut string with a ft_strsub with parameters : str, 0, 13
 * cut string with a ft_strsub with parameters : str, 13, sizeof(str)
 * ft_strjoin(strsub1, char* add, strsub2)
 *
 */

/*
 ** Bonjour je suis louis j'ai %d ans // %d : 18
 **                            ..     //
 ** Bonjour je suis louis j'ai %d ans // %d : 3300
 **                            ....       //
*/
char	*replace_str(char *str, t_param current)
{
	int		index;
	int		size;
	char	*new_str;

	index = current.position;
	// in case of int
	if (!(new_str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);

	return (new_str);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int index;
	t_param	current;
	char	*new_str;
	int 	tmp;

	va_start(ap, format);
	index = 0;
	new_str = ft_strdup(format);
	while (format[index] && format[index + 1])
	{
		if (format[index] != '%')
			write(1, &format[index], 1);
		else
		{
			if (is_valid_conversion(format[index + 1]))
			{
				current.position = index;
				current.type = format[index + 1];
				current.precision = 0;
				current.width = 0;
				index++;
			}
			else if (format[index + 1] == '.' || format[index + 1] == '*')
			{
				tmp = (ft_strlen((char *)format) > index + 1) ? ft_atoi((const char *)format + index + 2) : 0;
				if (format[index + 1 == '.'])
					current.precision = tmp;
				else if (format[index + 1] == '*')
					current.width = tmp;
				index += get_nbr_length((unsigned int)tmp) + 2;
				current.type = format[index];
				current.position = index;
			}
		}
		index++;
	}
	va_end(ap);
	(void)format;
	return (0);
}

int	main(int ac, char **av)
{
	ft_printf(av[1], atoi(av[2]));
	printf("\n");
	printf(av[1], atoi(av[2]));
	return (0);
}
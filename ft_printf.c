/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouzidi <sbouzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 11:47:57 by sbouzidi          #+#    #+#             */
/*   Updated: 2021/05/19 13:58:17 by sbouzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_list(t_struct *list)
{
	list->precisionpos = 0;
	list->nprinted = 0;
	list->moins = 0;
	list->plus = 0;
	list->space = 0;
	list->zero = 0;
	list->diez = 0;
	list->width = 0;
	list->precisionlen = 0;
	list->precision = 0;
	list->star_width = 0;
	list->star_precision = 0;
}

void	check_conv(const char *str, t_struct *list, int *i, va_list ap)
{
	while (ft_strrchr(TYPESFLAGS, str[*i + 1]))
	{
		*i = *i + 1;
		if (ft_strrchr("cspdiuxXfyb%", str[*i]))
		{
			convert(str[*i], list, ap);
			break ;
		}
		parse_indicateur(str[*i], list);
		parse_width(str[*i], list);
	}	
}

int	check_input(const char *str, t_struct *list, va_list ap, int r)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '%' && str[i])
			list->nprinted += write(1, &str[i], 1);
		else if (str[i] == '%')
		{	
			if (!ft_strrchr(TYPESFLAGS, str[i + 1]))
				list->nprinted += write(1, &str[i], 1);
			if (!parse_indicateur(str[i + 1], list))
				list->nprinted += write(1, &str[i], 1);
			check_conv(str, list, &i, ap);
		}
		r = r + list->nprinted;
		init_list(list);
		i++;
	}
	return (r);
}

int	ft_printf(const char *str, ...)
{
	static int	r = 0;
	va_list		ap;
	t_struct	list;	

	r = 0;
	init_list(&list);
	va_start(ap, str);
	r = check_input(str, &list, ap, r);
	va_end(ap);
	return (r);
}

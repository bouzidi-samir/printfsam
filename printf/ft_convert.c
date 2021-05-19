/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouzidi <sbouzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 11:47:57 by sbouzidi          #+#    #+#             */
/*   Updated: 2021/05/19 14:20:45 by sbouzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "limits.h"

void	flag_star(va_list ap, t_struct *list)
{
	if (list->star_width > 0)
	{
		list->width = va_arg(ap, int);	
		if (list->width < 0)
		{
			list->width *= -1;
			list->moins++;
		}
	}	
}

void	conv_char(va_list ap, t_struct *list)
{
	char	arg;
	int     width;
	int     i;

	i = 0;
	flag_star(ap, list);
	arg = va_arg(ap, int);
	width = list->width - 1;
	if (width < 0)
		width = 0;
	if (list->moins == 0)
	{
		print_width_char(list, width);
		list->nprinted += write(1, &arg, 1);
	}
	else if (list > 0)
	{
		list->nprinted += write(1, &arg, 1);
		print_width_char(list, width);
	}

}

int	conv_int(va_list ap, t_struct *list)
{
	char	*conv;
	int		arg;
	int		size;
	int		neg;

	neg = 0;
	conv = NULL;
	flag_star(ap, list);
	if (list->star_precision > 0)
		list->precisionlen = va_arg(ap, int);
	arg = va_arg(ap, long long int);
	if ((int)arg < 0 && arg > -2147483647 - 1)
	{
		neg = 1;
		arg *= -1;
	}
	if (arg == 0 && list->precision > 0 && list->precisionlen == 0)
		conv = ft_strdup("");
	else 
		conv = ft_itoa(arg);
	size = ft_strlen(conv);
	print_int(list, conv, neg, size);
	free(conv);
	return (1);
}

void	print_int(t_struct *list, char *conv, int neg, int size)
{
	if (list->moins > 0)
	{
		if (neg == 1)
			list->nprinted += write(1, "-", 1);
		print_precision(list, conv);
		ft_print_fd(conv, size, list);
		print_width_int(list, conv, neg);
	}
	else if (list->moins == 0)
	{
		if (list->precision > 0)
		 	print_width_int(list, conv, neg);
		if (neg == 1)
			list->nprinted += write(1, "-", 1);	
		if (list->precision == 0)
		 	print_width_int(list, conv, neg);
		
		print_precision(list, conv);
		ft_print_fd(conv, size, list);
	}
}

void	conv_str(va_list ap, t_struct *list)
{
	char	*arg;
	int		size;
	int     space;
	int     width;
	int i;

	i = 0;
	space = 0;
	flag_star(ap, list);	
	if (list->star_precision > 0)
		list->precisionlen = va_arg(ap, int);
	arg = va_arg(ap, char *);
	if (list->precisionlen < 0)
		arg = ft_strdup("(null)");
	if (arg == 0)
		arg = ft_strdup("(null)");
	if (list->precision > 0 && list->precisionlen < (int)ft_strlen(arg))
		size = list->precisionlen;
	else
		size = ft_strlen(arg);
	width = list->width - size;	
	if (list->moins > 0 )
	{
		while (arg[i] && i < size)
		{
			if (list->precision > 0 && list->precisionlen == 0)
				list->nprinted += write(1, " ", 1);
			else
			list->nprinted += write(1, &arg[i], 1);
			i++;
		}
		print_width_char(list, width);
	}
	else if (list->moins == 0)
	{
		print_width_char(list, width);
		while (arg[i] && i < size)
		{
			if (list->precision > 0 && list->precisionlen == 0)
				list->nprinted += write(1, " ", 1);
			else
				list->nprinted += write(1, &arg[i], 1);
			i++;
		}
	}	
	if (ft_strncmp(arg, "(null)", 8) == 0)
		free(arg);
}


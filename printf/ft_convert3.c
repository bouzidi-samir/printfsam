/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouzidi <sbouzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 11:47:57 by sbouzidi          #+#    #+#             */
/*   Updated: 2021/05/19 14:22:54 by sbouzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	else if (list->moins == 0 )
	{
		if (list->precisionlen < 0)
			list->precision = 0;
		if (list->precision > 0 || list->zero == 0)
		 	print_width_int(list, conv, neg);
		if (neg == 1)
			list->nprinted += write(1, "-", 1);	
		if (list->precision == 0 && list->zero > 0 )
		 	print_width_int(list, conv, neg);
		else if (list->precisionlen < 0 && list->zero > 0 && list->moins == 0)
			print_width_int(list, conv, neg);
		print_precision(list, conv);
		ft_print_fd(conv, size, list);
	}
}

int	  			conv_unint(va_list ap, t_struct *list)
{
	unsigned long long	arg;
	char	*conv;
	int size;
	int neg;
	
	neg = 0;
	conv = NULL;
	flag_star(ap, list);
	if (list->star_precision > 0)
		list->precisionlen = va_arg(ap, int);
	arg = va_arg(ap, unsigned int);
	//if (arg < 0)
	//{
	//	neg = 1;
	//	arg *= -1;
	//}
	if (arg == 0 && list->precision > 0 && list->precisionlen == 0)
		conv = ft_strdup("");
	else 
			conv = ft_u_itoa(arg);
	size = ft_strlen(conv);
	print_int(list, conv, neg, size);
	free(conv);
		return (1);
}








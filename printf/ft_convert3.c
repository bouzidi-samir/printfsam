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








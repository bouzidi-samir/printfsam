/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouzidi <sbouzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 11:47:57 by sbouzidi          #+#    #+#             */
/*   Updated: 2021/05/19 13:29:54 by sbouzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_precision(t_struct *list, char *conv)
{
	int	i;
	int	s;

	i = 0;
	s = list->precisionlen - ft_strlen(conv);
	if (s < 0)
		s = 0;
	if (s >= 0)
	{
		while (i < s)
		{
			list->nprinted += write(1, "0", 1);
			i++;
		}	
	}
}

void	print_width_int(t_struct *list, char *conv, int neg)
{
	int	i;
	int	prec;
	int	s1;

	i = 0;
	prec = list->precisionlen - ft_strlen(conv);
	if (prec < 0)
		prec = 0;
	s1 = list->width - ft_strlen(conv) - prec - neg;
	while (i < s1)
	{
		if (list->zero > 0 && list->precision == 0 && list->moins == 0)
			list->nprinted += write(1, "0", 1);
		else if (list->precisionlen < 0 && list->zero > 0 && list->moins ==0)
			list->nprinted += write(1, "0", 1);
		else
			list->nprinted += write(1, " ", 1);
		i++;
	}	
}

void	print_width_char(t_struct *list, int width)
{
	int	i;

	i = 0;
	while (i < width)
	{
		list->nprinted += write(1, " ", 1);
		i++;
	}
}

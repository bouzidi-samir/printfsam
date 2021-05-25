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

void	conv_char(va_list ap, t_struct *list)
{
	char	arg;
	int		width;
	int		i;

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

void	conv_str(va_list ap, t_struct *list)
{
	char	*arg;
	int		size;
	int		width;

	flag_star(ap, list);
	if (list->star_precision > 0)
		list->precisionlen = va_arg(ap, int);
	arg = va_arg(ap, char *);
	if (arg == 0)
		arg = ft_strdup("(null)");
	if (list->precision > 0 && list->precisionlen < (int)ft_strlen(arg))
		size = list->precisionlen;
	else
		size = ft_strlen(arg);
	width = list->width - size;
	print_str(list, arg, width, size);
	if (ft_strncmp(arg, "(null)", 8) == 0)
		free(arg);
}

void	print_str(t_struct *list, char *arg, int width, int size)
{
	if (list->precisionlen < 0)
	{	
		if (list->moins == 0)
			print_width_char(list, (list->width - ft_strlen(arg)));
		ft_print_fd(arg, ft_strlen(arg), list);
		if (list->moins > 0)
			print_width_char(list, (list->width - ft_strlen(arg)));
	}
	else
	{
		if (list->moins == 0 )
			print_width_char(list, width);
		print_strloop(list, arg, size);
		if (list->moins > 0)
			print_width_char(list, width);
	}
}

void	print_strloop(t_struct *list, char *arg, int size)
{
	int	i;

	i = 0;
	while (arg[i] && i < size)
	{
		if (list->precision > 0 && list->precisionlen == 0)
			list->nprinted += write(1, " ", 1);
		else
			list->nprinted += write(1, &arg[i], 1);
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouzidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 11:47:57 by sbouzidi          #+#    #+#             */
/*   Updated: 2021/04/17 11:47:05 by sbouzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_strrev(char *str)
{
	char	c;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(str) - 1;
	while (i < j)
	{
		c = str[i];
		str[i] = str[j];
		str[j] = c;
		i++;
		j--;
	}
}

char	*ft_hexad(unsigned long long nb)
{	
	char					*hexad;
	char					*r;
	int						i;
	unsigned long long		save_nb;

	i = 0;
	hexad = ft_calloc(sizeof(char), 100);
	while (nb != 0)
	{
		save_nb = nb % 16;
		if (save_nb < 10)
			hexad[i++] = save_nb + 48;
		else
			hexad[i++] = save_nb + 55;
		nb /= 16;
	}
	ft_strrev(hexad);
	r = ft_strdup(hexad);
	free(hexad);
	return (r);
}

int	conv_point(va_list ap, t_struct *list)
{
	char					*str;
	char					*stock;
	int						nega;
	unsigned long long		point;

	nega = 0;
	flag_star(ap, list);
	point = va_arg(ap, unsigned long long);
	if (point == 0 && list->precision > 0 && list->precisionlen == 0)
		return (-1);
	str = ft_strtolower(ft_hexad(point));
	if (point == 0)
		stock = ft_strdup("0x0");
	else
		stock = ft_strjoin("0x", str);
	free(str);
	str = ft_strdup(stock);
	free(stock);
	print_point(list, str, nega);
	free(str);
	return (1);
}

void	print_point(t_struct *list, char *str, int nega)
{
	if (list->moins > 0)
	{
		ft_putstr_fd(str, 1);
		print_width_int(list, str, nega);
	}	
	else if (list->moins == 0)
	{
		print_width_int(list, str, nega);
		ft_putstr_fd(str, 1);
	}
	list->nprinted += (ft_strlen(str));
}

int	conv_x(va_list ap, t_struct *list, char *c)
{
	unsigned long long	arg;
	char				*conv;
	int					neg;
	int					size;

	conv = NULL;
	neg = 0;
	flag_star(ap, list);
	if (list->star_precision > 0)
		list->precisionlen = va_arg(ap, int);
	arg = va_arg (ap, unsigned int);
	if (arg == 0 && list->precision > 0 && list->precisionlen < 0)
		conv = ft_strdup("0");
	else if (arg == 0 && list->precision == 0 && list->precisionlen <= 0)
		conv = ft_strdup("0");
	else
		conv = ft_hexad(arg);
	if (*c == 'x')
		conv = ft_strtolower(conv);
	else
		conv = ft_strtoupper(conv);
	size = ft_strlen(conv);
	print_int(list, conv, neg, size);
	free(conv);
	return (0);
}

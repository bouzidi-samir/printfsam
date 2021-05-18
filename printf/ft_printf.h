/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouzidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 11:47:57 by sbouzidi          #+#    #+#             */
/*   Updated: 2021/04/17 11:47:05 by sbouzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define TYPESFLAGS "cspdiuxX%-+.*0123456789"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_struct
{
	int		*str;
	int		nprinted;
	int		zero;
	int		moins;
	int		plus;
	int		space;
	int		diez;
	int		width;
	int		precisionlen;
	int		precision;
	int		star_width;
	int     star_precision;
}			t_struct;

int				ft_printf(const char *str, ...);
int				check_input(const char *str, t_struct *list, va_list ap);
void			init_list(t_struct *list);
int				parse_indicateur(char c, t_struct *list);
int				check_empty(t_struct *list);
int				parse_width(char c, t_struct *list);
void			convert(char c, t_struct *list, va_list ap);
void			conv_char(va_list ap, t_struct *list);
int				conv_point(va_list ap, t_struct *list);
int				conv_int(va_list ap, t_struct *list);
int				conv_unint(va_list ap, t_struct *list);
int				conv_x(va_list ap, t_struct *list, char *c);
void			conv_str(va_list ap, t_struct *list);
void			print_int(t_struct *list, char *conv, int neg, int size);
void			print_precision(t_struct *list, char *conv);
void			print_width_int(t_struct *list, char *conv, int n);
void			print_width_char(t_struct *list, int width);
void			format_x(t_struct *list, char c);
void			ft_print_fd(char *conv, int size, t_struct *list);
void			ft_putstr_fd(char *s, int fd);
void			flag_star(va_list ap, t_struct *list);
char			*ft_strncpy(char *dest, char *src, unsigned int n);
char			*ft_strrchrp(const char *s, char c);
char			*ft_itoa(int n);
char			*ft_hexad(unsigned long long nb);
char			*ft_strtolower(char *str);
char			*ft_strtoupper(char *str);
int				ft_strlenp(const char *s);

#endif

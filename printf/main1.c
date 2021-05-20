#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "ft_printf.h"
int				ft_printf(const char *str, ...);

#define BPRINT(x, ...) PRINT("\"%s\" // 1st '*' = %d, 2nd '*' = %d\n", x, a, b)

int main()
{
	int		a = -4;
	int		b = 0;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	char	*s = "-2147483648";
	char	*t = "0x12345678";
	char	*u = "-0";
	int x = 0;

//	printf("%s\n", "Simple input test");
	printf("%0i, %0d, %0d, %0d, %0d, %0d, %0d, %0d", i, j, k, l, m, c, e, d); 
	

//	printf("%s\n", );(" --- Return : %d\n", printf("%s\n", "%0i, %0d, %0d, %0d, %0d, %0d, %0d, %0d", i, j, k, l, m, c, e, d); //T3
//	printf("%s\n", );(" --- Return : %d\n", printf("%s\n", "%1i, %1d, %1d, %1d, %1d, %1d, %1d, %1d", i, j, k, l, m, c, e, d); //T4

}
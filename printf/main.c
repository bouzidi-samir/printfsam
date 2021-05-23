#include "ft_printf.h"
#include "limits.h"

int main ()
{
	
//	char *str = "salut";
//	char *s2 = "coucou";
//	char *s3 = "sam";
//	char *s4 = "ola";
	//int j = 3;
	int x = 0;
	//	int j = 1;
//	i = ft_printf("%.*i", -6, -3);
//	i = ft_printf( %-3.2x %10.42x ", 1, -1);
//	i =ft_printf(" *%-*.*d* *%*.*d* ", 6, 2, 102, 10, 21, -101);	
//	i =ft_printf(" 0*%-0*d*0 0*%021d*0 ", 21, 1021, -1011);	
//	printf("%i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X", i, j, k, l, m, n, c, c, j, j, j);	
//	x = ft_printf( "%0*.*d",2, -2, 8);	"
		x = ft_printf( " %*.*s", 3, -1, "2");	
//	i = ft_printf(" %.*s ", 0, NULL);
	printf("%d" , x);
	write(1, "\n", 1);
	return(0);
}

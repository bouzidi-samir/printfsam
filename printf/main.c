#include "ft_printf.h"
#include "limits.h"

int main ()
{
//	char *str = "salut";
//	char *s2 = "coucou";
//	char *s3 = "sam";
//	char *s4 = "ola";
	//int j = 3;
	int i = 0;
	//	int j = 1;
//	i = ft_printf("%.*i", -6, -3);
//	i = ft_printf(" %-3.2x %10.42x ", 1, -1);
//	i =ft_printf(" *%-*.*d* *%*.*d* ", 6, 2, 102, 10, 21, -101);	
//	i =ft_printf(" *%*.*d* *%*.*d* ", -6, 2, 102, 10, 21, 101);	
//	i = ft_printf("%1.s", "4567");	
	i = ft_printf(" %10.s", "123");
	printf("%d" , i);
	write(1, "\n", 1);
	return(0);
}

#include "ft_printf.h"
#include "limits.h"

int main ()
{
int             a = -4;
          int             b = 0;
           char    c = 'a';
           int             d = 2147483647;
             int             e = -2147483648;
             int             f = 42;
               int             g = 25;
                int             h = 4200;
                 int             i = 8;
	          int             j = -12;
	           int             k = 123456789;
	          int             l = 0;
	             int             m = -12345678;
	              char    *n = "abcdefghijklmnop";
	              char    *o = "-a";
	                char    *p = "-12";
	                 char    *q = "0";
		          char    *r = "%%";
		           char    *s = "-2147483648";
		            char    *t = "0x12345678";
		             char    *u = "-0";
	
	
//	char *str = "salut";
//	char *s2 = "coucou";
//	char *s3 = "sam";
//	char *s4 = "ola";
	//int j = 3;
	int x = 0;
	//	int j = 1;
//	i = ft_printf("%.*i", -6, -3);
//	i = ft_printf(" %-3.2x %10.42x ", 1, -1);
//	i =ft_printf(" *%-*.*d* *%*.*d* ", 6, 2, 102, 10, 21, -101);	
//	i =ft_printf(" 0*%-0*d*0 0*%021d*0 ", 21, 1021, -1011);	
	printf("%i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X", i, j, k, l, m, n, c, c, j, j, j);	
//	i = ft_printf("%*d", 21, 10);	
//	i = ft_printf(" %.*s ", 0, NULL);
	printf("%d" , x);
	write(1, "\n", 1);
	return(0);
}

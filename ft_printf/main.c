#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int i = 156;
	unsigned int d = 65325;
	char c = 'c';
	char *adr = "lawda";
	char	*format = "la variable vaut : %s, %c, %i, %p, %x, %X, %%, %d, \n";
	char	*argument = "une string";
	int res;
	int tin = 6546;

	res = ft_printf(format, argument, c, i, &adr, d, d, tin);
	printf("%d\n", res);

	res = printf(format, argument, c, i, &adr, d, d, tin);
	printf("%d\n", res);
	return (0);
}
/* make re && cc main.c libftprintf.a ft_printf.h && clear && ./a.out */

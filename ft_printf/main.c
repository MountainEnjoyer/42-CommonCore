#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int i = 156;
	//float f = 654.354635435;
	char c = 'c';
	char *adr = "lawda";
	char	*format = "la variable vaut : %s, %c, %i, %p \n";
	char	*argument = "une string";

	ft_printf(format, argument, c, i, &adr);
	printf(format, argument, c, i, &adr);
	return (0);
}

#include "ft_printf.h"

int	main(void)
{
	char	*format = "la variable vaut : %s";
	char	*argument = "une string";

	ft_printf(format, argument);
	return (0);
}

#include <stdio.h>
#include "libft.h"
#include <string.h>
#include <ctype.h>

char	ft_test(unsigned int i, char c)
{
	printf("index[%d] = %c\n", i, c);
	return (c + 3);
}

int	main(void)
{
	char *r = ft_strmapi("test", ft_test);
	printf("main = %s\n", r);
	return (0);
}

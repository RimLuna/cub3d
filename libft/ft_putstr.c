#include "libft.h"

void	ft_putstr(const char *s)
{
	write(1, s, ft_strlen(s));
}
#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	while ((s1[0] == s2[0]) && (s1[0] != '\0' || s2[0] != '\0'))
	{
		s1++;
		s2++;
	}
	if (s1[0] == s2[0])
		return (0);
	else
		return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
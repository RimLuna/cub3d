#include "libft.h"
#include "struct.h"

int     ft_buf_len(t_buf *buf)
{
    int	i;

	i = 0;
	while (buf)
	{
		buf = buf->next;
		i++;
	}
	return (i);
}

t_buf 	*ft_buf_add(t_buf **buf, char *str)
{
	t_buf	*first;
	t_buf	*new;

	if (!str)
		return (NULL);
	if (!(new = (t_buf*)malloc(sizeof(*new))))
		return (0);
	new->str = str;
	new->next = NULL;
	if (!*buf)
		*buf = new;
	else
	{
		first = *buf;
		while ((*buf)->next)
			*buf = (*buf)->next;
		(*buf)->next = new;
		*buf = first;
	}
	return (new);
}

t_buf			*ft_buf_last(t_buf *buf)
{
	t_buf *tmp;

	if (!buf)
		return (NULL);
	while (buf->next)
	{
		tmp = buf;
		buf = buf->next;
	}
	ft_putstr(tmp->str);
	return (tmp);
}

int				ft_buf_clear(t_buf **buf)
{
	t_buf	*tmp;

	while (*buf)
	{
		tmp = (*buf)->next;
		free((*buf)->str);
		free(*buf);
		(*buf) = tmp;
	}
	return (0);
}

t_buf   *ft_split_buf(char const *s, char splitter)
{
	int i;
	int start;
	t_buf *buf;

	start = 0;
	i = 0;
	buf = NULL;
	while (s[i])
	{
		if (s[i] == splitter)
		{
			if (i - start > 0 && !ft_buf_add(&buf, ft_substr(s, start, i - start)))
				return (PTR_CAST(ft_buf_clear(&buf)));
			start = ++i;
		}
		else
			i++;
	}
	if (i - start > 0 && !ft_buf_add(&buf, ft_substr(s, start, i - start)))
		return (PTR_CAST(ft_buf_clear(&buf)));
	return (buf);
}
#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

# define PTR_CAST(a)	(void*)((uintptr_t)(a))

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

int     is_in(char c, char const *set);

char	*ft_strdup(char const *s1);

void			ft_putstr(const char *s);
int     ft_atoi(char const *str);

char    *ft_substr(char const *s, int start, int len);

size_t			ft_strlen(const char *s);

int				ft_strcmp(const char *s1, const char *s2);

char			*ft_strcpy(char *dst, const char *src);

char			*ft_strmerge(char *a, char *b);

char			*ft_strcat(char *s1, const char *s2);

char			*ft_strjoin(char const *s1, char const *s2);

void			*ft_memset(void *b, int c, size_t len);

void			ft_bzero(void *s, size_t n);

void			*ft_memcpy(void *dst, const void *src, size_t n);

void			*ft_memalloc(size_t size);

void			ft_memdel(void **ap);

char			*ft_strnew(size_t size);

void			ft_strdel(char **as);

char			*ft_strsub(char const *s, unsigned int start, size_t len);

t_list			*ft_lstnew(void const *content, size_t content_size);

void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));

void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));

void			ft_lstadd(t_list **alst, t_list *new);

#endif

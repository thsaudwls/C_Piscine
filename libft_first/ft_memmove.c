#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
const void	*s;
void	*d;
size_t	i;

s = src;
d = dst;
i = 0;
if (!dst && !src)
return (NULL);
if (d > s)
{
while (len-- > 0)
((unsigned char *)d)[len] = ((unsigned char *)s)[len];
}
else
{
while (i < len)
{
((unsigned char *)d)[i] = ((unsigned char *)s)[i];
i++;
}
}
return (dst);
}
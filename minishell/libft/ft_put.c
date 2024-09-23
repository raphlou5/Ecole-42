#include "libft.h"
#include <unistd.h>

void	ft_putstr(char *str)
{
	write(STDOUT_FILENO, str, ft_strlen(str));
}

void	ft_putstrnl(char *str) // putstr avec passage à la ligne
{
	ft_putstr(str);
	ft_putstr("\n");
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}
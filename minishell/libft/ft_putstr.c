#include <unistd.h>
#include "libft.h"

void	ft_putstr(char *str)
{
	write(STDOUT_FILENO, str, ft_strlen(str));
}

void	ft_putstrnl(char *str) // putstr avec passage à la ligne
{
	ft_putstr(str);
	ft_putstr("\n");
}
#include "minishell.h"

void	*var_error(char *message, t_var *var_to_free)
{
	if (var_to_free)
		free_var(var_to_free);
	ft_putstr_fd("Minishell: ", STDERR_FILENO);
	ft_putstr_fd(message, STDERR_FILENO);

	ft_putstr_fd("\n", STDERR_FILENO);
}
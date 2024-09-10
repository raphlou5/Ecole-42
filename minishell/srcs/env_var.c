#include "minishell.h"

t_var	*ft_key_and_value(char *str)
{
	int		i;
	t_var	*var;

	var = ft_calloc(1, sizeof(t_var));
	if (!var)
		return (var_error(ENV_ERROR, NULL));
	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	var->key = ft_substr(str, 0, i);
	if (!var->key)
		return (var_error(ENV_ERROR, var));
	str += i + 1;
	var->data = ft_strdup(str);
	if (!var->data)
		return (var_error(ENV_ERROR, var));
	return (var);
}

void	free_var(void *mem)
{
	t_var	*var;

	var = (t_var *)mem;
	free(var->key);
	free(var->data);
	free(var);
}

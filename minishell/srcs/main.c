#include "../libft/libft.h"
#include "minishell.h"

void write_header(void)
{
    ft_putstrnl("[36m        _       _     _          _ _");
	ft_putstrnl("[36m  /\\/\\ (_)_ __ (_)___| |__   ___| | |");
	ft_putstrnl("[36m /    \\| | '_ \\|  __| '_ \\ / _ \\ | |");
	ft_putstrnl("[36m/ /\\/\\ \\ | | | | \\__ \\ | | |  __/ | |");
	ft_putstrnl("\\/    \\/_|_| |_|_|___/_| |_|\\___|_|_|");
	ft_putstrnl("");
}
// pour pouvoir récuperer differentes informations sur l'environnement de notre minishell il est important que l'on récupère les variables d'enviroonement et que nous lesstockions,
// elles peuvent être utiliser par exemple pour recuperer le pwd ou encore le pid de notre shell
// pour stocker les informations ont va faire une liste chainée qui contiendra chaque information de l'environnement actuel
int	make_env(char **envp, t_list **var_list)
{
	t_var *var;
	t_list *data;
	int i;

	i = 0;
	*var_list = NULL;
	while (envp[i])
	{
		var = ft_key_and_value;
		if(!var)
		{
			ft_lstclear(var_list, free_var);
			return (0);
		}
		data = ft_list_new
		if (!data)
		{
			free_var(data);
			ft_lstclear(var_list, free_var);
			return (0);
		}
		ft_lstadd_back(var_list, data);
		i++;
	}

	
	return (1);
}
int main(void)
{
    write_header();
}
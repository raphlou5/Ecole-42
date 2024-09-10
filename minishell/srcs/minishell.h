#ifndef MINISHELL_H

# define MINISHELL_H
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

# define ENV_ERROR	"Error while creating an environment variable"

typedef struct s_var {
    char *key;
    char *data;
} t_var;

// liste chainées
void ft_list_new(void *data);
void	free_var(void *mem);

// env
t_var	*ft_key_and_value(char *str);

//erreurs
void	*var_error(char *message, t_var *var_to_free);

#endif
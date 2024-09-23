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

// liste chainée pour l'executing

typedef struct s_command
{
    char *cmd;            // Commande principale
    char **args;          // Arguments de la commande
    char *input_file;     // Fichier pour la redirection d'entrée
    char *output_file;    // Fichier pour la redirection de sortie
    int append;           // 1 si redirection avec '>>', sinon 0
    int pipe;             // 1 si un pipe est présent après la commande
    struct s_command *next; // Pointeur vers la prochaine commande dans le pipeline
} t_command;


// liste chainées
void ft_list_new(void *data);
void	free_var(void *mem);

// env
t_var	*ft_key_and_value(char *str);

//erreurs
void	*var_error(char *message, t_var *var_to_free);

#endif
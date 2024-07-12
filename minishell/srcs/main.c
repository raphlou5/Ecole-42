#include "../libft/libft.h"

void write_header(void)
{
    ft_putstrnl("\x1B[36m        _       _     \x1B[34m_          _ _");
	ft_putstrnl("\x1B[36m  /\\/\\ (_)_ __ (_)\x1B[34m___| |__   ___| | |");
	ft_putstrnl("\x1B[36m /    \\| | '_ \\| \x1B[34m/ __| '_ \\ / _ \\ | |");
	ft_putstrnl("\x1B[36m/ /\\/\\ \\ | | | | \x1B[34m\\__ \\ | | |  __/ | |");
	ft_putstrnl("\x1B[36m\\/    \\/_|_| |_|_\x1B[34m|___/_| |_|\\___|_|_|");
	ft_putstrnl("");
}
// pour pouvoir récuperer differentes informations sur l'environnement de notre minishell il est important que l'on récupère les variables d'enviroonement et que nous lesstockions,
// elles peuvent être utiliser par exemple pour recuperer le pwd ou encore le pid de notre shell
// pour stocker les informations ont va faire une liste chainée qui contiendra chaque information de l'environnement actuel
int main(void)
{
    write_header();
}
#include "philo.h"

int		main(int argc, char **argv)
{
	t_info	info;
	int		ret;

	if (argc != 5 && argc != 6)
	{
		printf("mauvais nombres d'arguments");
		return (0);
	}
	if ((ret = init_all(&info, argv)))
	{
		printf("error");
		return (0);
	}
	if (philo(&info))
	{
		printf("erreur creation thread");
		return (0);
	}
	return (0);
}
#include "philo.h"

int	init_mutex(t_info *info)
{
	int i;

	i = info->nb_philo;
	while (--i >= 0)
	{
		if (pthread_mutex_init(&(info->forks[i]), NULL))
			return (1);
	}
	if (pthread_mutex_init(&(info->writing), NULL))
		return (1);
	if (pthread_mutex_init(&(info->meal_check), NULL))
		return (1);
	return (0);
}

int	init_philosophers(t_info *info)
{
	int i;

	i = info->nb_philo;
	while (--i >= 0)
	{
		info->philosophers[i].id = i;
		info->philosophers[i].x_ate = 0;
		info->philosophers[i].left_fork_id = i;
		info->philosophers[i].right_fork_id = (i + 1) % info->nb_philo;
		info->philosophers[i].t_last_meal = 0;
		info->philosophers[i].info = info;
	}
	return (0);
}

int	init_all(t_info *info, char **argv)
{
	info->nb_philo = ft_atoi(argv[1]);
	info->time_death = ft_atoi(argv[2]);
	info->time_eat = ft_atoi(argv[3]);
	info->time_sleep = ft_atoi(argv[4]);
	info->all_ate = 0;
	info->dieded = 0;
	if (info->nb_philo < 2 || info->time_death < 0 || info->time_eat < 0
		|| info->time_sleep < 0 || info->nb_philo > 250)
		return (1);
	if (argv[5])
	{
		info->nb_eat = ft_atoi(argv[5]);
		if (info->nb_eat <= 0)
			return (1);
	}
	else
		info->nb_eat = -1;
	if (init_mutex(info))
		return (1);
	init_philosophers(info);
	return (0);
}
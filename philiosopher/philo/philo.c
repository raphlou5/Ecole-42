#include "philo.h"

void	philo_eats(t_philosopher *philo)
{
	t_info *info;

	info = philo->info;
	pthread_mutex_lock(&(info->forks[philo->left_fork_id]));
	philo_write(info, philo->id, "has taken a fork");
	pthread_mutex_lock(&(info->forks[philo->right_fork_id]));
	philo_write(info, philo->id, "has taken a fork");
	pthread_mutex_lock(&(info->meal_check));
	philo_write(info, philo->id, "is eating");
	philo->t_last_meal = timestamp();
	pthread_mutex_unlock(&(info->meal_check));
	smart_sleep(info->time_eat, info);
	(philo->x_ate)++;
	pthread_mutex_unlock(&(info->forks[philo->left_fork_id]));
	pthread_mutex_unlock(&(info->forks[philo->right_fork_id]));
}

void	*p_thread(void *void_philosopher)
{
	int				i;
	t_philosopher	*philo;
	t_info			*info;

	i = 0;
	philo = (t_philosopher *)void_philosopher;
	info = philo->info;
	if (philo->id % 2)
		usleep(15000);
	while (!(info->dieded))
	{
		philo_eats(philo);
		if (info->all_ate)
			break ;
		philo_write(info, philo->id, "is sleeping");
		smart_sleep(info->time_sleep, info);
		philo_write(info, philo->id, "is thinking");
		i++;
	}
	return (NULL);
}

void	exit_philo(t_info *info, t_philosopher *philos)
{
	int i;

	i = -1;
	while (++i < info->nb_philo)
		pthread_join(philos[i].thread_id, NULL);
	i = -1;
	while (++i < info->nb_philo)
		pthread_mutex_destroy(&(info->forks[i]));
	pthread_mutex_destroy(&(info->writing));
}

void	death_checker(t_info *info, t_philosopher *p)
{
	int i;

	while (!(info->all_ate))
	{
		i = -1;
		while (++i < info->nb_philo && !(info->dieded))
		{
			pthread_mutex_lock(&(info->meal_check));
			if (time_diff(p[i].t_last_meal, timestamp()) > info->time_death)
			{
				philo_write(info, i, "died");
				info->dieded = 1;
			}
			pthread_mutex_unlock(&(info->meal_check));
			usleep(100);
		}
		if (info->dieded)
			break ;
		i = 0;
		while (info->nb_eat != -1 && i < info->nb_philo && p[i].x_ate >= info->nb_eat)
			i++;
		if (i == info->nb_philo)
			info->all_ate = 1;
	}
}

int		philo(t_info *info)
{
	int				i;
	t_philosopher	*philo;

	i = 0;
	philo = info->philosophers;
	info->first_timestamp = timestamp();
	while (i < info->nb_philo)
	{
		if (pthread_create(&(philo[i].thread_id), NULL, p_thread, &(philo[i])))
			return (1);
		philo[i].t_last_meal = timestamp();
		i++;
	}
	death_checker(info, info->philosophers);
	exit_philo(info, philo);
	return (0);
}
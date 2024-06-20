#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>

struct s_info;

typedef	struct			s_philosopher
{
	int					id;
	int					x_ate;
	int					left_fork_id;
	int					right_fork_id;
	long long			t_last_meal;
	struct s_info		*info;
	pthread_t			thread_id;
}						t_philosopher;

typedef struct			s_info
{
	int					nb_philo;
	int					time_death;
	int					time_eat;
	int					time_sleep;
	int					nb_eat;
	int					dieded;
	int					all_ate;
	long long			first_timestamp;
	pthread_mutex_t		meal_check;
	pthread_mutex_t		forks[250];
	pthread_mutex_t		writing;
	t_philosopher		philosophers[250];
}						t_info;


void		philo_write(t_info *info, int id, char *string);
int		philo(t_info *info);
int	ft_atoi(char *str);
long long	timestamp(void);
long long	time_diff(long long past, long long pres);
void		smart_sleep(long long time, t_info *info);
int	init_all(t_info *info, char **argv);

#endif
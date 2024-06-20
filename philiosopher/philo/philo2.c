#include "philo.h"

void		philo_write(t_info *info, int id, char *string)
{
	pthread_mutex_lock(&(info->writing));
	if (!(info->dieded))
	{
		printf("%lli ", timestamp() - info->first_timestamp);
		printf("%i ", id + 1);
		printf("%s\n", string);
	}
	pthread_mutex_unlock(&(info->writing));
	return ;
}
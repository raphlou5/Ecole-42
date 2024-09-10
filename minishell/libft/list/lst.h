#ifndef LST_H

# define LST_H
# include <stdlib.h>

typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}				t_list;

void ft_lst_new(void *data);

#endif

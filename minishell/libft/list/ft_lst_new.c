#include "list.h"

void ft_lst_new(void *data)
{
    t_list *content;

    content = (t_list *)malloc(sizeof(t_list));
    if(!content)
        return (NULL);
    content->next = NULL;
    content->data = data;
    return(content);
}

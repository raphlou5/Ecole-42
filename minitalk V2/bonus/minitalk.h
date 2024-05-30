/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevast <elevast@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 08:54:27 by elevast           #+#    #+#             */
/*   Updated: 2024/05/30 13:14:30 by elevast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "printf/ft_printf.h"
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

void	check_pid(int pid);
void	check_the_end(char *str);
void	check_the_message(char *str);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size);
int		ft_atoi(const char *str);

#endif

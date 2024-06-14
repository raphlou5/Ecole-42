/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_both.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevast <elevast@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 09:18:58 by elevast           #+#    #+#             */
/*   Updated: 2024/06/14 09:19:21 by elevast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	rev_rotate_both(t_stack_node **a,
								t_stack_node **b,
								t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node
		&& *a != cheapest_node)
		rrr(a, b);
	current_index(*a);
	current_index(*b);
}

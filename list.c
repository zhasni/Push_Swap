/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 11:28:11 by zhasni            #+#    #+#             */
/*   Updated: 2015/03/04 14:45:22 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push.h"

t_push		*ft_elem(int nb)
{
	t_push	*node;

	node = (t_push*)malloc(sizeof(t_push));
	if (node)
	{
		node->nb = nb;
		node->next = NULL;
	}
	else
		return (NULL);
	return (node);
}

t_push		*ft_del_elem(t_push *lst)
{
	free(lst);
	lst = lst->next;
	return (lst);
}

void		ft_init(t_env *env)
{
	env->stack_size_a = 0;
	env->stack_size_b = 0;
	env->mv = 0;
	env->opt_v = 0;
	env->opt_c = 0;
	env->opt_l = 0;
	env->opt_s = 0;
	env->opt_m = 0;
}

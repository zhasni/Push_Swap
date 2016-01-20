/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 11:28:57 by zhasni            #+#    #+#             */
/*   Updated: 2015/03/04 14:46:21 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push.h"

void		ft_push_b(t_push **a, t_push **b, t_env *env)
{
	ft_push_front(b, ft_elem((*a)->nb));
	*a = ft_del_elem(*a);
	env->stack_size_a -= 1;
	env->stack_size_b += 1;
	ft_putstr("pb ");
	if (env->opt_v == 1 && env->opt_c == 1)
		ft_print_step_color(*a, *b);
	else if (env->opt_v == 1 && env->opt_c == 0)
		ft_print_step(*a, *b);
	env->mv++;
}

void		ft_push_a(t_push **a, t_push **b, t_env *env)
{
	ft_push_front(a, ft_elem((*b)->nb));
	*b = ft_del_elem(*b);
	env->stack_size_a += 1;
	env->stack_size_b -= 1;
	if (env->opt_c == 1 && env->stack_size_b == 0)
		ft_putstr_color_fd("\033[0;31m", "pa", 1);
	else if (env->stack_size_b == 0)
		ft_putstr("pa");
	else
		ft_putstr("pa ");
	if (env->opt_v == 1 && env->opt_c == 1)
		ft_print_step_color(*a, *b);
	else if (env->opt_v == 1 && env->opt_c == 0)
		ft_print_step(*a, *b);
	env->mv++;
}

void		ft_push_back(t_push **head, t_push *elem)
{
	t_push	*e;

	if (*head)
	{
		e = *head;
		while (e->next)
			e = e->next;
		e->next = elem;
	}
	else
		*head = elem;
}

void		ft_push_front(t_push **head, t_push *elem)
{
	elem->next = *head;
	*head = elem;
}

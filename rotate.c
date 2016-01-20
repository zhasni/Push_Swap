/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 11:29:33 by zhasni            #+#    #+#             */
/*   Updated: 2015/03/04 14:46:33 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push.h"

t_push		*ft_rotate(t_push *lst)
{
	int		tmp;
	t_push	*e;

	e = lst;
	while (e->next)
	{
		tmp = e->nb;
		e->nb = e->next->nb;
		e->next->nb = tmp;
		e = e->next;
	}
	return (lst);
}

t_push		*ft_rotate_a(t_push *lst, t_push *b, t_env *env)
{
	int		tmp;
	t_push	*e;

	e = lst;
	while (e->next)
	{
		tmp = e->nb;
		e->nb = e->next->nb;
		e->next->nb = tmp;
		e = e->next;
	}
	if (env->mv == 0 && ft_check_sort(lst) == 0 && env->opt_c == 1)
		ft_putstr_color_fd("\033[0;31m", "ra", 1);
	else
		ft_putstr("ra ");
	if (env->opt_v == 1 && env->opt_c == 1)
		ft_print_step_color(lst, b);
	else if (env->opt_v == 1 && env->opt_c == 0)
		ft_print_step(lst, b);
	env->mv++;
	return (lst);
}

t_push		*ft_rotate_b(t_push *lst, t_push *b, t_env *env)
{
	int		tmp;
	t_push	*e;

	e = lst;
	while (e->next)
	{
		tmp = e->nb;
		e->nb = e->next->nb;
		e->next->nb = tmp;
		e = e->next;
	}
	if (env->mv == 0 && ft_check_sort(lst) == 0 && env->opt_c == 1)
		ft_putstr_color_fd("\033[0;31m", "rb", 1);
	else if (env->mv == 0 && ft_check_sort(lst) == 0)
		ft_putstr("rb");
	else
		ft_putstr("rb ");
	if (env->opt_v == 1 && env->opt_c == 1)
		ft_print_step_color(lst, b);
	else if (env->opt_v == 1 && env->opt_c == 0)
		ft_print_step(lst, b);
	env->mv++;
	return (lst);
}

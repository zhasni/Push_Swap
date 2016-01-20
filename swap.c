/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 11:29:58 by zhasni            #+#    #+#             */
/*   Updated: 2015/03/04 14:47:27 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push.h"

t_push	*ft_swap(t_push *lst)
{
	int tmp;

	if (!lst)
		exit (-1);
	tmp = lst->nb;
	lst->nb = lst->next->nb;
	lst->next->nb = tmp;
	return (lst);
}

t_push	*ft_swap_a(t_push *lst, t_push *b, t_env *env)
{
	int tmp;

	if (!lst)
		exit (-1);
	tmp = lst->nb;
	lst->nb = lst->next->nb;
	lst->next->nb = tmp;
	if (env->mv == 0 && ft_check_sort(lst) == 0 && env->opt_c == 1)
		ft_putstr_color_fd("\033[0;31m", "sa", 1);
	else if (env->mv == 0 && ft_check_sort(lst) == 0)
		ft_putstr("sa ");
	else
		ft_putstr("sa ");
	if (env->opt_v == 1 && env->opt_c == 1)
		ft_print_step_color(lst, b);
	else if (env->opt_v == 1 && env->opt_c == 0)
		ft_print_step(lst, b);
	env->mv++;
	return (lst);
}

t_push	*ft_swap_b(t_push *lst)
{
	int tmp;

	if (!lst)
		exit (-1);
	tmp = lst->nb;
	lst->nb = lst->next->nb;
	lst->next->nb = tmp;
	ft_putstr("sb ");
	return (lst);
}

void	ft_swap_s(t_push **a, t_push **b, t_env *env)
{
	ft_swap_a(*a, *b, env);
	ft_swap_b(*b);
	ft_putstr("ss ");
}

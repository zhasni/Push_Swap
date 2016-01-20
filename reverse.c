/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 11:29:19 by zhasni            #+#    #+#             */
/*   Updated: 2015/03/04 14:46:27 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push.h"

t_push		*ft_reverse_rotate(t_push *lst, int k)
{
	int tmp;

	tmp = 0;
	while (tmp < k - 1)
	{
		ft_rotate(lst);
		tmp++;
	}
	return (lst);
}

t_push		*ft_reverse_rotate_a(t_push *lst, t_push *b, int size, t_env *env)
{
	int tmp;

	tmp = 0;
	while (tmp < size - 1)
	{
		ft_rotate(lst);
		tmp++;
	}
	if (ft_check_sort(lst) == 0 && env->opt_c == 1)
		ft_putstr_color_fd("\033[0;31m", "rra", 1);
	else if (ft_check_sort(lst) == 0 && env->stack_size_b == 0)
		ft_putstr("rra");
	else
		ft_putstr("rra ");
	if (env->opt_v == 1 && env->opt_c == 1)
		ft_print_step_color(lst, b);
	else if (env->opt_v == 1 && env->opt_c == 0)
		ft_print_step(lst, b);
	env->mv++;
	return (lst);
}

t_push		*ft_reverse_rotate_b(t_push *lst, t_push *a, int size, t_env *env)
{
	int tmp;

	tmp = 0;
	while (tmp < size - 1)
	{
		ft_rotate(lst);
		tmp++;
	}
	if (env->mv == 0 && ft_check_sort(lst) == 0 && env->opt_c == 1)
		ft_putstr_color_fd("\033[0;31m", "rra", 1);
	else
		ft_putstr("rra ");
	if (env->opt_v == 1 && env->opt_c == 1)
		ft_print_step_color(lst, a);
	else if (env->opt_v == 1 && env->opt_c == 0)
		ft_print_step(lst, a);
	env->mv++;
	return (lst);
}

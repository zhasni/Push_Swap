/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 11:28:26 by zhasni            #+#    #+#             */
/*   Updated: 2015/03/04 14:45:07 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push.h"

void		ft_tri_insert_v1(t_push **a, t_push **b, t_env *env)
{
	int		tmp;
	t_push	*e;

	if ((*a)->nb > (*a)->next->nb)
		*a = ft_swap_a(*a, *b, env);
	while (env->stack_size_a > 0 && ft_check_sort(*a) == 1)
	{
		tmp = (*a)->nb;
		e = *a;
		*a = ft_rotate_a(*a, *b, env);
		while (e->nb != tmp)
		{
			if (tmp > e->nb)
				tmp = e->nb;
			*a = ft_rotate_a(*a, *b, env);
		}
		ft_push_b(a, b, env);
	}
	while (env->stack_size_b > 0)
		ft_push_a(a, b, env);
}

void		ft_tri_begin(t_push **a, t_push **b, t_env *env)
{
	if ((*a)->nb > (*a)->next->nb)
		*a = ft_swap_a(*a, *b, env);
	while (env->stack_size_b > 0)
		ft_push_a(a, b, env);
}

void		ft_tri_insert_v2(t_push **a, t_push **b, t_env *env)
{
	int		pos;
	int		i;

	ft_tri_begin(a, b, env);
	while (env->stack_size_a > 2 && ft_check_sort(*a) == 1)
	{
		i = 0;
		pos = ft_check_rotate(*a);
		if (pos > (env->stack_size_a / 2))
		{
			pos = env->stack_size_a - pos;
			while (i++ < pos)
				ft_reverse_rotate_a(*a, *b, env->stack_size_a, env);
		}
		else
		{
			while (i++ < pos)
				ft_rotate_a(*a, *b, env);
		}
		if (ft_check_sort(*a) == 1)
			ft_push_b(a, b, env);
		else
			break ;
	}
	ft_tri_begin(a, b, env);
}

void		ft_lst_sort(int ac, char **av, t_env *env, int i)
{
	t_push	*swap_a;
	t_push	*swap_b;

	swap_a = NULL;
	swap_b = NULL;
	if (ft_is_int(av + i) == -1)
		exit(ft_error(1));
	while (i < ac)
	{
		ft_push_back(&swap_a, ft_elem(ft_atoi(av[i])));
		i++;
		env->stack_size_a++;
	}
	if (env->opt_s == 1)
		ft_tri_insert_v1(&swap_a, &swap_b, env);
	else if (ac < 10)
		ft_tri_insert_v2(&swap_a, &swap_b, env);
	else
		ft_tri_insert_v2(&swap_a, &swap_b, env);
	ft_putchar('\n');
	if (env->opt_l == 1)
		ft_print_lst_backn(swap_a, env);
	if (env->opt_m == 1)
		ft_print_move(env);
}

int			main(int ac, char **av)
{
	t_env	env;

	ft_init(&env);
	if (ac > 2)
		ft_check_options(ac, av, &env);
	else if (ac == 2 && ft_strcmp(av[1], "help") != 0)
	{
		if (ft_is_int(av + 1) == -1)
			exit(ft_error(1));
		return (0);
	}
	else
	{
		if (av[1] != NULL && ft_strcmp(av[1], "help") == 0)
			ft_help();
		ft_error(3);
		ft_putendl("Write 'help' for options description");
		exit(3);
	}
	ft_putchar('\n');
	return (0);
}

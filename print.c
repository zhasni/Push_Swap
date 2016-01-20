/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 11:28:11 by zhasni            #+#    #+#             */
/*   Updated: 2015/03/04 14:46:15 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push.h"

void		ft_print_step(t_push *a, t_push *b)
{
	ft_putstr("\n\n-------------------------------");
	ft_putstr("stack_a-------------------------------\n\n");
	ft_print_lst_space(a);
	ft_putstr("\n\n----------------------------------");
	ft_putstr("-----------------------------------\n");
	ft_putstr("-------------------------------");
	ft_putstr("stack_b-------------------------------\n\n");
	ft_print_lst_space(b);
	ft_putstr("\n\n----------------------------------");
	ft_putstr("-----------------------------------\n\n");
}

void		ft_print_step_color(t_push *a, t_push *b)
{
	ft_putstr_color_fd("\033[0;34m",
		"\n\n-------------------------------", 1);
	ft_putstr_color_fd("\033[0;34m",
		"stack_a-------------------------------\n\n", 1);
	ft_print_lst_space(a);
	ft_putstr_color_fd("\033[0;34m",
		"\n\n----------------------------------", 1);
	ft_putstr_color_fd("\033[0;34m",
		"-----------------------------------\n", 1);
	ft_putstr_color_fd("\033[0;31m",
		"-------------------------------", 1);
	ft_putstr_color_fd("\033[0;31m",
		"stack_b-------------------------------\n\n", 1);
	ft_print_lst_space(b);
	ft_putstr_color_fd("\033[0;31m",
		"\n\n----------------------------------", 1);
	ft_putstr_color_fd("\033[0;31m",
		"-----------------------------------\n\n", 1);
}

void		ft_print_lst_space(t_push *lst)
{
	while (lst)
	{
		ft_putnbr(lst->nb);
		ft_putchar(' ');
		lst = lst->next;
	}
}

void		ft_print_lst_backn(t_push *lst, t_env *env)
{
	if (env->opt_c == 1)
	{
		while (lst)
		{
			ft_putnbr_color_fd("\033[0;35m", lst->nb, 1);
			ft_putchar('\n');
			lst = lst->next;
		}
	}
	else
	{
		while (lst)
		{
			ft_putnbr(lst->nb);
			ft_putchar('\n');
			lst = lst->next;
		}
	}
}

void		ft_print_move(t_env *env)
{
	if ((env->opt_m == 1 && env->opt_l == 1) || (env->opt_m == 1 && env->opt_c)
			== 1)
		ft_putnbr_color_fd("\033[0;35m", env->mv, 1);
	else
		ft_putnbr(env->mv);
}

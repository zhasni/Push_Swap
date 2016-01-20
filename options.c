/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 11:28:26 by zhasni            #+#    #+#             */
/*   Updated: 2015/03/04 18:36:06 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push.h"

void	ft_check_options_ter(int ac, char **av, t_env *env)
{
	if ((ft_strcmp(av[1], "-mc") == 0 || ft_strcmp(av[1], "-cm") == 0))
	{
		env->opt_c = 1;
		env->opt_m = 1;
	}
	else if ((ft_strcmp(av[1], "-vs") == 0 || ft_strcmp(av[1], "-sv") == 0))
	{
		env->opt_v = 1;
		env->opt_s = 1;
	}
	if (ft_strcmp(av[1], "-v") == 0)
		env->opt_v = 1;
	else if (ft_strcmp(av[1], "-c") == 0)
		env->opt_c = 1;
	else if (ft_strcmp(av[1], "-s") == 0)
		env->opt_s = 1;
	else if (ft_strcmp(av[1], "-l") == 0)
		env->opt_l = 1;
	else if (ft_strcmp(av[1], "-m") == 0)
		env->opt_m = 1;
	if (env->opt_v > 0 || env->opt_c > 0 || env->opt_s > 0 || env->opt_l > 0
		|| env->opt_m > 0)
		ft_lst_sort(ac, av, env, 2);
	else
		ft_lst_sort(ac, av, env, 1);
}

void	ft_check_options_bis(int ac, char **av, t_env *env)
{
	if ((ft_strcmp(av[1], "-lm") == 0 || ft_strcmp(av[1], "-ml") == 0))
	{
		env->opt_l = 1;
		env->opt_m = 1;
	}
	else if ((ft_strcmp(av[1], "-sc") == 0 || ft_strcmp(av[1], "-cs") == 0))
	{
		env->opt_s = 1;
		env->opt_c = 1;
	}
	else if ((ft_strcmp(av[1], "-sl") == 0 || ft_strcmp(av[1], "-ls") == 0))
	{
		env->opt_s = 1;
		env->opt_l = 1;
	}
	else if ((ft_strcmp(av[1], "-sm") == 0 || ft_strcmp(av[1], "-ms") == 0))
	{
		env->opt_s = 1;
		env->opt_m = 1;
	}
	ft_check_options_ter(ac, av, env);
}

void	ft_check_options(int ac, char **av, t_env *env)
{
	if ((ft_strcmp(av[1], "-vc") == 0 || ft_strcmp(av[1], "-cv") == 0))
	{
		env->opt_c = 1;
		env->opt_v = 1;
	}
	else if ((ft_strcmp(av[1], "-vl") == 0 || ft_strcmp(av[1], "-lv") == 0))
	{
		env->opt_l = 1;
		env->opt_v = 1;
	}
	else if ((ft_strcmp(av[1], "-vm") == 0 || ft_strcmp(av[1], "-mv") == 0))
	{
		env->opt_m = 1;
		env->opt_v = 1;
	}
	else if ((ft_strcmp(av[1], "-lc") == 0 || ft_strcmp(av[1], "-cl") == 0))
	{
		env->opt_c = 1;
		env->opt_l = 1;
	}
	ft_check_options_bis(ac, av, env);
}

void	ft_help(void)
{
	ft_putendl("options available are :\n");
	ft_putendl("	-v	print the stacks between each step\n");
	ft_putendl("	-c	print the last move in color\n");
	ft_putendl("	-l	print the stack_a sorted\n");
	ft_putendl("	-s	speed sorting but many many moves\n");
	ft_putendl("	-m	print the total of moves\n");
	ft_putendl("two opts allowed -vc -vl -vs -vm -lc -lm -ls -sc -sm -mc");
	exit(0);
}

int		ft_error(int x)
{
	if (x == 1)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("(number is not a number !!!)", 2);
	}
	else if (x == 2)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("(int overflow !!!)", 2);
	}
	else if (x == -1)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("(2 numbers identical !!!)", 2);
	}
	else
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("(entrer at leat 1 number !!!)", 2);
	}
	return (x);
}

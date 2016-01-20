/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 11:28:26 by zhasni            #+#    #+#             */
/*   Updated: 2015/03/04 14:45:14 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push.h"

int			ft_check_sort(t_push *lst)
{
	while (lst->next)
	{
		if (lst->nb > lst->next->nb)
			return (1);
		lst = lst->next;
	}
	return (0);
}

int			ft_check_rotate(t_push *lst)
{
	t_push	*e;
	int		tmp;
	int		i;
	int		k;

	i = 0;
	k = 0;
	tmp = lst->nb;
	e = lst;
	while (e->next)
	{
		if (tmp >= e->nb)
		{
			tmp = e->nb;
			k = i;
		}
		i++;
		e = e->next;
	}
	if (tmp > e->nb)
		return (i);
	return (k);
}

int			ft_is_num(char **str)
{
	int		i;
	int		j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] < 48 || str[i][j] > 57)
			{
				if (str[i][j] == 45 || str[i][j] == 43)
				{
					j++;
					continue;
				}
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int			ft_is_int(char **str)
{
	int		i;
	int		j;
	int		tmp;

	i = 0;
	if (ft_is_num(str) == -1)
		return (-1);
	while (str[i])
	{
		tmp = ft_atol_max_int(str[i]);
		j = i + 1;
		while (str[j])
		{
			if (tmp == ft_atol_max_int(str[j]))
				exit(ft_error(-1));
			j++;
		}
		i++;
	}
	return (0);
}

int			ft_atol_max_int(char *str)
{
	long	nb;
	int		neg;

	nb = 0;
	neg = 1;
	if (*str == '-')
	{
		neg = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str == '0')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		nb = (nb * 10) + *str - '0';
		str++;
	}
	nb *= neg;
	if (nb < -2147483648 || nb > 2147483647)
		exit(ft_error(2));
	return ((int)nb);
}

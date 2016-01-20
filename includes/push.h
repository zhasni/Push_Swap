/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 11:48:31 by zhasni            #+#    #+#             */
/*   Updated: 2015/03/04 10:09:53 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PUSH_H
# define _PUSH_H

# include "../libft/libft.h"

# include <stdlib.h>

typedef struct		s_push
{
	int				nb;
	struct s_push	*next;
}					t_push;

typedef struct		s_env
{
	int				stack_size_a;
	int				stack_size_b;
	int				mv;
	int				max;
	int				min;
	int				mid;
	int				*tab;
	int				opt_v;
	int				opt_c;
	int				opt_l;
	int				opt_s;
	int				opt_m;
}					t_env;

void				ft_push_b(t_push **a, t_push **b, t_env *env);
void				ft_push_a(t_push **a, t_push **b, t_env *env);
void				ft_push_back(t_push **head, t_push *elem);
void				ft_push_front(t_push **head, t_push *elem);
t_push				*ft_elem(int nb);
t_push				*ft_del_elem(t_push *lst);
t_push				*ft_swap_a(t_push *lst, t_push *b, t_env *env);
t_push				*ft_rotate_a(t_push *lst, t_push *b, t_env *env);
t_push				*ft_reverse_rotate_a(t_push *lst, t_push *b, int size,
						t_env *env);
t_push				*ft_rotate(t_push *lst);
void				ft_print_lst_space(t_push *lst);
void				ft_init(t_env *env);
void				ft_print_step(t_push *a, t_push *b);
void				ft_print_step(t_push *a, t_push *b);
void				ft_print_step_color(t_push *a, t_push *b);
void				ft_print_lst_backn(t_push *lst, t_env *env);
void				ft_print_move(t_env *env);
int					ft_check_sort(t_push *lst);
int					ft_check_sort(t_push *lst);
int					ft_check_rotate(t_push *lst);
int					ft_is_num(char **str);
int					ft_is_int(char **str);
void				ft_check_options(int ac, char **av, t_env *env);
void				ft_check_options_bis(int ac, char **av, t_env *env);
void				ft_check_options_ter(int ac, char **av, t_env *env);
void				ft_help(void);
int					ft_error(int x);

void				ft_putnbr_color_fd(char *color, int n, int fd);

int					ft_atol_max_int(char *str);
void				ft_lst_sort(int ac, char **av, t_env *env, int i);
t_push				*ft_rotate_b(t_push *lst, t_push *a, t_env *env);
void				ft_tri_insert_v3(t_push **a, t_push **b, t_env *env);
t_push				*ft_reverse_rotate_b(t_push *lst, t_push *a, int size,
						t_env *env);

#endif

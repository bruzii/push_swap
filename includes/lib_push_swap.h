/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_push_swap.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgervais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:19:23 by bgervais          #+#    #+#             */
/*   Updated: 2022/12/23 19:39:55 by bgervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIB_PUSH_SWAP_H
# define LIB_PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

typedef struct t_point
{
	int	*cout_a;
	int	*valeur;
	int	*cout_b;
}	t_point;

void	ft_sa(t_list **lst);
void	ft_sb(t_list **lst);
void	ft_ra(t_list **lst);
void	ft_rb(t_list **lst);
void	ft_rr(t_list **lst, t_list **lst2);
void	ft_rra(t_list **lst);
void	ft_rrb(t_list **lst);
void	ft_rrr(t_list **lst, t_list **lst2);
void	ft_r(t_list **list);
void	ft_pull(t_list **lst);
void	ft_pb(t_list **lst, t_list **lst2);
void	ft_pa(t_list **lst, t_list **lst2);
t_list	*ft_create(t_list **lst, int pos);
void	ft_p(t_list **lst, t_list **lst2);
void	ft_s(t_list **lst);
void	ft_short(t_list **lst_a);
void	ft_is_5(t_list **lst_a);
void	ft_is_3(t_list **lst);
void	ft_clear_and_copy(t_list **lst, t_list **new);
void	ft_lstclear_bis(t_list **lst);
void	ft_free_p(t_point p);
void	ft_clear_element(t_list **lst);
void	ft_print(t_list	**lst);
void	ft_good_pos(t_list **lst_a, t_list **lst_b);
void	ft_is_algo(t_list **lst_a, t_list **lst_b, t_point p, int pos);
void	ft_good_pos_unique(t_list	**lst_a);
void	ft_replace(t_list **lst_a);
void	bubble_sort(t_list **arr);
int		ft_algo_best_pos(t_point p);
int		ft_find_pos_min(t_list **lst_a);
int		ft_best_option(int value, int len, t_list **lst);
int		ft_is_no_option1(int value, t_list **lst);
t_point	ft_cost_value_b(t_list	**lst_b);
t_point	ft_cost_value_a(t_list **lst_a, t_list	**lst_b);
t_list	*ft_push_all_to_b(t_list **lst_a);

int		ft_check_string(char *str);
int		ft_sort(t_list	**nbr);
int		ft_find_bro(t_list **lst, int value);
int		ft_check(char *str);
int		ft_check_int(char *str);
int		*ft_recup_one(char *str);
int		*ft_recup(int argc, char **argv);
int		ft_is_min(t_list **lst);
int		ft_check_double_one(char *str, int *nbr);
int		ft_check_double(int len, int *nbr);
int		ft_is_sorted(t_list	**lst);
int		ft_check_total(char *str);
t_list	*ft_recup_list(int argc, char **argv);
t_list	*ft_recup_list_one(char *str);
t_list	*ft_create_and_delete(t_list **lst, int pos);
t_list	*creat_elem(int data, int pos);
t_list	*ft_create_element(int pos);
t_list	*ft_copy(t_list **lst);

#endif

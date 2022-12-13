#ifndef LIB_PUSH_SWAP_H
# define LIB_PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
#include "libft.h"

typedef struct t_point
{
	int	*cout_a;
	int	*count_b_bis;
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
void	ft_is_3(t_list  **lst);
void	ft_less_one(t_list **lst);
void	ft_clear_element(t_list **lst);
void	ft_good_pos(t_list **lst_a, t_list **lst_b);
void	ft_is_algo(t_list **lst_a, t_list **lst_b, t_point p);
void	ft_good_pos_unique(t_list   **lst_a);
int		ft_algo_best_pos(t_point p);
t_list	*ft_push_all_to_b(t_list **lst_a);
int		ft_check(char *str);
int		*ft_recup(char *str);
t_list	*ft_recup_list(char *str);
t_list	*ft_create_and_delete(t_list **lst, int pos);
t_list	*creat_elem(int data, int pos);
t_list	*ft_create_element(int pos);
t_point	ft_cost_value_b(t_list **lst_b);
t_point	ft_cost_value_a(t_list **lst_a, t_list  **lst_b);
int		ft_is_min(t_list **lst);
int		ft_is_max(t_list **lst);
int		ft_check_double(char *str, int *nbr);
int		ft_strlen_int(int *nbr);
int		ft_is_sorted(t_list	**lst);
int		ft_check_total(char *str);

# endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgervais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:17:08 by bgervais          #+#    #+#             */
/*   Updated: 2022/12/23 14:34:29 by bgervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lib_push_swap.h"

int	ft_find_bro(t_list	**lst_a, int value)
{
	t_list	*temp;
	int		bro;

	temp = *lst_a;
	while ((*lst_a)->content < value)
		*lst_a = (*lst_a)->next;
	if ((*lst_a)->content > value)
		bro = (*lst_a)->content;
	while (*lst_a)
	{
		if ((*lst_a)->content > value)
		{
			if (bro > (*lst_a)->content)
			{
				bro = (*lst_a)->content;
			}
		}
		*lst_a = (*lst_a)->next;
	}
	*lst_a = temp;
	return (bro);
}

int	ft_algo_best_pos(t_point p)
{
	int		pos;
	int		total;
	int		i;

	i = 0;
	pos = 0;
	total = p.cout_a[i] + p.cout_b[i];
	i++;
	while (p.cout_b[i] != -1)
	{
		if (total > (p.cout_a[i] + p.cout_b[i])
			&& p.cout_b[i] != -1)
		{
			pos = i;
			total = p.cout_a[i] + p.cout_b[i];
		}
		i++;
	}
	return (pos);
}

void	ft_is_algo(t_list **lst_a, t_list **lst_b, t_point p, int pos)
{
	int		i;

	while (ft_lstsize(*lst_b) != 0)
	{
		p = ft_cost_value_a(lst_a, lst_b);
		pos = ft_algo_best_pos(p);
		i = 0;
		while (i++ < p.cout_b[pos])
		{
			if (pos <= (ft_lstsize(*lst_b) / 2))
				ft_rb(lst_b);
			else
				ft_rrb(lst_b);
		}
		i = 0;
		while (i++ < p.cout_a[pos])
		{
			if (p.valeur[pos] == 1)
				ft_ra(lst_a);
			if (p.valeur[pos] == 0)
				ft_rra(lst_a);
		}
		ft_pa(lst_b, lst_a);
		ft_free_p(p);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_to_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgervais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:03:30 by bgervais          #+#    #+#             */
/*   Updated: 2022/12/23 15:08:50 by bgervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lib_push_swap.h"

void	ft_until_above_median(t_list **lst_a, int median, int option)
{
	while ((*lst_a)->content >= median)
	{
		if (option)
			ft_ra(lst_a);
		else
			ft_rra(lst_a);
	}
}

void	ft_if_below_median(t_list *lst_b, t_list **lst_a)
{
	if (!lst_b)
		lst_b = ft_create_and_delete(lst_a, (*lst_a)->content);
	else
		ft_pb(lst_a, &lst_b);
}

int	ft_reset(t_list	**new, t_list **lst_a)
{
	int	median;

	ft_clear_and_copy(lst_a, new);
	median = ft_sort(new);
	return (median);
}

int	ft_end(t_list **lst_a, t_list **new)
{
	if (ft_lstsize(*lst_a) == 2)
	{
		ft_lstclear_bis(new);
		if ((*lst_a)->content > (*lst_a)->next->content)
			ft_sa(lst_a);
		return (1);
	}
	return (0);
}

t_list	*ft_push_all_to_b(t_list **lst_a)
{
	t_list	*lst_b;
	int		median;
	t_list	*new;
	int		option;

	lst_b = NULL;
	new = ft_copy(lst_a);
	median = ft_sort(&new);
	while (*lst_a)
	{
		option = ft_best_option(median, ft_lstsize(*lst_a), lst_a);
		ft_until_above_median(lst_a, median, option);
		if ((*lst_a)->content < median)
		{
			if (!lst_b)
				lst_b = ft_create_and_delete(lst_a, (*lst_a)->content);
			else
				ft_pb(lst_a, &lst_b);
		}
		if (ft_is_no_option1(median, lst_a) == 0)
			median = ft_reset(&new, lst_a);
		if (ft_end(lst_a, &new))
			break ;
	}
	return (lst_b);
}

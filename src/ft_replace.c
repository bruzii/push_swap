/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgervais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:51:49 by bgervais          #+#    #+#             */
/*   Updated: 2022/12/21 16:51:59 by bgervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lib_push_swap.h"

int	ft_find_pos_min(t_list **lst_a)
{
	int		min;
	t_list	*temp;
	int		i;

	i = 0;
	min = ft_is_min(lst_a);
	temp = *lst_a;
	if (min == (*lst_a)->content)
		return (0);
	while (*lst_a)
	{
		if ((*lst_a)->content == min)
			break ;
		i++;
		*lst_a = (*lst_a)->next;
	}
	*lst_a = temp;
	return (i);
}

void	ft_replace(t_list **lst_a)
{
	int	pos;
	int	min;

	min = ft_is_min(lst_a);
	pos = ft_find_pos_min(lst_a);
	if (pos == 0)
		return ;
	if (pos > (ft_lstsize(*lst_a) / 2))
	{
		while ((*lst_a)->content != min)
			ft_rra(lst_a);
	}
	else
	{
		while ((*lst_a)->content != min)
			ft_ra(lst_a);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruct_parsing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgervais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:41:03 by bgervais          #+#    #+#             */
/*   Updated: 2022/12/23 18:44:52 by bgervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lib_push_swap.h"

t_list	*ft_create(t_list **lst, int pos)
{
	t_list	*lst_a;

	lst_a = ft_create_element(pos);
	ft_clear_element(lst);
	return (lst_a);
}

void	ft_p(t_list **lst, t_list **lst2)
{
	t_list	*temp;
	t_list	*temp2;

	temp2 = creat_elem((*lst)->content, (*lst)->position);
	temp = (*lst)->next;
	free(*lst);
	*lst = temp;
	ft_lstadd_front(lst2, temp2);
	ft_good_pos_unique(lst);
}

void	ft_s(t_list **lst)
{
	int	temp;

	if (*lst && (*lst)->next)
	{
		temp = (*lst)->content;
		(*lst)->content = (*lst)->next->content;
		(*lst)->next->content = temp;
	}
}

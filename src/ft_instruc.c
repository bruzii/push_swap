/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgervais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:37:59 by bgervais          #+#    #+#             */
/*   Updated: 2022/12/23 18:22:46 by bgervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lib_push_swap.h"

void	ft_rra(t_list **lst)
{
	ft_pull(lst);
	ft_printf("rra\n");
}

void	ft_rrb(t_list **lst)
{
	ft_pull(lst);
	ft_printf("rrb\n");
}

void	ft_rrr(t_list **lst, t_list **lst2)
{
	ft_pull(lst);
	ft_pull(lst2);
}

void	ft_pull(t_list **lst)
{
	t_list	*temp;
	t_list	*temp2;

	temp = *lst;
	while ((*lst)->next->next)
	{
		*lst = (*lst)->next;
	}
	temp2 = ft_create_element((*lst)->next->content);
	free ((*lst)->next);
	(*lst)->next = NULL;
	*lst = temp;
	ft_lstadd_front(lst, temp2);
	ft_good_pos_unique(lst);
}

int	ft_check_double(int len, int *nbr)
{
	int	i;
	int	k;

	i = 0;
	while (i < (len - 1))
	{
		k = i + 1;
		while (k < (len - 1))
		{
			if (nbr[i] == nbr[k])
				return (0);
			k++;
		}
		i++;
	}
	return (1);
}

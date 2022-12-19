/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgervais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:37:59 by bgervais          #+#    #+#             */
/*   Updated: 2022/12/13 17:16:36 by bgervais         ###   ########.fr       */
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
	ft_printf("rrr\n");
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

int	ft_check_double(char *str, int *nbr)
{
	int	i;
	int	k;
	int	len;

	i = 0;
	len = ft_check(str);
	while (i < len)
	{
		k = i + 1;
		while (k < len)
		{
			if (nbr[i] == nbr[k])
				return (0);
			k++;
		}
		i++;
	}
	return (1);
}

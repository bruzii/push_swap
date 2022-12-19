/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cost.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgervais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:19:05 by bgervais          #+#    #+#             */
/*   Updated: 2022/12/19 12:54:00 by bgervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

t_point	ft_cost_value_b(t_list **lst_b)
{
	t_point	p;
	t_list	*temp_b;
	int		moitie;
	int		len;

	moitie = ft_lstsize(*lst_b) / 2;
	len = ft_lstsize(*lst_b);
	p.cout_b = malloc(sizeof(int) * (ft_lstsize(*lst_b) + 1));
//	p.count_b_bis = malloc(sizeof(int) * (ft_lstsize(*lst_b) + 1));
	if (!p.cout_b)
		return (p);
	temp_b = *lst_b;
	while (*lst_b)
	{
		if ((*lst_b)->position <= moitie)
			p.cout_b[(*lst_b)->position] = (*lst_b)->position;
		else if ((*lst_b)->position > moitie && (*lst_b)->position > 1)
			p.cout_b[(*lst_b)->position] = ((len) - (*lst_b)->position);
		if (!(*lst_b)->next)
			p.cout_b[(*lst_b)->position + 1] = -1;
		*lst_b = (*lst_b)->next;
	}
	*lst_b = temp_b;
	return (p);
}
int	ft_just_swap(t_list **lst_a, t_list **lst_b)
{
	if ((*lst_b)->content > (*lst_a)->content)
	{
		if ((*lst_b)->content < (*lst_a)->next->content)
			return (1);
	}
	return (0);
}

t_point	ft_cost_value_a(t_list **lst_a, t_list	**lst_b)
{
	t_point	p;
	t_list	*temp_b;
	int		i;
	int		count;

	i = 0;
	count = 0;
	ft_print(lst_a);
	p = ft_cost_value_b(lst_b);
	p.cout_a = malloc(sizeof(int) * (ft_lstsize(*lst_b)));
	temp_b = *lst_b;
	while (*lst_b)
	{
		while (p.cout_b[i] != -1)
		{
			if (!((*lst_b)->content < (*lst_a)->content))
			{
				count = ft_just_swap(lst_a, lst_b);
				ft_print(lst_a);
//				printf("\nfonct : %d\n\n", ft_just_swap(lst_a, lst_b));
				if (!count)
				{
					while ((*lst_b)->content > (*lst_a)->content)
					{
						ft_r(lst_a);
						count++;
					}
				}
				if (count != 1)
					count = count * 2;
			}
//			printf("count : %d\n", count);
			p.cout_a[i++] = count;
			if (count == 1)
				count--;
			count = count / 2;
			while ((count) > 0)
			{
//				printf ("ok\n");
				ft_pull(lst_a);
				count--;
			}
			break ;
		}
		*lst_b = (*lst_b)->next;
	}	
	*lst_b = temp_b;
	ft_good_pos(lst_a, &temp_b);
	return (p);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cost.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgervais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:19:05 by bgervais          #+#    #+#             */
/*   Updated: 2022/12/23 14:34:42 by bgervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

int	ft_cost(int val, t_list **lst_a)
{
	t_list	*temp;
	int		i;
	int		value;

	value = ft_find_bro(lst_a, val);
	i = 0;
	temp = *lst_a;
	while (*lst_a)
	{
		if ((*lst_a)->content == value)
			break ;
		i++;
		*lst_a = (*lst_a)->next;
	}
	*lst_a = temp;
	return (i);
}

t_point	ft_cost_value_b(t_list **lst_b)
{
	t_point	p;
	t_list	*temp_b;
	int		moitie;
	int		len;

	moitie = ft_lstsize(*lst_b) / 2;
	len = ft_lstsize(*lst_b);
	p.cout_b = malloc(sizeof(int) * (ft_lstsize(*lst_b) + 1));
	if (!p.cout_b)
		exit (0);
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

int	ft_option(t_list **lst_a, int i)
{
	int	size;

	size = ft_lstsize(*lst_a);
	if (i <= (size / 2))
		return (1);
	return (0);
}

int	ft_ra_or_rra(t_list **lst_a, t_list **lst_b, int count)
{
	if (ft_option(lst_a, ft_cost((*lst_b)->content, lst_a)))
		count = ft_cost((*lst_b)->content, lst_a);
	if (!ft_option(lst_a, ft_cost((*lst_b)->content, lst_a)))
		count = ft_lstsize(*lst_a) - ft_cost((*lst_b)->content, lst_a);
	return (count);
}

t_point	ft_cost_value_a(t_list **lst_a, t_list	**lst_b)
{
	t_point	p;
	t_list	*temp_b;
	int		i;
	int		count;

	i = 0;
	count = 0;
	p = ft_cost_value_b(lst_b);
	p.cout_a = malloc(sizeof(int) * (ft_lstsize(*lst_b)));
	p.valeur = malloc(sizeof(int) * (ft_lstsize(*lst_b)));
	if (!p.cout_a || !p.valeur)
		exit (0);
	temp_b = *lst_b;
	while (*lst_b)
	{
		if ((*lst_a)->content == ft_find_bro(lst_a, (*lst_b)->content))
			count = 0;
		else
			count = ft_ra_or_rra(lst_a, lst_b, count);
		p.cout_a[i++] = count;
		p.valeur[i - 1] = ft_option(lst_a, ft_cost((*lst_b)->content, lst_a));
		*lst_b = (*lst_b)->next;
	}	
	*lst_b = temp_b;
	return (p);
}

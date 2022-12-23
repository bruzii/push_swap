/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgervais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 12:14:59 by bgervais          #+#    #+#             */
/*   Updated: 2022/12/23 18:44:21 by bgervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lib_push_swap.h"

void	ft_sort_long(t_point p, t_list **pile_a, t_list *pile_b)
{
	int	pos;

	pos = 0;
	ft_good_pos(pile_a, &pile_b);
	p = ft_cost_value_a(pile_a, &pile_b);
	ft_good_pos(pile_a, &pile_b);
	ft_is_algo(pile_a, &pile_b, p, pos);
	ft_replace(pile_a);
	ft_free_p(p);
}

int	main(int argc, char **argv)
{
	t_list	*pile_a;
	t_list	*pile_b;
	t_point	p;

	if (argc == 2)
		pile_a = ft_recup_list_one(argv[1]);
	else
		pile_a = ft_recup_list(argc, argv);
	if (!pile_a)
		return (0);
	if (ft_is_sorted(&pile_a))
	{
		if (ft_lstsize(pile_a) < 4 || ft_lstsize(pile_a) == 5)
		{
			ft_short(&pile_a);
		}
		else
		{
			pile_b = ft_push_all_to_b(&pile_a);
			ft_sort_long(p, &pile_a, pile_b);
		}
	}
	ft_lstclear_bis(&pile_a);
	return (0);
}

/*
void	ft_print(t_list **lst)
{
	t_list	*temp;
	
	temp = *lst;
	while (*lst)
	{
		printf("liste[%d] : %d\n",(*lst)->position, (*lst)->content);
		*lst = (*lst)->next;
	}
	*lst = temp;
}
*/

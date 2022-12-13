#include "lib_push_swap.h"

void	ft_free_lst(t_list	**lst)
{
	while (*lst)
	{
		ft_clear_element(lst);
		*lst = (*lst)->next;
	}
}
		
int	main(int argc, char **argv)
{
	t_list	*pile_a;
	t_list	*pile_b;
	t_list	*temp;
	t_point	p;
//	int		i;

//	i = 0;
	(void)argc;
	pile_a = ft_recup_list(argv[1]);
	pile_b = ft_push_all_to_b(&pile_a);
//	ft_pa(&pile_b, &pile_a);
	temp = pile_a;
	while (pile_a)
	{
		ft_printf("a[%d}:%d\n", (pile_a)->position, (pile_a)->content);
		pile_a = (pile_a)->next;
	}
	pile_a = temp;
	temp = pile_b;
	while (pile_b)
	{
		ft_printf("b[%d] :%d\n", pile_b->position, pile_b->content);
		pile_b = pile_b->next;
	}
	pile_b = temp;
//	printf("min : %d\n", ft_is_min(&pile_a));
	printf("\n\n----------------------------\n\n");
	p = ft_cost_value_a(&pile_a, &pile_b);
//	printf("meileur position : %d\n", ft_algo_best_pos(p));
//	printf("meileur position : %d\n", ft_algo_best_pos(p));		
//	printf("meileur position : %d\n", ft_algo_best_pos(p));		
//	printf("meileur position : %d\n", ft_algo_best_pos(p));		
//	printf("meileur position : %d\n", ft_algo_best_pos(p));		
//	printf("sorted : %d\n", ft_is_sorted(&pile_a));
//	printf("max is : %d\n", ft_is_max(&pile_a));
	ft_is_algo(&pile_a, &pile_b, p);
//	while (p.cout_b[i] != -1)
//	{
//		printf("cout bis = %d ------ cout a =  %d\n", p.count_b_bis[i], p.cout_a[i]);
//		i++;
//	}
//	ft_pa(&pile_a, &pile_b);
//	ft_pb(&pile_a, &pile_b);
//	ft_is_3(&pile_a);
//	printf("min pos : %d\n", ft_is_min(&pile_a));
	while (pile_a)
	{
		ft_printf("a[%d}:%d\n", (pile_a)->position, (pile_a)->content);
		pile_a = (pile_a)->next;
	}
	while (pile_b)
	{
		ft_printf("b[%d] :%d\n", pile_b->position, pile_b->content);
		pile_b = pile_b->next;
	}
		
	ft_free_lst(&pile_a);
	ft_free_lst(&pile_b);
	free (p.cout_b);
	free (p.cout_a);
	return (0);
}

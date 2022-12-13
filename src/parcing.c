/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgervais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:49:40 by bgervais          #+#    #+#             */
/*   Updated: 2022/12/13 15:51:11 by bgervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lib_push_swap.h"

t_list	*creat_elem(int data, int pos)
{
	t_list	*temp;

	temp = malloc(sizeof(t_list) * 1);
	if (!temp)
		return (0);
	temp->content = data;
	temp->position = pos;
	temp->next = NULL;
	return (temp);
}

int	ft_check(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (str[0] == ' ')
		return (0);
	while (str[i])
	{
		if (str[i] == ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			return (0);
		if (str[i] == '-' && (str[i + 1] == '-' || str[i + 1] == '\0'))
			return (0);
		if (!(str[i] <= '9' && str[i] >= '0') && str[i] != ' ' && str[i] != '-')
			return (0);
		if ((str[i] <= '9' && str[i] >= '0') && str[i + 1] == '-')
			return (0);
		if ((str[i] <= '9' && str[i] >= '0')
			&& (str[i + 1] == ' ' || str[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

int	*ft_recup(char *str)
{
	int			i;
	int			count;
	int long	nbr;
	int			*nb;
	int			k;
	int			signe;

	i = 0;
	k = 0;
	count = ft_strlen(str);
	nb = malloc(sizeof(int) * (count));
	if (!nb)
		return (0);
	while (i < count)
	{
		signe = 1;
		nbr = 0;
		while (str[i] != ' ' && str[i])
		{
			if (str[i] == '-')
			{
				i++;
				signe = -1;
				nbr = nbr * 10 + str[i] -'0';
			}
			else if (str[i] != ' ')
				nbr = nbr * 10 + str[i] - '0';
			i++;
		}
		nb[k++] = (nbr * signe);
		i++;
	}
	return (nb);
}

t_list	*ft_recup_list(char *str)
{
	int		i;
	int		*nbr;
	int		len;
	t_list	*lst;
	t_list	*cpy;

	i = 0;
	if (ft_check(str))
		len = ft_check(str);
	else
	{
		ft_printf("Error\n");
		return (NULL);
	}
	if (!ft_check_total(str))
		return (0);
	nbr = ft_recup(str);
	lst = creat_elem(nbr[i], i);
	cpy = lst;
	i++;
//	printf("len : %d\n", len);
	while (i < len)
	{
//		printf("i%d = %d\n", i, nbr[i]);
		lst->next = creat_elem(nbr[i], i);
		lst = lst->next;
		i++;
	}
	return (free(nbr), cpy);
}

int	ft_check_total(char *str)
{
	int	*pile_a;

	if (!ft_check(str))
	{
		ft_printf("Error\n");
		return (0);
	}
	pile_a = ft_recup(str);
	if (!(ft_check_double(str, pile_a)))
	{
		ft_printf("Error\n");
		return (0);
	}
	free (pile_a);
	return (2);
}

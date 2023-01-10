/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_one_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgervais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:49:40 by bgervais          #+#    #+#             */
/*   Updated: 2022/12/26 11:13:21 by bgervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lib_push_swap.h"

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

void	ft_recup_aux(int *i, char *str, int *signe, int long *nbr)
{
	while (str[*i] != ' ' && str[*i])
	{
		if (str[*i] == '-')
		{
			*i = *i + 1;
			*signe = -1;
			*nbr = *nbr * 10 + str[*i] - '0';
		}
		else if (str[*i] != ' ')
			*nbr = *nbr * 10 + str[*i] - '0';
		*i = *i + 1;
	}
}

int	*ft_recup_one(char *str)
{
	int			i;
	int long	nbr;
	int			*nb;
	int			k;
	int			signe;

	i = 0;
	k = 0;
	nb = malloc(sizeof(int) * ft_strlen(str));
	if (!nb)
		return (0);
	while (i < (int)ft_strlen(str))
	{
		signe = 1;
		nbr = 0;
		ft_recup_aux(&i, str, &signe, &nbr);
		if ((nbr * signe) > 2147483647 || (nbr * signe) < -2147483648)
			return (free (nb), NULL);
		nb[k++] = (nbr * signe);
		i++;
	}
	if (k == 1)
		return (free (nb), NULL);
	return (nb);
}

t_list	*ft_recup_list_one(char *str)
{
	int		i;
	int		*nbr;
	int		len;
	t_list	*lst;
	t_list	*cpy;

	i = 0;
	len = ft_check(str);
	if (!ft_check_total(str))
		return (NULL);
	nbr = ft_recup_one(str);
	if (!nbr)
		return (free (nbr), NULL);
	lst = creat_elem(nbr[i], i);
	cpy = lst;
	i++;
	while (i < len)
	{
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
	pile_a = ft_recup_one(str);
	if (!pile_a || !(ft_check_double_one(str, pile_a)))
	{
		ft_printf("Error\n");
		return (free (pile_a), 0);
	}
	return (free (pile_a), 2);
}

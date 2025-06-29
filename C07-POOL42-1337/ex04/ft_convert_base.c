/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 02:33:03 by msabr             #+#    #+#             */
/*   Updated: 2024/08/12 15:05:11 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *src);
int	error(char *base);
int	ft_atoi_base(char *str, char *base);

int	ft_strlen_base(int nbr, int len_base)
{
	int	size;

	size = 0;
	if (nbr <= 0)
	{
		nbr *= -1;
		size++;
	}
	while (nbr != 0)
	{
		size++;
		nbr /= len_base;
	}
	return (size);
}

void	ft_putnbr_base_2(int nbr, char *base, char *pointeur)
{
	long	nb;
	int		i;
	int		len_base;
	int		len_nbrf;

	nb = nbr;
	i = 0;
	len_base = ft_strlen(base);
	len_nbrf = ft_strlen_base(nbr, len_base);
	if (nb < 0)
	{
		pointeur[0] = '-';
		nb *= -1;
		i = 1;
	}
	len_nbrf--;
	while (nb >= len_base)
	{
		pointeur[len_nbrf] = base[nb % len_base];
		nb /= len_base;
		len_nbrf--;
	}
	if (nb < len_base)
		pointeur[i] = base[nb];
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long	n;
	int		len;
	char	*pnt;

	if ((error(base_from) == 0) || (error(base_to) == 0))
		return (NULL);
	n = ft_atoi_base(nbr, base_from);
	len = ft_strlen_base(n, ft_strlen(base_to));
	pnt = (char *)malloc(sizeof(char) * (len + 1));
	if (pnt == NULL)
		return (NULL);
	ft_putnbr_base_2(n, base_to, pnt);
	pnt[len] = '\0';
	return (pnt);
}

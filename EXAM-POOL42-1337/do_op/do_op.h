#ifndef DO_OP_H
# define DO_OP_H

# include <unistd.h>
# include <stdio.h>

int	ft_atoi(char *str)
{
	int		i;
	int		sign;
	int		nb;

	i = 0;
	sign = 1;
	nb = 0;
	while ((str[i] == '\t') || (str[i] == '\n') || (str[i] == '\r')
		|| (str[i] == '\v') || (str[i] == ' ') || (str[i] == '\f'))
		i++;
	while (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	nb = nb * sign;
	return (nb);
}

int	ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

#endif
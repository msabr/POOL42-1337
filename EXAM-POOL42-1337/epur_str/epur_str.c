/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 11:23:17 by msabr             #+#    #+#             */
/*   Updated: 2024/08/09 11:23:19 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdio.h>

int is_speace(char c)
{
    if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r' || c == ' ')
        return (1);
    else
        return (0);
}

int main (int ac, char **av)
{
	int		i = 0;
	int		space = -1;
	if (ac == 2)
	{
		while (av[1][i])
		{
			if (is_speace(av[1][i]) == 0)
			{
				if (space == 1)
					write(1, " ", 1);
				space = 0;
				write(1, &av[1][i], 1);
			}
			else if (space == 0)
				space = 1;
			i++;
		}
	}
	write(1, "\n", 1);
    return (0);
}

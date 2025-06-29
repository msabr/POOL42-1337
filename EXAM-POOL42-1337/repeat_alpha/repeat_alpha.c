/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 21:52:48 by msabr             #+#    #+#             */
/*   Updated: 2024/08/01 22:17:13 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1,"\n",1);
		return 0;
	}
	int i = 0;
	int nbr;
	while (argv[1][i])
	{
		if (argv[1][i] >= 'a' && argv[1][i]<='z')
		{
			nbr = 'a';
			while (nbr <= argv[1][i])
			{
				write(1,&argv[1][i],1);
				nbr++;
			}
		}
		else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
		{
			nbr = 'A';
			while (nbr <= argv[1][i])
			{
				write(1,&argv[1][i],1);
				nbr++;
			}
		}
		else
		{
			write(1,&argv[1][i],1);
		}
	i++;
	}
	write(1,"\n",1);
	return 0;
}

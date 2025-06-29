/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 23:11:51 by msabr             #+#    #+#             */
/*   Updated: 2024/08/01 23:23:32 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main (int argc, char **argv)
{
	if (argc != 2)
	{
		write(1,"\n",1);
		return 0;
	}
	int i = 0;
	while (argv[1][i])
	{
		if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
		{
			argv[1][i] -= 32;
			write(1,&argv[1][i],1);
		}
		else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
		{
			argv[1][i] += 32;
			write(1,&argv[1][i],1);
		}else
		{
			write(1,&argv[1][i],1);
		}
		i++;
	}
	write(1,"\n",1);
	return 0;
}


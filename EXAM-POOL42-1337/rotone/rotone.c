/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 23:30:06 by msabr             #+#    #+#             */
/*   Updated: 2024/08/01 23:53:08 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int main (int argc,char **argv)
{
	int i = 0;

	if (argc != 2)
	{
		write(1,"\n",1);
		return 0;
	}
	while (argv [1][i])
	{
		if ((argv[1][i] >='a' && argv[1][i] <= 'z') || (argv[1][i]>='A' && argv[1][i] <= 'Z'))
		{
			if (argv[1][i] == 'z')
				argv[1][i] = 'a';
			else if (argv[1][i] == 'Z')
				argv[1][i] = 'A';
			else
				argv[1][i] += 1;
			write(1,&argv[1][i],1);
		}else
		{
			write(1,&argv[1][i],1);
		}
		i++;
	}
	write (1,"\n",1);
	return 0;
}



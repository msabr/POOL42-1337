/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:52:28 by msabr             #+#    #+#             */
/*   Updated: 2024/08/01 18:05:46 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main (int argc , char **argv)
{
	int i;
	int j;

	if (argc != 2)
	{
		write(1,"\n",1);
		return 0;
	}
	i = 0;
	while (argv[1][i] && (argv[1][i]==32 || argv[1][i]==9))
	{
		i++;
	}
	j = i;

	while (argv[1][i])
	{
		if (argv[1][i]=='\t' || argv[1][i]==' ')
		{
			break;
		}
		i++;
	}
	while ( j < i)
	{
		write(1,&argv[1][j],1);
		j++;
	}
	write(1,"\n",1);
	return 0;
}


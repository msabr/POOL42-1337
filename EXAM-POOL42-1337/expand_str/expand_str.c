/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 11:23:41 by msabr             #+#    #+#             */
/*   Updated: 2024/08/09 11:23:44 by msabr            ###   ########.fr       */
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
int main (int argc,char **argv)
{
    int i = 0;
    int speace = -1;

    if (argc == 2)
    {
        while (argv[1][i])
        {
            if (is_speace(argv[1][i]) == 0)
            {
                if (speace == 1)
                    write(1,"   ",3);
                speace = 0;
                write(1, &argv[1][i], 1);                
            }
            else if (speace == 0)     
            {
                speace = 1;
            }
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}

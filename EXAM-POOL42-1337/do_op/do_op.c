/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:56:33 by msabr             #+#    #+#             */
/*   Updated: 2024/08/08 16:56:34 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdio.h>
# include "do_op.h"

int	ft_atoi(char *str);
int	ft_strcmp(char *s1, char *s2);

int main (int argc, char **argv)
{
    int i = 0;
    if (argc == 4)
    {
        int nb1,nb2;
        nb1 = ft_atoi(argv[1]);
        nb2 = ft_atoi(argv[3]);
        if (ft_strcmp(argv[2],"+") == 0){
            printf("%d",nb1 + nb2);
        }
        else if (ft_strcmp(argv[2],"-") == 0){
            printf("%d",nb1 - nb2);
        }
        else if (ft_strcmp(argv[2],"*") == 0){
            printf("%d",nb1 * nb2);
        }
        else if (ft_strcmp(argv[2],"/") == 0){
            if (nb2 != 0)
                printf("%d",nb1 / nb2);
        }
        else if (ft_strcmp(argv[2],"%") == 0){
            if (nb2 != 0)
                printf("%d",nb1 % nb2);
        }
    }
    printf("\n");
    return 0;
}


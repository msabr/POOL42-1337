/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:52:25 by msabr             #+#    #+#             */
/*   Updated: 2024/08/08 12:52:27 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

void	ft_print_numbers(void)
{
    int i = '0';
    while (i <= '9')
    {
        write(1,&i,1);
        i++;
    }
}
int main()
{
    ft_print_numbers();
    return (0);
}

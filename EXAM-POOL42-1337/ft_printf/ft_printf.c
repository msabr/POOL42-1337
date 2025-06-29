/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 11:18:58 by msabr             #+#    #+#             */
/*   Updated: 2025/05/23 11:19:02 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

void ft_putstr(char* str, int *j)
{
    int i = 0;
    if (!str)
        write(1,"(null)",7);
    while (str[i])
    {
        *j += write(1, &str[i], 1);
    }
}

void	ft_putnbr_base(long n, int base, int *j)
{
    if (n < 0)
    {
        n *= -1;
        *j += write(1, "-", 1);
    }
    if(n >= base)
        ft_putnbr_base(n / base,base,j);
    *j +=  write(1, &("0123456789abcdef")[n % base], 1);
}

int ft_printf(const char *format, ... )
{
    va_list pnt;
    int i = 0;

    va_start(pnt, format);
    while (*format)
    {
        if (*format == '%' && ((*(format + 1) == 's') || (*(format + 1) == 'd') || (*(format + 1) == 'x')))
        {
            format++;
            if (*format == 's')
                ft_putstr(va_arg(pnt,char*),&i);
            else if (*format == 'x')
                ft_putnbr_base(va_arg(pnt, int), 10 , &i);
            else if (*format == 'x')
                ft_putnbr_base(va_arg(pnt,unsigned int), 16 , &i);
            
        }
        else
            i += write(1, format , 1);
    }
    va_end(pnt);
    return(i);
}

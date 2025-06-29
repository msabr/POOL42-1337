#include <unistd.h>

void lowcase(char *str)
{
    int i = 0;
    while (str[i])
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
        i++;
    }
}

int is_speace(char c)
{
    if (c == '\t' || c == '\n' || c == '\f' || c == '\v' || c == '\r' || c == ' ')
        return (1);
    else
        return (0);
}

void ft_putstr(char *str)
{
    int i = 0;

    while (str[i])
    {
        write(1,&str[i],1);
        i++;
    }
}

char *rstr_capitalizer(char *str)
{
    int i = 0;
    int j = 0;
    int t = 1;

    lowcase(str);
    while (str[i])
        i++;
    i--;
    while (str[i] && is_speace(str[i]))
        i--;
    j = i;
    while (i > 0)
    {
        if ((is_speace(str[i]) == 0) && ( t == 1))
        {
            if (str[i] >= 'a' && str[i] <= 'z')
            {
                str[i] -= 32;
                t = 0;
            }
            
        }
        else if (is_speace(str[i]))
        {
            t = 1;
        }
        i--;
    }
    return (str);
}

int main(int ac, char **av)
{
    if (ac > 1)
    {
        int i = 1;
        while (av[i])
        {
            ft_putstr(rstr_capitalizer(av[i]));
            ft_putstr("\n");
            i++;
        }
    }
    else
        ft_putstr("\n");
    return (0);
}
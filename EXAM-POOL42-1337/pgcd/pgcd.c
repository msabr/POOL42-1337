#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2", 2);
		nb = 147483648;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		ft_putchar(nb + '0');
	}
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	int		nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (str[i] && str[i] == ' ')
	{
		i++;
	}
	while (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
		{
			sign *= -1;
		}
		i++;
	}
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			nb = nb * 10 + (str[i] - '0');
		}
		else
		{
			break;
		}
		i++;
	}
	nb = nb * sign;
	return (nb);
}

int main(int argc, char **argv)
{
    if (argc == 3)
    {
        int i;
        int pgcd;
        int x = ft_atoi(argv[1]);
        int y = ft_atoi(argv[2]);
        if (x > y)
            i = y - 1;
        else
            i = x - 1;
        while(i > 0)
        {
            if ((x % i == 0) && (y % i == 0))
            {
                ft_putnbr(i);
                break;
            }
            i--;
        }
    }
    write(1,"\n",1);
	return 0;
}
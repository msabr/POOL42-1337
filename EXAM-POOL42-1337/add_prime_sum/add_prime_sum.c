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
	int	i = 0;
	int	neg_flag = 0;
	int	result = 0;

	while (str[i])
	{
		result *= 10; 
		if (str[i] == '-' && !(neg_flag))
			neg_flag = 1;
		if (str[i] >= '0' && str[i] <= '9') 
            result += str[i] - '0';
		i++;
	}
	if (neg_flag)
		return (result * -1);
	return (result);
}

int	ft_is_prime(int nb)
{
	int		n;

	n = 2;
	if (nb > 1)
	{
		while (n <= (nb / 2))
		{
			if ((nb % n) == 0)
				return (0);
			n++;
		}
		return (1);
	}
	return (0);
}

int main (int argc, char **argv)
{
	int i = 0;
    int s = 0;
    int nbr ;

	if (argc == 2)
	{
        nbr = ft_atoi(argv[1]);
        if (nbr > 0)
        {
            while (i <= nbr)
            {
                if (ft_is_prime(i) == 1)
                {
                    s += i;
                }
                i++;
            }
            ft_putnbr(s);
        }else{
        write(1,"0\n",2);
		return (0);  
        }
        return (0);
	}
	write(1,"0\n",2);
	return 0;
}
#include <stdio.h>

int	power(int nb, int power)
{
	int		i;
	int		pow;

	if (power < 0)
		return (0);
	i = 0;
	pow = 1;
	while (i < power)
	{
		pow = pow * nb;
		i++;
	}
	return (pow);
}

int	    is_power_of_2(unsigned int n)
{
    unsigned int i;
    i = 0;
    while (i < n)
    {
        if (power(2,i) == n)
            return 1;
        i++;
    }
    return (0);
}

int main()
{
    int n;
    n = is_power_of_2(2048);
    printf("%d\n",n);
    return (0);
}
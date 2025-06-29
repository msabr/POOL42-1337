#include <unistd.h>
void ft_putchar (char c)
{
	write(1,&c,1);
}

int ft_atoi (char *str)
{
	int i = 0;
	int res = 0;
	int signe = 1;

	if (str[i] == '-')
	{
		signe = -1;
		i++;
	}
	while (str[i] && (str[i] >= '0') && (str[i]<='9'))
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * signe);
}

void print_hex (int nbr)
{
	long n = nbr;
	char *base = "0123456789abcdef";
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= 16)
	{
		print_hex (n / 16);
		print_hex (n % 16);
	}
	else
		ft_putchar(base[n]);

}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        int nb = ft_atoi(argv[1]);
        print_hex(nb); 
    }
    write(1,"\n",1);
	return 0;
}
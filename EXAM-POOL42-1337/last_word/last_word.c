#include <unistd.h>

int	ft_strlen(char *str)
{
	int		l;

	l = 0;
	while (str[l] != '\0')
	{
		l++;
	}
	return (l);
}

int main (int argc , char **argv)
{
	int i;
	int j;

	if (argc != 2)
	{
		write(1,"\n",1);
		return 0;
	}
	i = ft_strlen(argv[1]) - 1;

	while (argv[1][i] && (argv[1][i]==32 || argv[1][i]==9))
	{
		i--;
	}
	j = i;

	while (argv[1][i])
	{
		if (argv[1][i]=='\t' || argv[1][i]==' ')
		{
			break;
		}
		i--;
	}
	while ( j >= i)
	{
		write(1,&argv[1][i],1);
		i++;
	}
	write(1,"\n",1);
	return 0;
}


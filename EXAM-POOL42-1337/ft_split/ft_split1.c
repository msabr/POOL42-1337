#include <stdlib.h>

int is_speace(char c)
{
    if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r' || c == ' ')
        return (1);
    else
        return (0);
}

int count_words(char *str)
{
    int i = 0;
    int count = 0;
    int t = 1;

    while (str[i] && is_speace(str[i]))
        i++;
    while (str[i])
    {
        if ((is_speace(str[i]) == 0 ) && (t == 1))
        {
            count++;
            t = 0;
        }
        else if (is_speace(str[i]) == 1)
            t = 1;
        i++;
    }
    return (count);
}



int cat_split(char *dest,char *src, int index)
{
    int i = 0;

    while (src[index] && is_speace(src[index]) == 0)
    {
        dest[i] = src[index];
        i++;
        index++;
    }
    dest[i] = '\0';
    return (index);
}

char **ft_split(char *str)
{
    int i = 0;
    int j = 0;
    int indice = 0;
    int count = count_words(str);
    char **pnt;

    pnt = (char **)malloc(sizeof(char *) * (count + 1));
    if(pnt == NULL)
        return (NULL);
    while (indice < count)
    {
        while (str[i] && (is_speace(str[i]) == 1))
            i++;
        j = 0;
        while (str[i + j] && (is_speace(str[i + j]) == 0))
            j++;
        pnt[indice] = (char *)malloc(sizeof(char) * (j + 1));
        i = cat_split(pnt[indice],str,i);
        indice++;
    }
    pnt[indice] = 0;
    return (pnt);
}

#include <stdio.h>
int	main()
{
	int		index;
	char	**split;
	split = ft_split("sabir  is -+the best");
	index = 0;
	while (split[index])
	{
		printf("%s\n", split[index]);
		index++;
	}
}
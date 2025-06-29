/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:10:33 by msabr             #+#    #+#             */
/*   Updated: 2024/08/13 18:10:35 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

char	*ft_strchr(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	return (0);
}

char	*ft_strpbrk(const char *s1, const char *s2)
{
	char *str1 = (char *)s1;
	char *str2 = (char *)s2;

	while (*str1)
	{
		if (ft_strchr(str2, *str1) != 0)
			return (str1);
		str1++;
	}
	return (NULL);
}

int main(int argc, char **argv)
{
	if (argc == 3)
	{
		char *pch;

		pch = ft_strpbrk(argv[1], argv[2]);
		printf("Characters in |%s|: ", argv[1]);
		while (pch != NULL)
		{
			printf("%c, ", *pch);
			pch = ft_strpbrk(pch + 1, argv[2]);
		}
		printf("\n");
	}
	return (0);
}

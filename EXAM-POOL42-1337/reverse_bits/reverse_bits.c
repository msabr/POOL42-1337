/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 00:47:30 by msabr             #+#    #+#             */
/*   Updated: 2024/08/02 00:53:09 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char res=0;
	int i=8;

	while (i>0)
	{
		res = res * 2 + (octet % 2);
		octet = octet / 2;
		i--;
	}
	return res;
}

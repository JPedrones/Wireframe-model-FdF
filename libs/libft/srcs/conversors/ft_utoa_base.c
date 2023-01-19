/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 <jpedrones@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 21:06:23 by joapedr2          #+#    #+#             */
/*   Updated: 2022/07/15 22:04:30 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Convert unsigned integer number to string */
static size_t	len_mal(unsigned long int n, unsigned int base)
{
	size_t	i;

	i = 1;
	while (n >= base && i++)
		n /= base;
	return (i);
}

char	*ft_utoa_base(unsigned long int n, char *buffer)
{
	char	*nbr;
	size_t	len;
	size_t	base;

	base = ft_strlen(buffer);
	len = len_mal(n, base) + 1;
	nbr = (char *)malloc(len * sizeof(char));
	if (!nbr)
		return (NULL);
	nbr[--len] = '\0';
	if (n == 0)
		nbr[--len] = '0';
	while (n)
	{
		nbr[--len] = buffer[n % base];
		n /= base;
	}
	return (nbr);
}

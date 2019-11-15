/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 15:02:18 by jereligi          #+#    #+#             */
/*   Updated: 2019/11/15 15:33:08 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		n;
	char	*dst;

	dst = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (dst == NULL)
		return (NULL);
	i = 0;
	n = 0;
	while (s1[n])
		dst[i++] = s1[n++];
	n = 0;
	while (s2[n])
		dst[i++] = s2[n++];
	dst[i] = '\0';
	return (dst);
}

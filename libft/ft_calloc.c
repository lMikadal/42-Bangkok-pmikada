/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:45:16 by pmikada           #+#    #+#             */
/*   Updated: 2022/06/08 20:20:05 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*c;
	size_t	sum;
	size_t	i;

	sum = count * size;
	c = (void *)malloc(sum);
	if (c == NULL)
		return (0);
	i = 0;
	while (sum > 0)
	{
		((char *)c)[i] = '\0';
		sum--;
		i++;
	}
	return (c);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 11:26:47 by aeddaqqa          #+#    #+#             */
/*   Updated: 2019/07/23 14:34:51 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_strnew(size_t size)
{
	char	*fraiche;
	size_t	i;

	i = 0;
	fraiche = NULL;
	fraiche = (char *)malloc(sizeof(char) * size + 1);
	if (fraiche == NULL)
		return (NULL);
	while (i < size + 1)
	{
		fraiche[i] = '\0';
		i++;
	}
	return (fraiche);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalissa <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:48:26 by jalissa           #+#    #+#             */
/*   Updated: 2023/12/12 03:17:33 by jalissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	compter_mots(const char *s, char c)
{
	int	compteur;
	int	i;

	i = 0;
	compteur = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			compteur++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (compteur);
}

char	*mot_suivant(const char *s, char c, int *index)
{
	const char	*debut;
	const char	*fin;

	debut = s + *index;
	while (*debut && *debut == c)
		debut++;
	fin = debut;
	while (*fin && *fin != c)
		fin++;
	if (!(*debut))
	{
		*index = fin - s;
		return (NULL);
	}
	else
	{
		*index = fin - s + 1;
		return (ft_substr(debut, 0, fin - debut));
	}
}

void	freefonc(char **res, int i)
{
	while (i > 0)
		free(res[--i]);
	free(res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		nu_mots;
	int		i;
	int		index;

	nu_mots = 0;
	i = 0;
	index = 0;
	if (!s)
		return (NULL);
	nu_mots = compter_mots(s, c);
	res = ft_calloc(nu_mots + 1, sizeof (char *));
	if (!res)
		return (NULL);
	while (i < nu_mots)
	{
		res [i] = mot_suivant(s, c, &index);
		if (!res[i])
		{
			freefonc(res, i);
			return (NULL);
		}
	i++;
	}
	return (res);
}

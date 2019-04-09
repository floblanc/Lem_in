/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:48:17 by floblanc          #+#    #+#             */
/*   Updated: 2019/04/04 11:54:36 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libprintf.h"

static int			ft_count_word(const char *str, char c)
{
	int	i;
	int cases;

	i = 1;
	cases = 0;
	if (str[0] != c)
		cases++;
	while (str[i])
	{
		if (str[i] != c && str[i - 1] == c)
			cases++;
		i++;
	}
	return (cases);
}

static unsigned int	ft_count_letters(const char *s, int check_p, char c)
{
	unsigned int	i;

	i = 0;
	while (s[i + check_p] != c && s[i + check_p] != '\0')
		i++;
	return (i);
}

static char			**ft_freetab(char **tab, int cases)
{
	int	j;

	j = 0;
	while (j < cases)
		free(tab[j++]);
	return (0);
}

char				**ft_strsplit(char const *s, char c)
{
	int		cases;
	int		save_c;
	int		i;
	char	**tab;

	if (!s)
		return (0);
	cases = ft_count_word(s, c);
	if (!(tab = (char**)malloc(sizeof(char*) * (cases + 1))))
		return (0);
	i = 0;
	save_c = cases;
	cases = 0;
	while (cases < save_c && s[i])
	{
		if ((i == 0 && s[i] != c) || (s[i - 1] == c && s[i] != c))
		{
			if (!(tab[cases] = ft_strsub(s, i, ft_count_letters(s, i, c))))
				return (ft_freetab(tab, cases));
			cases++;
		}
		i++;
	}
	tab[cases] = 0;
	return (tab);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 17:22:16 by vradchen          #+#    #+#             */
/*   Updated: 2017/11/15 17:22:17 by vradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "try.h"

int		main(int argc, char **argv)
{
	char *str;

	if (argc < 2)
		ft_putstr(FEW);
	else if (argc > 2)
		ft_putstr(MANY);
	else
	{
		str = ft_r(argv[1]);
		ft_putstr(str);
	}
	return (0);
}

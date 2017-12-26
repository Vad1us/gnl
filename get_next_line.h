/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 14:21:58 by vradchen          #+#    #+#             */
/*   Updated: 2017/12/12 14:22:00 by vradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1

# include <fcntl.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <limits.h>

int		get_next_line(const int fd, char **line);

#endif

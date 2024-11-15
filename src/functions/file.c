/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 02:24:14 by tbarret           #+#    #+#             */
/*   Updated: 2024/03/02 11:58:00 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	check_file(char *file)
{
	if (ft_strstr(file, ".ber"))
		return ;
	error("Error\n You have not specified a map.", 2);
}

char	**get_file(char *file)
{
	char	*l;
	char	*r;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error("Error\n You have not specified a map.", 2);
	r = ft_strdup("");
	while (1)
	{
		l = get_next_line(fd);
		if (!l)
			break ;
		r = ft_strjoin(r, l);
		free(l);
	}
	close(fd);
	if (r[0] == '\0' || ft_strlen(r) <= 1)
	{
		free(r);
		free(l);
		error("Error\n Your maps are empty.",
			2);
	}
	return (ft_split(r, '\n'));
}

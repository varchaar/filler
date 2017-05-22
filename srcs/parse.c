/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varichar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 13:31:31 by varichar          #+#    #+#             */
/*   Updated: 2017/05/22 15:19:21 by varichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_player_nb(t_map *map)
{
	char *line;

	line = NULL;
	while (ft_strstr(line, LOGIN))
	{
		free(line);
		get_next_line(0, &line);
	}
	map->pl = ft_strstr(line, "$$$ exex p1") ? 1 : 2;
	free(line);
}

void	get_map_size(t_map *map)
{
	char *line;

	line = NULL;
	while (ft_strstr(line, "Plateau "))
	{
		free(line);
		get_next_line(0, &line);
	}
	while (!ft_isdigit(*line))
		line++;
	map->y = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	map->x = ft_atoi(line);
	free(line);
}

void	get_map(t_map *map)
{
	char *line;
	int i;

	line = NULL;
	i = 0;
	map->map = (char **)malloc(sizeof(char *) * map->y);
	while (ft_strstr(line, "000"))
	{
		free(line);
		get_next_line(0, &line);
	}
	while (ft_atoi(line) == map->y + 1)
	{
		free(line);
		get_next_line(0, &line);
		map->map[i++] = ft_strdup(line + 4);
	}
}

void	get_piece_size(t_pc *pc)
{
	char *line;
	int i;

	line = NULL;
	i = 0;
	pc->pc = (char **)malloc(sizeof(char *));
	while (ft_strstr(line, "Piece"))
	{
		free(line);
		get_next_line(0, &line);
	}
	while (!ft_isdigit(*line))
		line++;
	pc->y = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	pc->x = ft_atoi(line);
}

void	get_piece(t_pc *pc)
{
	char *line;
	int i;

	line = NULL;
	i = 0;
	pc->pc = (char **)malloc(sizeof(char *) * pc->y);
	while (ft_strchr(line, '*') || ft_strchr(line, '.'))
	{
		free(line);
		get_next_line(0, &line);
	}
	while (i < pc->y)
	{
		free(line);
		get_next_line(0, &line);
		pc->pc[i++] = ft_strdup(line);
	}
}

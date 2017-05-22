/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varichar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 13:17:47 by varichar          #+#    #+#             */
/*   Updated: 2017/05/22 15:57:23 by varichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		filler_end(t_map *map, t_pc *pc)
{
	while (map->map)
	{
		ft_strdel(*(map->map));
		map->map++;
	}
	while (pc->pc)
	{
		ft_strdel(*(pc->pc));
		pc->pc++;
	}
	return (0);
}

void	init(t_map *map, t_pc *pc)
{
	ft_bzero(&map, sizeof(map));
	ft_bzero(&pc, sizeof(pc));
	get_player_nb(map);
	get_map_size(map);
	get_map(map);
}

int		main(void)
{
	t_map map;
	t_pc pc;

	init(&map, &pc);
	while (1)
	{
		get_piece_size(&pc);
		get_piece(&pc);
		if (print_res(&map, &pc))
			return (filler_end(&map, &pc));
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varichar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 13:38:15 by varichar          #+#    #+#             */
/*   Updated: 2017/05/22 15:51:01 by varichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# define LOGIN	"varichar"
# define P1		'O'
# define P2		'X'

# include "libft.h"

typedef struct	s_map
{
	int		pl;
	int		x;
	int		y;
	char	**map;
}				t_map;

typedef struct	s_pc 
{
	int		x;
	int		y;
	char	**pc;
}				t_pc;

void	get_player_nb(t_map *map);
void	get_map_size(t_map *map);
void	get_map(t_map *map);
void	get_piece_size(t_pc *pc);
void	get_piece(t_pc *pc);

#endif

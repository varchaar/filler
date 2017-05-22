/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varichar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 13:38:15 by varichar          #+#    #+#             */
/*   Updated: 2017/05/22 15:05:29 by varichar         ###   ########.fr       */
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

#endif

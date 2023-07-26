/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanson <jmanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 17:42:47 by jmanson           #+#    #+#             */
/*   Updated: 2023/07/19 17:44:57 by jmanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <stddef.h>
# include <stdbool.h>

typedef struct s_vector
{
	int				x;
	int				y;
}					t_vector;

typedef struct s_mapcheck
{
	t_vector		size;
	t_vector		point;
	bool			b_player;
	bool			b_exit;
	bool			b_collect;
	int				cpy_count;
}					t_mapcheck;

typedef struct s_tile
{
	char			type;
	char			og_type;
	int				x;
	int				y;
	struct s_tile	*up;
	struct s_tile	*down;
	struct s_tile	*left;
	struct s_tile	*right;
}					t_tile;

typedef struct s_image
{
	void			**imgs[10];
	void			*img1;
	void			*img2;
	void			*img3;
	void			*img4;
}					t_image;

typedef struct s_player
{
	t_tile			*tile;
	int				framecount;
	int				idle_frames;
	int				action_frames;
}					t_player;

typedef struct s_game
{
	char			**map;
	t_tile			**tilemap;
	void			*mlx;
	void			*window;
	t_vector		img_size;
	t_vector		wndw_size;
	t_player		player;
	int				og_collects;
	int				collects;
	int				moves;
	t_image			collect_imgs;
	t_image			bg_imgs;
	t_image			door_imgs;
	t_image			enemy_imgs;
	t_image			player_imgs;
	t_image			text_imgs;
	t_image			number_imgs;
}					t_game;

#endif

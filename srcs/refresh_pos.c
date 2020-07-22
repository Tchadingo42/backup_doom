/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 12:34:19 by jcanteau          #+#    #+#             */
/*   Updated: 2020/07/22 04:18:49 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	ft_rotate_up(t_env *doom)
{
	if (doom->cam.angle_z <= MAX_ANGLE_Z)
	doom->cam.angle_z += UP_DOWN_ANGLE_SPEED;
}

void	ft_rotate_down(t_env *doom)
{
	if (doom->cam.angle_z >= -MAX_ANGLE_Z)
		doom->cam.angle_z -= UP_DOWN_ANGLE_SPEED;
}

int		wall_on_cam_pos(t_env *doom)
{
	char	map_symbol;

	map_symbol = doom->map.data[(int)doom->cam.pos_y][(int)doom->cam.pos_x];
	if (map_symbol == WALL)
		return (1);
	else if (map_symbol == DOOR)
		return (2);
	else if (map_symbol == TRANSP)
		return (3);
	else if (map_symbol == GRID)
		return (3);
	return (0);
}

void	ft_strafe_right(t_env *doom)
{
	doom->cam.pos_x -= cos(doom->cam.angle) * doom->moves.movespeed;
	if (wall_on_cam_pos(doom))
		doom->cam.pos_x += cos(doom->cam.angle) * doom->moves.movespeed;
	doom->cam.pos_y += sin(doom->cam.angle) * doom->moves.movespeed;
	if (wall_on_cam_pos(doom))
		doom->cam.pos_y -= sin(doom->cam.angle) * doom->moves.movespeed;
}

void	ft_strafe_left(t_env *doom)
{
	doom->cam.pos_x += cos(doom->cam.angle) * doom->moves.movespeed;
	if (wall_on_cam_pos(doom))
		doom->cam.pos_x -= cos(doom->cam.angle) * doom->moves.movespeed;
	doom->cam.pos_y -= sin(doom->cam.angle) * doom->moves.movespeed;
	if (wall_on_cam_pos(doom))
		doom->cam.pos_y += sin(doom->cam.angle) * doom->moves.movespeed;
}

void	ft_backward(t_env *doom)
{
	doom->cam.pos_x -= sin(doom->cam.angle) * doom->moves.movespeed;
	if (wall_on_cam_pos(doom))
		doom->cam.pos_x += sin(doom->cam.angle) * doom->moves.movespeed;
	doom->cam.pos_y -= cos(doom->cam.angle) * doom->moves.movespeed;
	if (wall_on_cam_pos(doom))
		doom->cam.pos_y += cos(doom->cam.angle) * doom->moves.movespeed;
}

void	ft_forward(t_env *doom)
{
	doom->cam.pos_x += sin(doom->cam.angle) * doom->moves.movespeed;
	if (wall_on_cam_pos(doom))
		doom->cam.pos_x -= sin(doom->cam.angle) * doom->moves.movespeed;
	doom->cam.pos_y += cos(doom->cam.angle) * doom->moves.movespeed;
	if (wall_on_cam_pos(doom))
		doom->cam.pos_y -= cos(doom->cam.angle) * doom->moves.movespeed;
}

void	set_movespeed(t_env *doom)
{
	if (doom->moves.running == TRUE &&
			doom->moves.crouching == FALSE)
		doom->moves.movespeed = RUN_RATIO * MOVE_SPEED;
	else if (doom->moves.running == FALSE)
		doom->moves.movespeed = MOVE_SPEED;
}

void	ft_crouch(t_env *doom)
{
	if (doom->moves.falling == FALSE && doom->moves.jumping == FALSE)
	{
		if (doom->moves.crouching == TRUE)
		{
			doom->moves.flying = FALSE;
			if (doom->cam.pos_z - INC_POS_Z >= MIN_POS_Z)
				doom->cam.pos_z -= INC_POS_Z;
		}
		else if (doom->moves.crouching == FALSE && doom->moves.flying == FALSE)
			doom->moves.raising = TRUE;
	}
}

void		ft_jump(t_env *doom)
{
	if (doom->moves.falling == FALSE && doom->moves.crouching == FALSE)
	{
		if (doom->moves.jumping == TRUE)
		{
			doom->moves.flying = FALSE;
			if (doom->cam.pos_z + INC_POS_Z <= MAX_POS_Z)
				doom->cam.pos_z += INC_POS_Z;
			else if (doom->moves.jumping == TRUE)
			{
				doom->moves.jumping = FALSE;
				doom->moves.falling = TRUE;
			}
		}
		else
			doom->moves.jumping = FALSE;
	}
	else if (doom->moves.crouching == TRUE)
		doom->moves.jumping = FALSE;
}

void	ft_reset_pos_z(t_env *doom)
{
	if (doom->moves.falling == TRUE)
	{
		if (doom->cam.pos_z - INC_POS_Z >= DEFAULT_POS_Z)
			doom->cam.pos_z -= INC_POS_Z;
		else
			doom->moves.falling = FALSE;
	}
	else if (doom->moves.raising && doom->moves.flying == FALSE)
	{
		if (doom->cam.pos_z + INC_POS_Z <= DEFAULT_POS_Z)
			doom->cam.pos_z += INC_POS_Z;
		else
			doom->moves.raising = FALSE;
	}
}

void	ft_up_down_test(t_env *doom)
{
	if (doom->moves.up == TRUE)
	{
		doom->moves.flying = TRUE;
		if (doom->cam.pos_z + INC_POS_Z <= MAX_POS_Z + 0.01)
			doom->cam.pos_z += INC_POS_Z;
	}
	else if (doom->moves.down == TRUE)
	{
		doom->moves.flying = TRUE;
		if (doom->cam.pos_z - INC_POS_Z >= MIN_POS_Z)
			doom->cam.pos_z -= INC_POS_Z;
	}
}

void	ft_refresh_new_pos(t_env *doom)
{
	set_movespeed(doom);
	ft_crouch(doom);
	ft_jump(doom);
	ft_up_down_test(doom);
	ft_reset_pos_z(doom);
	//printf("pos_z = %.2f\traising = %d\tfalling = %d\tflying = %d\n", doom->cam.pos_z, doom->moves.raising, doom->moves.falling, doom->moves.flying);			//DEBUG
	if (doom->moves.strafe_right == TRUE)
		ft_strafe_right(doom);
	if (doom->moves.strafe_left == TRUE)
		ft_strafe_left(doom);
	if (doom->moves.backward == TRUE)
		ft_backward(doom);
	if (doom->moves.forward == TRUE)
		ft_forward(doom);
	if (doom->moves.rotate_left == TRUE)
	{
		doom->cam.angle += ROTATE_SPEED;
		if (doom->cam.angle > PI)
			doom->cam.angle = -PI;
	}
	if (doom->moves.rotate_right == TRUE)
	{
		doom->cam.angle -= ROTATE_SPEED;
		if (doom->cam.angle <= -PI)
			doom->cam.angle = PI;
	}
	if (doom->moves.rotate_up == TRUE)
		ft_rotate_up(doom);
	if (doom->moves.rotate_down == TRUE)
		ft_rotate_down(doom);
}

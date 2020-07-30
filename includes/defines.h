/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 18:18:53 by jcanteau          #+#    #+#             */
/*   Updated: 2020/07/30 09:42:34 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DEFINES_H
# define DEFINES_H

# define TRUE 1
# define FALSE 0

# define PI 3.14159

# define W 1000
# define H 800

# define MAX_DEPTH 20
# define FOV_RATIO 4
# define FOV_RATIO_STEP 0.5
# define SHADING_DEPTH 10
# define WALL_SIZE 64
# define SKY_ZOOM 2

# define PROJ_DIST 18
# define PROJ_DIST_STEP 0.75
# define MAX_PROJ_DIST 64
# define MIN_PROJ_DIST 2

# define MOVE_SPEED 0.035
# define RUN_RATIO 3
# define ROTATE_SPEED 0.05
# define UP_DOWN_ANGLE_SPEED 30
# define MAX_ANGLE_Z 1200

# define DEFAULT_POS_Z 32
# define INC_POS_Z 4
# define MAX_POS_Z 128
# define MIN_POS_Z 0.1
# define MAX_JUMP 60
# define MIN_CROUCH 15

# define WALL '#'
# define EMPTY '.'
# define DOOR 'D'
# define OBJECT 'O'
# define GRID 'G'
# define BARREL 'B'
# define BUTTON_OFF 'Y'
# define BUTTON_ON 'H'
# define DOOR_OPENED 'R'
# define HEALTH_POTION 'P'
# define KEY 'K'
# define TORCH 'T'

# define MAX_PULS_FUNKY_TEXTURES 50

# define BUTTON_RANGE 2

# define DOOR_OPENING_DURATION 2
# define MIN_ALTITUDE -32

# define MAX_PROCESSOR 16
# define FPS_TEST 0

# define NB_XPM 22

#endif

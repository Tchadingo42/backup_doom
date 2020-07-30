/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:34:34 by jcanteau          #+#    #+#             */
/*   Updated: 2020/07/30 10:48:01 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOM_H
# define DOOM_H

# include <stdio.h>

# include "../SDL2-2.0.12/include/SDL.h"
# include <SDL2/SDL_mixer.h>
# include <SDL2/SDL_ttf.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <time.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <pthread.h>
# include "../libft/libft.h"
# include "defines.h"
# include "colors.h"
# include "../fmod/inc/fmod.h"
# define SIZE 3

typedef enum		e_texture_id
{
	NORTH,
	SOUTH,
	WEST,
	EAST,
	FLOOR,
	SKY,
	GRID_XPM,
	CROSSHAIR,
	BARREL_XPM,
	BUTTON_OFF_XPM,
	BUTTON_ON_XPM,
	DOOR_METAL_XPM,
	HEALTH_POTION_XPM,
	KEY_XPM,
	TORCH_1_XPM,
	TORCH_2_XPM,
	TORCH_3_XPM,
	TORCH_4_XPM,
	TORCH_5_XPM,
	TORCH_6_XPM,
	TORCH_7_XPM,
	TORCH_8_XPM
}					t_texture_id;

typedef enum	e_motion
{
	CROUCHING,
	RAISING,
	JUMPING,
	FALLING,
	UP,
	DOWN,
	FLYING
}				t_motion;

typedef enum	e_switch_texture_mod
{
	NON_TEXTURED,
	SHADED,
	COLOR_ORIENTED,
	TEXTURED
}					t_switch_texture_mod;

typedef struct		s_map
{
	int				nbl;
	int				nbcol;
	size_t			cur_line;
	char			*data;
	int				*bright;
	int				*alt;
}					t_map;

typedef struct		s_camera
{
	double			pos_x;
	double			pos_y;
	double			pos_z;
	double			angle;
	int				angle_z;
	double			fov;
	double			fov_ratio;
	double			proj_dist;
}					t_camera;

typedef struct		s_movements
{
	char			strafe_left;
	char			strafe_right;
	char			forward;
	char			backward;
	char			rotate_left;
	char			rotate_right;
	char			rotate_up;
	char			rotate_down;
	char			running;
	char			crouching;
	char			raising;
	char			jumping;
	char			falling;
	char			up;
	char			down;
	char			flying;
	double			movespeed;
}					t_movements;

typedef struct		s_raycast
{
	int				x_;
	int				y_;
	double			deltadistx;
	double			deltadisty;
	double			sidedistx;
	double			sidedisty;
	char			side;
	double			eye_x;
	double			eye_y;
	int				test_x;
	int				test_y;
	double			ray_angle;
	double			distance_towall;
	int				stepx;
	int				stepy;
	double			sample_x;
	double			sample_y;
	double			test_point_x;
	double			test_point_y;
	double			test_angle;
	int				horizon;
	double			rowdistance;
	double			floorstepx;
	double			floorstepy;
	double			floorx;
	double			floory;
	int				text_x;
	int				text_y;
	int				orientation;
	int				ceiling;
	int				floor;
	unsigned int	tmp_x;
	unsigned int	tmp_y;
}					t_raycast;

typedef struct		s_xpm
{
	int				w;
	int				h;
	int				colormax;
	int				nchar;
	Uint32			*pixels;
	char			**color;
}					t_xpm;

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_pointd
{
	double			x;
	double			y;
}					t_pointd;

typedef struct		s_object_data
{
	t_pointd		pos;
	t_point			screen;
	t_point			cursor;
	double			vect_x;
	double			vect_y;
	double			h_;
	double			w_;
	int				x_;
	int				y_;
	int				delta_x_start;
	int				delta_x_end;
	int				type;
	double			dist;
	double			angle;
	int				in_fov;
}					t_object_data;

typedef struct		s_object
{
	t_object_data	data;
	struct s_object	*next;
}					t_object;

typedef struct		s_thread_env
{
	pthread_t		thread;
	char			work_done;
	t_raycast		rc;
	t_map			map;
	t_camera		cam;
	char			wall;
	t_xpm			*xpm;
	int				x_start;
	int				x_end;
	Uint32			*screen_pixels;
	void			*doom;
	void			*shared_data;
	char			transparent_found;
}					t_thread_env;

typedef struct		s_shared_data
{
	t_thread_env	*tab_thread_env;
	pthread_mutex_t	mutex;
	pthread_cond_t	cond;
	pthread_cond_t	cond_main;
	int				max_thread;
	int				all_work_done;
	int				copied;
	char			stop;
	double			depth_buf[W];
}					t_shared_data;

typedef struct		s_minimap
{
	int				i;
	int				j;
	int				x;
	int				y;
	int				def_x;
	int				def_y;
	char			done;
}					t_minimap;

typedef struct		s_text
{
	TTF_Font		*font;
	SDL_Surface		*welcome1;
	SDL_Surface		*welcome2;
	SDL_Color		black;
}					t_text;

typedef struct		s_fps
{
	SDL_Surface		*s;
	double			time_fps;
	double			time_tmp;
	unsigned int	frames;
	unsigned int	count_fps;
	char			test;
}					t_fps;

typedef struct		s_door
{
	int				x;
	int				y;
	int				start_alt;
	double			speed;
	double			start_time;
	struct s_door	*next;
}					t_door;

typedef struct		s_sound
{
	FMOD_SYSTEM		*system;
	FMOD_SOUND		*music;
	FMOD_SOUND		*jump;
	FMOD_SOUND		*switch_on;
	FMOD_SOUND		*switch_off;
	FMOD_SOUND		*door_opening;
	FMOD_SOUND		*door_closing;
	FMOD_SOUND		*laser_shot;
	FMOD_SOUND		*shotgun;
	FMOD_CHANNEL	*channel_music;
	int				state;
}					t_sound;

typedef struct		s_env
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Texture		*texture;
	SDL_Event		event;
	t_map			map;
	t_camera		cam;
	t_movements		moves;
	t_text			txt;
	t_door			*door;
	t_xpm			xpm[NB_XPM];
	Uint32			*screen_pixels;
	t_minimap		minimap;
	t_sound			sound;
	char			wall;
	int				pitch;
	int				block;
	int				h;
	t_fps			fps;
	double			music_puls;
	unsigned int	count_puls;
	struct timespec	time0;
	int				no_funky;
	t_shared_data	shared_data;
	char			new_values;
	t_object		obj;
	int				screen_x;
	int				screen_y;
}					t_env;

typedef struct				s_sprite
{
        SDL_Surface			*img;
}					t_sprite;

typedef struct				s_elem
{
	t_sprite			sprite[SIZE];
}					t_elem;

void				ft_doom(char *mapfile);
void				ft_sdl(t_env *doom);
void				ft_exit(t_env *doom, int exit_type, char *message);
void				ft_print(t_env *doom);
void				ft_initialize(t_env *doom, char *mapfile);
void				ft_init_map(t_env *doom, char *mapfile);
void				ft_movement(t_env *doom);
void				ft_stop_movement(t_env *doom);
void				ft_settings(t_env *doom);
void				ft_refresh_new_pos(t_env *doom);
void				ft_error(t_map *m, int code, char *line);

int					ft_check_line(t_map *m);
int					ft_check_borders(t_map *m);
void				ft_count_lines_columns(t_map *m, char *mapfile, int fd);
void				ft_norme(int code);

void				ft_calc_sampling_x(t_thread_env *e);

void				ft_fix_fisheye_distorsion(t_thread_env *e);
void				ft_set_ceiling_floor(t_thread_env *e);
void				ft_draw_ceiling(t_thread_env *e);
void				ft_draw_wall(t_thread_env *e);
void				ft_draw_floor(t_thread_env *e);
void				ft_draw_minimap(t_env *doom);
void				ft_set_sdl_minimap_colors(t_env *doom);
void				ft_apply_textured_wall(t_thread_env *e);
void				ft_apply_color_oriented_wall(t_thread_env *e);
void				ft_apply_shaded_wall(t_thread_env *e);
void				ft_free_map(t_map *m);
void				ft_free_door(t_door *list);
void				ft_destroy_texture_renderer_window(t_env *doom);
void				ft_calc_next_intersection(t_thread_env *e);
void				ft_calc_next_intersection_transparent(t_thread_env *e);

void				ft_key_pressed(t_env *doom);
void				ft_key_released(t_env *doom);

double				get_time(t_env *doom);
void				ft_funky_textures(t_env *doom);
void				ft_draw_fps(t_env *doom);
void				draw_text(t_env *doom, unsigned int pos, SDL_Surface *text);
void				draw_centered_text(t_env *doom, SDL_Surface *text);

void				resolve_door(t_env *doom);
void				animation_opening_door(t_env *doom);

void				editor(char *mapfile);
void				save_in_file(t_env *doom);

int					get_xpm(char *xpm_file, t_xpm *xpm);
int					xpm_fill(t_xpm *xpm, char *line, int num);
void				free_one_xpm(t_xpm *xpm);
void				free_xpm(t_env *doom);
void				ft_free_obj(t_object **obj);

void				init_pthread(t_env *doom);
void				ft_raycaster(t_thread_env *e);
void				free_thread_env(t_shared_data *shared_data);
int					ft_malloc_tab(t_map *m);
void				update_thread_env(t_thread_env *thread_env);

void				ft_draw_crosshair(t_env *doom);

void				ft_fmod(t_env *doom);
void				ft_free_fmod(t_env *doom);
void				ft_switch_button(t_env *doom);

void				init_door(t_env *doom, int door_y, int door_x);

void				ft_draw_objects(t_env *e);
void				ft_count_objects(t_env *doom);
int					ft_choose_and_init_sprite(t_env *e, t_object *tmp);

void				init_draw_barrel(t_env *e, t_object *tmp);
void				init_draw_health_potion(t_env *e, t_object *tmp);
void				init_draw_key(t_env *e, t_object *tmp);
void				init_draw_torch(t_env *e, t_object *tmp);

void				ft_load_textures(t_env *doom);

#endif

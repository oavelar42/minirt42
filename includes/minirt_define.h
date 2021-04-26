/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_define.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 11:07:35 by oavelar           #+#    #+#             */
/*   Updated: 2021/04/10 14:47:38 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_DEFINE_H
#define MINIRT_DEFINE_H

# define EMPTY_LINE_GNL '\0'

# if defined(__linux__) || defined(__unix__)
#  define ESC 65307
#  define SPACE 32
#  define CLOSE 33
#  define LEFT 65361
#  define RIGHT 65363
#  define DOWN 65364
#  define UP 65362
#  define C 99
#  define S 115

# elif __APPLE__
#  define ESC 54
#  define SPACE 49
#  define CLOSE 17
#  define LEFT 123
#  define RIGHT 124
#  define DOWN 125
#  define UP 126
# endif

/*
** main FUNCIONS
*/
int	main(int argc, char **argv);
void	scene_init(t_scene *scene);
void	check_args(int argc, char **argv, t_scene *scene);
void    read_scene(char *file, t_scene *scene);
void	display_scene(t_scene *scene);
void	scene_quit(t_scene *scene);

/*
** read FUNCIONS
*/
void	read_element(char **line, t_scene *scene);
void	check_scene_values(t_scene *scene);
void		read_resolution(char **line, t_scene *scene);
void		read_ambient(char **line, t_scene *scene);

void	delete_cameras(t_cam **cams);
void	next_camera(t_scene *scene);

void		read_light(char **line, t_scene *scene);
t_light		*create_light(char **line, t_scene *scene);
void		add_light(t_light **lights, t_light *new_light);
void		delete_lights(t_light **lights);


void		read_sphere(char **line, t_scene *scene);
t_sphere	*create_sphere(char **line, t_scene *scene);
void		add_sphere(t_sphere **spheres, t_sphere *new_sphere);
void		delete_spheres(t_sphere **spheres);

/*
** bmp FUNCIONS
*/
void		save_image_bmp(t_scene *scene);
void		header_data(int fd, t_scene *scene);
void		pixel_data(int fd, t_scene *scene);

/*
** render FUNCIONS
*/
void	render_scene(t_scene *scene);
void	look_at(t_cam *cam);
void	set_ray(t_ray *ray, t_scene *scene, double x, double y);
void	save_pixel(char **buffer, t_color color);

void	cast_ray(t_ray *ray, t_scene *scene);

/*
** shade FUNCIONS
*/

/*
** auxiliar FUNCTIONS
*/

void		skip_blanks(char **str);
void		skip_digits(char **str);
void		skip_char(char **str, int c);
int			get_int(char **line, t_scene *scene);
double		get_double(char **line, t_scene *scene);

void	    normalize_vec3(t_vec3 *v1);
t_color	    get_color_vec3(char **line, t_scene *scene);
t_vec3	    get_vec3(char **line, t_scene *scene);

t_vec3      new_vec3(double x, double y, double z);
t_vec3		esc_vec3(double k, t_vec3 v);
t_vec3	    add_vec3(t_vec3 u, t_vec3 v);

t_vec3		cross_vec3(t_vec3 v1, t_vec3 v2);
t_vec3		mult_vec3_mat3x3(t_vec3 v, t_mat3x3 m);

/*
** others
*/
int	key_hook(int keycode, t_scene *scene);
int	refresh(t_scene *scene);
int	close_program(t_scene *scene);
void	exit_error_msg(t_error id, t_scene *scene);
void	push_image(t_scene *scene);
void	move_element(int keycode, t_scene *scene);
void	move_x_pos(t_scene *scene, int key);
void	move_x_neg(t_scene *scene, int key);
void	move_y_pos(t_scene *scene, int key);
void	move_y_neg(t_scene *scene, int key);

#endif

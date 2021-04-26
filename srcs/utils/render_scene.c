/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 11:07:35 by oavelar           #+#    #+#             */
/*   Updated: 2021/04/10 14:47:38 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	look_at(t_cam *cam)
{
	t_vec3	c_dir;

	c_dir = cam->dir;
	cam->cam_to_world.v1.z = 0;
	if (!c_dir.x && !c_dir.y)
	{
		cam->cam_to_world.v1.y = 0;
		if (c_dir.z > 0)
			cam->cam_to_world.v1.x = -1.0;
		else if (c_dir.z < 0)
			cam->cam_to_world.v1.x = 1.0;
	}
	else
	{
		cam->cam_to_world.v1.x = c_dir.y;
		cam->cam_to_world.v1.y = -1.0 * c_dir.x;
	}
	cam->cam_to_world.v2 = cross_vec3(cam->cam_to_world.v1, c_dir);
	cam->cam_to_world.v3 = esc_vec3(-1, c_dir);
	normalize_vec3(&cam->cam_to_world.v1);
	normalize_vec3(&cam->cam_to_world.v2);
	normalize_vec3(&cam->cam_to_world.v3);
}

void	set_ray(t_ray *ray, t_scene *scene, double x, double y)
{
	ray->dir.x = (2 * ((x + 0.5) / scene->res.width) - 1)
		* tan(scene->cams->fov / 2 * M_PI / 180) * scene->res.ratio;
	ray->dir.y = (1 - 2 * (y + 0.5) / scene->res.height)
		* tan(scene->cams->fov / 2 * M_PI / 180);
	ray->dir.z = -1;
	ray->dir = mult_vec3_mat3x3(ray->dir, scene->cams->cam_to_world);
	normalize_vec3(&ray->dir);
	ray->t = DBL_MAX;
	ray->color = (t_color){0, 0, 0};
	ray->origin = scene->cams->pos;
	cast_ray(ray, scene);
}

void	cast_ray(t_ray *ray, t_scene *scene)
{
	void	*objs;

	objs = scene->spheres;
	while (objs)
	{
		render_sphere(ray, scene, (t_sphere *)objs);
		objs = ((t_sphere *)objs)->next;
	}
}

void	save_pixel(char **buffer, t_color color)
{
	**buffer = (char)floor(color.b);
	(*buffer)++;
	**buffer = (char)floor(color.g);
	(*buffer)++;
	**buffer = (char)floor(color.r);
	(*buffer)++;
	(*buffer)++;
}

void	render_scene(t_scene *scene)
{
	t_ray	ray;
	char	*buffer;
	int	x;
	int	y;

	look_at(scene->cams);
	buffer = scene->img_address;
	y = 0;
	while (y < scene->res.height)
	{
		x = 0;
		while (x < scene->res.width)
		{
			set_ray(&ray, scene, (double)x, (double)y);
			save_pixel(&buffer, ray.color);
			x++;
		}
		y++;
		printf("\rRendering progress...WAIT... %d%%",
			 y * 100 / scene->res.height);
	}
	if (!scene->save_bmp)
		printf("\r\n\n Change camera: PRESS KEYCODE\n\n");
}

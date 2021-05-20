/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 11:07:35 by oavelar           #+#    #+#             */
/*   Updated: 2021/05/20 19:49:57 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	render_plane(t_ray *ray, t_scene *scene, t_plane *plane)
{
	double	t;
	t_hit	p;

	if ((t = intersect_plane(ray, plane)))
	{
		if (t < ray->t)
		{
			ray->t = t;
			p.point = add_vec3(ray->origin, esc_vec3(ray->t, ray->dir));
			p.normal = plane->n_dir;
			normalize_vec3(&p.normal);
			p.color = plane->color;
			ray->color = get_surface_data(scene, &p);
		}
	}
}

double	intersect_plane(t_ray *ray, t_plane *plane)
{
	double	t;
	double	denom;

	t = 0;
	denom = dot_vec3(ray->dir, plane->n_dir);
	if (fabs(denom) > 0.00001)
		t = dot_vec3(sub_vec3(plane->point,
					ray->origin), plane->n_dir) / denom;
	if (t >= 0)
		return (t);
	else
		return (0);
}

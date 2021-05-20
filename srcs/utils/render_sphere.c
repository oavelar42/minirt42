/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 11:07:35 by oavelar           #+#    #+#             */
/*   Updated: 2021/05/20 19:50:04 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	intersect_sphere(t_ray *ray, t_sphere *sphere)
{
	double	t;
	t_vec3	oc;
	double	tca;
	double	d2;

	oc = sub_vec3(sphere->centre, ray->origin);
	tca = dot_vec3(oc, ray->dir);
	if (tca < 0)
		return (0);
	d2 = dot_vec3(oc, oc) - tca * tca;
	if (d2 > sphere->radius * sphere->radius)
		return (0);
	t = tca - sqrt(sphere->radius * sphere->radius - d2);
	return (t);
}

void	render_sphere(t_ray *ray, t_scene *scene, t_sphere *sphere)
{
	double	t;
	t_hit	p;

	if ((t = intersect_sphere(ray, sphere)))
	{
		if (t < ray->t)
		{
			ray->t = t;
			p.point = add_vec3(ray->origin, esc_vec3(ray->t, ray->dir));
			p.normal = sub_vec3(p.point, sphere->centre);
			normalize_vec3(&p.normal);
			p.color = sphere->color;
			ray->color = get_surface_data(scene, &p);
		}
	}
}

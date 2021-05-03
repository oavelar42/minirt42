/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 11:07:35 by oavelar           #+#    #+#             */
/*   Updated: 2021/04/10 14:47:38 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	new_vec3(double x, double y, double z)
{
	t_vec3	v1;

	v1.x = x;
	v1.y = y;
	v1.z = z;
	return (v1);
}

t_vec3	sub_vec3(t_vec3 u, t_vec3 v)
{
	t_vec3	w;

	w.x = u.x - v.x;
	w.y = u.y - v.y;
	w.z = u.z - v.z;
	return (w);
}

t_vec3	add_vec3(t_vec3 u, t_vec3 v)
{
	t_vec3	w;

	w.x = u.x + v.x;
	w.y = u.y + v.y;
	w.z = u.z + v.z;
	return (w);
}

t_vec3	esc_vec3(double k, t_vec3 v)
{
	t_vec3 t;

	t.x = k * v.x;
	t.y = k * v.y;
	t.z = k * v.z;
	return (t);
}

double	dot_vec3(t_vec3 u, t_vec3 v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z);
}

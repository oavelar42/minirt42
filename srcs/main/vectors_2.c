/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 11:07:35 by oavelar           #+#    #+#             */
/*   Updated: 2021/05/20 19:49:02 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	normalize_vec3(t_vec3 *v1)
{
	double	mod;

	mod = sqrt(dot_vec3(*v1, *v1));
	v1->x /= mod;
	v1->y /= mod;
	v1->z /= mod;
}

int	range_vec3(t_vec3 v1, double min, double max)
{
	return (v1.x < min || v1.x > max || v1.y < min
		|| v1.y > max || v1.z < min || v1.z > max);
}

int	ft_isnull_vec3(t_vec3 v1)
{
	return (v1.x == 0.0 && v1.y == 0.0 && v1.z == 0.0);
}

t_color	get_color_vec3(char **line, t_scene *scene)
{
	t_color	vec3;

	skip_blanks(line);
	vec3.r = get_double(line, scene);
	skip_blanks(line);
	skip_char(line, ',');
	vec3.g = get_double(line, scene);
	skip_blanks(line);
	skip_char(line, ',');
	vec3.b = get_double(line, scene);
	if ((vec3.r < 0 || vec3.r > 255) || (vec3.g < 0
			|| vec3.g > 255) || (vec3.b < 0 || vec3.b > 255))
		exit_error_msg(RGB_RANGE_ERR, scene);
	return (vec3);
}

t_vec3	get_vec3(char **line, t_scene *scene)
{
	t_vec3	vec3;

	skip_blanks(line);
	vec3.x = get_double(line, scene);
	skip_blanks(line);
	skip_char(line, ',');
	vec3.y = get_double(line, scene);
	skip_blanks(line);
	skip_char(line, ',');
	vec3.z = get_double(line, scene);
	return (vec3);
}

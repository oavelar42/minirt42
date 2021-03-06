/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 11:07:35 by oavelar           #+#    #+#             */
/*   Updated: 2021/05/20 19:49:38 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	add_sphere(t_sphere **spheres, t_sphere *new_sphere)
{
	t_sphere	*last;

	if (!spheres || !new_sphere)
		return ;
	if (!*spheres)
	{
		*spheres = new_sphere;
		return ;
	}
	last = *spheres;
	while (last->next)
		last = last->next;
	last->next = new_sphere;
}

t_sphere	*create_sphere(char **line, t_scene *scene)
{
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		exit_error_msg(DEFAULT_ERR, scene);
	sphere->centre = get_vec3(line, scene);
	sphere->radius = get_double(line, scene) / 2;
	sphere->color = get_color_vec3(line, scene);
	skip_blanks(line);
	if (**line != EMPTY_LINE_GNL)
		exit_error_msg(SCENE_FORMAT_ERR, scene);
	sphere->next = NULL;
	return (sphere);
}

void	read_sphere(char **line, t_scene *scene)
{
	t_sphere	*new_sphere;

	*line += 3;
	new_sphere = create_sphere(line, scene);
	add_sphere(&scene->spheres, new_sphere);
	return ;
}

void	delete_spheres(t_sphere **spheres)
{
	t_sphere	*current;
	t_sphere	*node;

	if (!*spheres || !spheres)
		return ;
	current = *spheres;
	while (current)
	{
		node = current->next;
		free(current);
		current = node;
	}
	*spheres = NULL;
}

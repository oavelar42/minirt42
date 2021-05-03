/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 11:07:35 by oavelar           #+#    #+#             */
/*   Updated: 2021/04/10 14:47:38 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	add_plane(t_plane **planes, t_plane *new_plane)
{
	t_plane	*last;

	if (!planes || !new_plane)
		return ;
	if (!*planes)
	{
		*planes = new_plane;
		return ;
	}
	last = *planes;
	while (last->next)
		last = last->next;
	last->next = new_plane;
}

t_plane	*create_plane(char **line, t_scene *scene)
{
	t_plane	*plane;

	if (!(plane = malloc(sizeof(t_plane))))
		exit_error_msg(DEFAULT_ERR, scene);
	plane->point = get_vec3(line, scene);
	plane->n_dir = get_vec3(line, scene);
	if (range_vec3(plane->n_dir, -1.0, 1.0))
		exit_error_msg(VEC_RANGE_ERR, scene);
	plane->color = get_color_vec3(line, scene);
	skip_blanks(line);
	if (**line != EMPTY_LINE_GNL)
		exit_error_msg(SCENE_FORMAT_ERR, scene);
	plane->next = NULL;
	return (plane);
}

void	read_plane(char **line, t_scene *scene)
{
	t_plane	*new_plane;

	*line += 3;
	new_plane = create_plane(line, scene);
	add_plane(&scene->planes, new_plane);
	return ;
}

void	delete_planes(t_plane **planes)
{
	t_plane	*current;
	t_plane	*node;

	if (!*planes || !planes)
		return ;
	current = *planes;
	while (current)
	{
		node = current->next;
		free(current);
		current = node;
	}
	*planes = NULL;
}
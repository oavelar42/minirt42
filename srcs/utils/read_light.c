/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 11:07:35 by oavelar           #+#    #+#             */
/*   Updated: 2021/04/10 14:47:38 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		add_light(t_light **lights, t_light *new_light)
{
	t_light	*last;

	if (!lights || !new_light)
		return ;
	if (!*lights)
	{
		*lights = new_light;
		return ;
	}
	last = *lights;
	while (last->next)
		last = last->next;
	last->next = new_light;
}

t_light		*create_light(char **line, t_scene *scene)
{
	t_light	*light;

	if (!(light = malloc(sizeof(t_light))))
		exit_error_msg(DEFAULT_ERR, scene);
	light->pos = get_vec3(line, scene);
	light->lum = get_double(line, scene);
	if (light->lum < 0.0 || light->lum > 1.0)
		exit_error_msg(VALUE_RANGE_ERR, scene);
	light->color = get_color_vec3(line, scene);
	skip_blanks(line);
	if (**line != EMPTY_LINE_GNL)
		exit_error_msg(SCENE_FORMAT_ERR, scene);
	light->next = NULL;
	return (light);
}

void		read_light(char **line, t_scene *scene)
{
	t_light	*new_light;

	*line += 2;
	new_light = create_light(line, scene);
	add_light(&scene->lights, new_light);
	return ;
}

void		delete_lights(t_light **lights)
{
	t_light	*current;
	t_light	*node;

	if (!lights || !*lights)
		return ;
	current = *lights;
	while (current)
	{
		node = current->next;
		free(current);
		current = node;
	}
	*lights = NULL;
}
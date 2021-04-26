/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_elem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 11:07:35 by oavelar           #+#    #+#             */
/*   Updated: 2021/04/10 14:47:38 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	read_resolution(char **line, t_scene *scene)
{
	if (scene->res.declared)
		exit_error_msg(RES_DECLARED, scene);
	scene->res.declared = 1;
	*line += 2;
	scene->res.width = get_int(line, scene);
	if (scene->res.width > 1800)
		scene->res.width = 1800;
	scene->res.height = get_int(line, scene);
	if (scene->res.height > 1000)
		scene->res.height = 1000;
	scene->res.ratio = (double)scene->res.width / (double)scene->res.height;
	if (scene->res.ratio <= 0)
		exit_error_msg(SCENE_FORMAT_ERR, scene);
	skip_blanks(line);
	if (**line == EMPTY_LINE_GNL)
		return ;
	exit_error_msg(SCENE_FORMAT_ERR, scene);
}

void	read_ambient(char **line, t_scene *scene)
{
	if (scene->amb.declared)
		exit_error_msg(AMB_DECLARED, scene);
	scene->amb.declared = 1;
	*line += 2;
	scene->amb.bright = get_double(line, scene);
	if (scene->amb.bright < 0.0 || scene->amb.bright > 1.0)
		exit_error_msg(VALUE_RANGE_ERR, scene);
	scene->amb.color = get_color_vec3(line, scene);
	skip_blanks(line);
	if (**line == EMPTY_LINE_GNL)
		return ;
	exit_error_msg(SCENE_FORMAT_ERR, scene);
}

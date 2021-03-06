/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 11:07:35 by oavelar           #+#    #+#             */
/*   Updated: 2021/05/20 19:49:33 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	check_scene_values(t_scene *scene)
{
	if (!scene->res.declared)
		exit_error_msg(SCENE_FORMAT_ERR, scene);
	if (!scene->cam_count)
		exit_error_msg(NO_CAM_ERR, scene);
}

void	read_element(char **line, t_scene *scene)
{
	if (!ft_strncmp(*line, "R ", 2))
		read_resolution(line, scene);
	else if (!ft_strncmp(*line, "A ", 2))
		read_ambient(line, scene);
	else if (!ft_strncmp(*line, "c ", 2))
		read_camera(line, scene);
	else if (!ft_strncmp(*line, "l ", 2))
		read_light(line, scene);
	else if (!ft_strncmp(*line, "sp ", 3))
		read_sphere(line, scene);
	else if (!ft_strncmp(*line, "pl ", 3))
		read_plane(line, scene);
	else if (!ft_strncmp(*line, "cy ", 3))
		read_cyl(line, scene);
	else if (!ft_strncmp(*line, "sq ", 3))
		read_square(line, scene);
	else if (!ft_strncmp(*line, "tr ", 3))
		read_triangle(line, scene);
	else if (**line != EMPTY_LINE_GNL)
		exit_error_msg(SCENE_FORMAT_ERR, scene);
	return ;
}

void	read_scene(char *file, t_scene *scene)
{
	int		fd;
	char	*line;
	char	*temp;
	int		bytes;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit_error_msg(SCENE_FILE_ERR, scene);
	while ((bytes = get_next_line(fd, &line)) > 0)
	{
		temp = line;
		read_element(&line, scene);
		free(temp);
	}
	free(line);
	close(fd);
	check_scene_values(scene);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 11:07:35 by oavelar           #+#    #+#             */
/*   Updated: 2021/04/10 14:47:38 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	check_args(int argc, char **argv, t_scene *scene)
{
	if (argc < 2 || argc < 3)
		exit_error_msg(ARGS_ERR, scene);
	if (ft_strlen(argv[1]) < 4)
		exit_error_msg(SCENE_FILE_ERR, scene);
	if (argc == 3)
	{
		if (!ft_strcmp(argv[2], "--save"))
			scene->save_bmp = 1;
		else if (!strcmp(argv[2], "--shine"))
			scene->specular = 1;
		else if (!ft_strcmp(argv[2], "--sepia"))
			scene->sepia = 1;
		else if (!ft_strcmp(argv[2], "--stereoscopy"))
			scene->stereoscopy = 1;
		else
			exit_error_msg(OPT_ERR, scene);
	}
	if (ft_strncmp((argv[1] + ft_strlen (argv[1]) - 3), ".rt", 3))
		exit_error_msg(SCENE_FILE_ERR, scene);
}

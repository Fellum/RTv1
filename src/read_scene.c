
#include "read_scene.h"
#include "ft_string.h"

t_scene	*read_scene(t_arguments	*args)
{
	t_scene	*res;

	if (!(res = ft_memalloc(sizeof(t_scene))))
		return (NULL);

	res->cam.width = args->w_width;
	res->cam.height = args->w_height;
	return (res);
}

void	free_scene(t_scene *scene)
{
	free(scene);
}


#include "read_scene.h"
#include "ft_string.h"

t_scene	*read_scene(t_arguments	*args)
{
	t_scene	*res;

	if (!(res = ft_memalloc(sizeof(t_scene))))
		return (NULL);

	res->cam.origin = (t_vector){0, 0, -500};
	res->cam.direction = (t_vector){0, 0, 500};
	res->cam.right = (t_vector){1, 0, 0};
	res->cam.up = (t_vector){0, 1, 0};
	res->cam.width = args->w_width;
	res->cam.height = args->w_height;

	t_object	tmp = {SPHERE, {0, 50, 50}, {0, 0,0},
					   {100, 100, 0, 0xFF}, 150};
	ft_lstadd(&(res->objects), ft_lstnew_node(&tmp, sizeof(t_object)));
	tmp = (t_object){SPHERE, {0, 0, 25}, {0, 0,0},
					   {100, 0, 100, 0xFF}, 20};
	ft_lstadd(&(res->objects), ft_lstnew_node(&tmp, sizeof(t_object)));

	tmp = (t_object){INDIRECT_LIGHT, {0, -400, -500}, {0, 0,0},
					 {100, 0, 100, 0xFF}, 0.7};
	ft_lstadd(&(res->lights), ft_lstnew_node(&tmp, sizeof(t_object)));

	tmp = (t_object){INDIRECT_LIGHT, {0, 400, -500}, {0, 0,0},
					 {100, 0, 100, 0xFF}, 0.3};
	ft_lstadd(&(res->lights), ft_lstnew_node(&tmp, sizeof(t_object)));
	return (res);
}

void	free_scene(t_scene *scene)
{
	free(scene);
}


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

	t_object	tmp = {SPHERE, {-150, 0, 50}, {0, 0,0},
					   {0, 255, 255, 0xFF}, 100};
	ft_lstadd(&(res->objects), ft_lstnew_node(&tmp, sizeof(t_object)));


	tmp.position.x = 150;
	tmp.size = 100;
	tmp.color.green = 0;
	ft_lstadd(&(res->objects), ft_lstnew_node(&tmp, sizeof(t_object)));

	tmp.position.x = 0;
	tmp.position.y = 0;
	tmp.size = 1000;
	tmp.color.red = 100;
	ft_lstadd(&(res->objects), ft_lstnew_node(&tmp, sizeof(t_object)));


	tmp = (t_object){INDIRECT_LIGHT, {0, 0, -450}, {0, 0,0},
					 {100, 0, 100, 0xFF}, 1};


	ft_lstadd(&(res->lights), ft_lstnew_node(&tmp, sizeof(t_object)));
	tmp.position.y = 0;
	tmp.position.z = 0;
//	ft_lstadd(&(res->lights), ft_lstnew_node(&tmp, sizeof(t_object)));

	return (res);
}

void	free_scene(t_scene *scene)
{
	free(scene);
}

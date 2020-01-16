
#include "read_scene.h"
#include "ft_string.h"

t_scene	*read_scene(t_arguments	*args)
{
	t_scene	*res;

	if (!(res = ft_memalloc(sizeof(t_scene))))
		return (NULL);

	res->cam.origin = (t_vector){0, 0, -1000};
	res->cam.direction = (t_vector){0, 0, 200};
	res->cam.right = (t_vector){1, 0, 0};
	res->cam.up = (t_vector){0, 1, 0};
	res->cam.width = args->w_width;
	res->cam.height = args->w_height;

	t_object	tmp = {SPHERE, {-150, 0, 300}, {0, 0,0},
					   {0, 255, 255, 0xFF}, 100};
	ft_lstadd(&(res->objects), ft_lstnew_node(&tmp, sizeof(t_object)));


	tmp.position.x = 150;
	tmp.size = 100;
	tmp.color.green = 128;
	ft_lstadd(&(res->objects), ft_lstnew_node(&tmp, sizeof(t_object)));

	tmp.position.x = -75;
	tmp.position.y = 0;
	tmp.position.z = -50;
	tmp.size = 20;
	tmp.color.green = 0;
	ft_lstadd(&(res->objects), ft_lstnew_node(&tmp, sizeof(t_object)));


	//tmp.type = INV_SPHERE;
	tmp.position.x = 0;
	tmp.position.y = 0;
	tmp.position.z = 300;
	tmp.size = 50;

	ft_lstadd(&(res->objects), ft_lstnew_node(&tmp, sizeof(t_object)));


	tmp.type = PLANE;
	tmp.position.x = -500;
	tmp.position.y = 0;
	tmp.position.z = 500;
	tmp.color.red = 50;
	tmp.direction = (t_vector){1, 0, 0};
	ft_lstadd(&(res->objects), ft_lstnew_node(&tmp, sizeof(t_object)));

	tmp.type = PLANE;
	tmp.position.x = 500;
	tmp.position.y = 0;
	tmp.position.z = 500;
	tmp.color.red = 100;
	tmp.direction = (t_vector){-1, 0, 0};
	ft_lstadd(&(res->objects), ft_lstnew_node(&tmp, sizeof(t_object)));

	tmp.type = PLANE;
	tmp.position.x = 0;
	tmp.position.y = 500;
	tmp.position.z = 500;
	tmp.color.red = 150;
	tmp.direction = (t_vector){0, -1, 0};
	ft_lstadd(&(res->objects), ft_lstnew_node(&tmp, sizeof(t_object)));

	tmp.type = PLANE;
	tmp.position.x = 0;
	tmp.position.y = -500;
	tmp.position.z = 500;
	tmp.color.red = 200;
	tmp.direction = (t_vector){0, 1, 0};
	ft_lstadd(&(res->objects), ft_lstnew_node(&tmp, sizeof(t_object)));

	tmp.type = PLANE;
	tmp.position.x = 0;
	tmp.position.y = 0;
	tmp.position.z = 500;
	tmp.color.red = 255;
	tmp.direction = (t_vector){0, 0, -1};
	ft_lstadd(&(res->objects), ft_lstnew_node(&tmp, sizeof(t_object)));


	tmp = (t_object){INDIRECT_LIGHT, {-300, 300, 200}, {0, 0,0},
					 {100, 0, 100, 0xFF}, 0.5};


	ft_lstadd(&(res->lights), ft_lstnew_node(&tmp, sizeof(t_object)));
	tmp.position.x = 0;
	tmp.position.z = -300;
	ft_lstadd(&(res->lights), ft_lstnew_node(&tmp, sizeof(t_object)));

	return (res);
}

void	free_scene(t_scene *scene)
{
	free(scene);
}

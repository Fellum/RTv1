
#include "rtv_structs.h"
#include "vector.h"

double		get_light_k(t_intersec inter, t_object *light)
{
	t_vector n1, n2, n3;
	n1 = ft_vecsum(ft_vecscale(inter.ray, inter.rlen), inter.start);
	n2 = ft_vecsub(n1 ,inter.obj->position);
	n3 = ft_vecsub(light->position, n1);

	double tmp = ft_vecdot(n2, n3) / ft_veclen(n2) / ft_veclen(n3);
	if (tmp < 0)
		return (0);
	else
		return (tmp * light->size);
}

double 		get_intersection(t_vector or, t_vector ray, t_object *obj)
{
	if (obj->type == SPHERE)
	{
		return (sphere_intersection(&or, &ray, &(obj->position), obj->size));
	}
}

char 		is_lighted(t_intersec inter, t_object *light, t_list *objects)
{
	t_list_node	*cur;
	double cur_inter;
	t_vector n1, n3;

	n1 = ft_vecsum(ft_vecscale(inter.ray, inter.rlen), inter.start);
	n3 = ft_vecsub(light->position, n1 );

	cur = objects->begin;
	while (cur)
	{
		cur_inter = get_intersection(light->position, n3, cur->content);
		if (!isnan(cur_inter) && cur_inter - 1 > 0.00001)
			return (0);
		cur = cur->next;
	}
	return (1);
}

double		get_lights_k(t_intersec inter, t_list *lights, t_list *objects)
{
	t_list_node	*cur_l;
	double res;

	res = 0;
	cur_l = lights->begin;
	while (cur_l)
	{
		if (is_lighted(inter, cur_l->content, objects))
			res += get_light_k(inter, cur_l->content);
		cur_l = cur_l->next;
	}
	return (res);
}


t_intersec	find_nearest_inter(t_scene *scene, t_vector ray)
{
	t_intersec	res;
	double cur_inter;
	t_list_node	*cur;

	res.rlen = NAN;
	cur = scene->objects.begin;
	while (cur)
	{
		cur_inter = get_intersection(scene->cam.origin, ray, cur->content);
		if (isnan(res.rlen) || (cur_inter > 1.0 && cur_inter < res.rlen))
		{
			res.rlen = cur_inter;
			res.obj = cur->content;
			res.ray = ray;
		}
		cur = cur->next;
	}
	res.start = scene->cam.origin;
	return (res);
}

t_color		get_pixel_color(t_scene *scene, t_vector ray, t_vector origin)
{
	double k;
	t_color res = {0 , 0x0 , 0x0, 0xFF};

	t_intersec	tmp;

	tmp = find_nearest_inter(scene, ray);
	if (isnan(tmp.rlen))
		return (res);
	else
	{
		k = get_lights_k(tmp, &(scene->lights), &(scene->objects));
		res.red = tmp.obj->color.red * k;
		res.green = tmp.obj->color.green * k;
		res.blue = tmp.obj->color.blue * k;
		return (res);
	}
}

void 		render_scene(SDL_Renderer *rend, t_scene *scene)
{
	t_vector	cur_vec;
	t_vector	tmp;
	int			cur_x;
	int 		cur_y;
	t_color		cl;

	cur_y = 0;
	cur_vec = ft_vecsum(scene->cam.direction, ft_vecscale(scene->cam.up, (int)(scene->cam.height / 2)));
	cur_vec = ft_vecsub(cur_vec, ft_vecscale(scene->cam.right, (int)(scene->cam.width / 2)));
	while (cur_y < scene->cam.height)
	{
		cur_x = 0;
		tmp = cur_vec;
		while (cur_x < scene->cam.width)
		{
			cl = get_pixel_color(scene, cur_vec, scene->cam.origin);
			SDL_SetRenderDrawColor(rend, cl.red, cl.green, cl.blue, cl.alpha);
			SDL_RenderDrawPoint(rend, cur_x, cur_y);
			cur_vec = ft_vecsum(cur_vec, scene->cam.right);
			cur_x++;
		}
		cur_y++;
		cur_vec = ft_vecsub(tmp, scene->cam.up);
	}
}

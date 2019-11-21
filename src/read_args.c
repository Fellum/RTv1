
#include "read_args.h"
#include "ft_string.h"

t_arguments		*read_arguments(int argc, char **argv)
{
	t_arguments	*res;

	if (!(res = ft_memalloc(sizeof(t_arguments))))
		return (NULL);
	res->w_height = 500;
	res->w_width = 500;
	res->fname = argv[0];
	return (res);
}

void			free_arguments(t_arguments *args)
{
	free(args);
}

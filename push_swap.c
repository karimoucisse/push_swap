#include "libft.h"

int ft_check_args(char **av)
{
	int i;

    i = 1;
	while(av[i])
	{
		//if(ft_strncmp(av[i], "0", ft_strlen(av[i])) && ft_atoi(av[i]) == 0)
		printf("%s", av[i]);
		i++;
	}
	return (1);
}

int ft_check_espace(char *av, int ac)
{
	int i;

	if(av[0] == ' ' || av[ft_strlen(av) - 1] == ' ')
		return (0);
    i = 0;
    while(*av)
    {
        if(*av == ' ')
            i++;
        else
		    i = 0;
		if (i > 1)
		    return (0);
		av++;
    }
    return (1);
}
int ft_check_char(char *av, int ac)
{
	int i;

    i = 0;
	if(!ft_check_espace(av, ac))
		return (0);
	// while(av[i])
	// {
	// 	if(av[i] == ' ' && (av[i+1] && av[i+1] == ' '))
	// 		return (0);
	// 	else if(av[i] == ' ')
	// 		i++;
	// 	if(av[i] != '0' && !ft_isdigit(av[i]))
	// 		return (0);
	// 	i++;
	// }
	printf("yes yes!\n");
	return (1);
}
int main(int ac, char **av)
{
	if(ac < 2)
		return (1);
	if(ac == 2)
		ft_check_char(av[1], ac);
	// if(ac > 2)
	// 	ft_check_args(av);
}

#include "../includes/push_swap.h"

int check_digit(int argc, char **argv)
{
    int i;
    int k;

    k = 0;
    while (++k < argc)
    {
        if (argv[k][0] != '-' && argv[k][0] != '+' && !ft_isdigit(argv[k][0]))
            return 0;
        i = 1;
        while (argv[k][i])
        {
            if (!ft_isdigit(argv[k][i]))
                return 0;
            i++;
        }
    }
    return 1;
}

int check_repeted(int argc, char **argv)
{
    int k;
    int i;

    k = 0;
    while (++k < argc - 1)
    {
        i = k;
        while (++i < argc)
            if (ft_atoi(argv[k]) == ft_atoi(argv[i]))
                return 0;
    }
    return 1;
}

int check_interger_limits(int argc, char **argv)
{
    int k;
    int i;

    k = 0;
    i = 0;
    while (++k < argc)
    {
        if ((argv[k][i] == '+' && (ft_atoi(&argv[k][i]) < 0)) 
            || (argv[k][i] == '-' && (ft_atoi(&argv[k][i]) > 0)))
            return 0;
        else if (ft_isdigit(argv[k][i]) && (ft_atoi(&argv[k][i]) < 0))
            return 0;
    }
    return 1;
}

int check_args(int argc, char **argv)
{
    int k;
	int i;
	char **ptr;
	
    i = 1;
	k = 0;
    if (argc <= 1)
		return 0;
	if (argc == 2)
	{
		ptr = ft_split(argv[1], ' ');
		while (ptr[k])
			argv[i++] = ptr[k++];
		argc = i;
	}
	if (!check_digit(argc, argv) || !check_repeted(argc, argv) || !check_interger_limits(argc, argv))
	{
		// ERROR should be returned to stder not stdin
		printf("ERROR");
		return 0;
	}
    return argc;
}
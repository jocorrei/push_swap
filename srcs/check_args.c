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
    size_t len;

    k = 0;
    while (++k < argc -1)
    {
        i = k;
        while (++i < argc)
        {
            len = ft_strlen(argv[k]);
            if (len < ft_strlen(argv[i]))
                len = ft_strlen(argv[i]);
            if (!ft_strncmp(argv[k], argv[i], len))
                return 0;
        }
    }
    return 1;
}
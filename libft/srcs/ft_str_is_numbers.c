# include "../includes/libft.h"

int ft_str_is_numbers(const char *str)
{
    while (str)
    {
        if ((ft_isdigit(*str)) || (*str == ' '))
        {
            str++;
            if (*str == '\0')
                return 1;           
        }
        else
            return 0;
    }
    return 1;
}
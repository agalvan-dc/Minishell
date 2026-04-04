
#include "../libft.h"

int ft_atoi(const char *str)
{
    int sum;
    int i;
    int sign;

    i = 0;
    sum = 0;
    sign = 1;
    while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while(str[i] >= '0' && str[i] <= '9')
    {
        sum = sum * 10 + (str[i] - '0');
        i++;
    }
    return (sum * sign);
}

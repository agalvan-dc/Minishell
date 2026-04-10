#include "../../minishell.h"

int     ft_variable_detection(char *line, int index)
{
    if (line[index] == '$')
        return (index);
    index++;
    while (line[index] && !(is_var_delimiter(line, index)))
        index++;
    return (index - 1);
}

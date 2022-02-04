#include "./gnl/get_next_line.h"
#include "./so_long.h"
#include <stdio.h>

int is_valid_argv(int argc, char **argv)
{
    if (argc != 2)
    {
        return (FALSE);
    }
    if (ft_strcmp(&argv[1][ft_strlen(argv[1]) - 4], ".ber") != 0)
    {
        return (FALSE);
    }
    return (TRUE);
}
int main(int argc, char **argv)
{
    if (is_valid_argv(argc, argv) == FALSE)
    {
        printf("[error] invalid main arguements.\n");
    }
    else
        printf("valid\n");
    return (0);
}
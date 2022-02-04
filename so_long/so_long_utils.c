#include "so_long.h"

int             ft_strcmp(const char *s1, const char *s2)
{
    int          index;
    unsigned char   *cp1;
    unsigned char   *cp2;

    cp1 = (unsigned char*)s1;
    cp2 = (unsigned char*)s2;
    index = 0;
    while (cp1[index] != '\0')
    {
        if (cp1[index] != cp2[index])
        {
                return (cp1[index] - cp2[index]);
        }
        index++;
    }
    if (cp1[index] == '\0')
    {
        return (cp1[index] - cp2[index]);
    }
    return (0);
}
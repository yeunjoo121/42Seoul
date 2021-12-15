#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

/*
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	sindex1;
	size_t	sindex2;
	size_t	index;
	size_t	strindex;
	char	*str;

	sindex1 = ft_strlen(s1);
	sindex2 = ft_strlen(s2);
	index = 0;
	strindex = 0;
	if (!(str = (char*)malloc(sizeof(char) * (sindex1 + sindex2 + 1))))
		return (NULL);
	while (index < sindex1)
		str[strindex++] = s1[index++];
	index = 0;
	while (index < sindex2)
		str[strindex++] = s2[index++];
	str[strindex] = '\0';
	return (str);
}*/

void ft_gnl_test(int fd)
{
    char    *middle;
    while (read(fd, middle, BUFFER_SIZE) > 0)
    {
        printf("%s", middle);
    }
    return ;
}

int main(void)
{
    int     fd;
    fd = open("test.txt", O_RDONLY);
    ft_gnl_test(fd);
    return 0;
}
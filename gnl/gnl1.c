#include "get_next_line.h"

size_t		ft_strlen(const char *str)
{
	size_t		index;

	index = 0;
	while (str[index] != '\0')
	{
		index++;
	}
	return (index);
}

char			*ft_strdup(const char *s1)
{
	char		*p;
	size_t		slen;
	size_t		index;

	index = 0;
	slen = ft_strlen(s1);
	if (!(p = (char*)malloc(sizeof(char) * (slen + 1))))
	{
		return (0);
	}
	while (index < slen)
	{
		p[index] = s1[index];
		index++;
	}
	p[index] = '\0';
	return (p);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	sindex1;
	size_t	sindex2;
	size_t	index;
	size_t	strindex;
	char	*str;
	if (!(s1) && !(s2))
		return NULL;
	else if (!(s1) || !(s2))
		return (!(s1) ? (ft_strdup(s2)) : ft_strdup(s1));
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
}

char		*ft_strndup(const char *s, int len)
{
	char	*res;
	int		index;

	res = NULL;
	index = 0;
	if (len == 0)
		return (NULL);
	if (!(res = (char*)malloc(sizeof(char) * (len + 1))))
	{
		return (NULL);
	}
	while (index < len)
	{
		res[index] = s[index];
		index++;
	}
	res[index] = '\0';
	return (res);
}

int		ft_strchr(const char *s, int c)
{
	size_t	index;

	index = 0;
	while (s[index] != '\0')
	{
		if ((unsigned char)c == s[index])
		{
			return index;
		}
		index++;
	}
	if ((unsigned char)c == s[index])
	{
		return index;
	}
	return (-1);
}

int     is_newline(char *str)
{
    int     index;

    index = 0;
    while (str[index] != '\0')
    {
        if (str[index] == '\n')
        {
            return (index);
        }
        index++;
    }
    return (-1);
}

int     make_line(char *backup, int cut, char **line)
{
    char    *temp;

    backup[cut] = '\0';
    *line = ft_strdup(backup);
    temp = ft_strdup(&backup[cut + 1]);
    free(backup);
	backup = 0;
    backup = temp;
    return (1);
}

int     get_next_line(int fd, char **line)
{
    static char *backup[OPEN_MAX];
    char    buf[BUFFER_SIZE + 1];
	int		cut;
	int		readindex;

    while ((readindex = read(fd, buf, BUFFER_SIZE)) > 0)
    {
        buf[readindex] = '\0';
        backup[fd] = ft_strjoin(backup[fd], buf);
        cut = is_newline(backup[fd]);
        if (cut >= 0)
        {
            return (make_line(backup[fd], cut, line));
        }
	}
    if (readindex == 0)
	{
		while (1)
		{
			cut = is_newline(backup[fd]);
			if (cut >= 0)
			{
				return (make_line(backup[fd], cut, line));
			}
			if (cut == -1)
			{
				*line = backup[fd];
				free(backup[fd]);
				return (0);
			}
		}
	}
	return (-1);
}

int		main(void)
{
	int fd;
	char *line = 0;
	int i;

	if (!(fd = open("test.txt", O_RDONLY)))
	{
		return 0;
	}
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("real str : %s\n", line);
		free(line);
	}
	printf("real str : %s\n", line);
	free(line);
	close(fd);
	return 0;
}
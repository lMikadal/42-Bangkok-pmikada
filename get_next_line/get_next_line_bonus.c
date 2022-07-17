#include "get_next_line_bonus.h"

char	*ft_cut(t_buff *b)
{
	char	*m;
	int		diff;
	int		len_nl;
	int		i;

	len_nl = ft_strlen_nl(b->temp_buff);
	if (len_nl == -1)
		len_nl = ft_strlen(b->temp_buff);
	diff = ft_strlen(b->temp_buff) - len_nl;
	m = (char *)malloc((diff * sizeof(char)) + 1);
	if (m == NULL)
		return (NULL);
	i = 0;
	while (i < diff)
		m[i++] = b->temp_buff[len_nl++];
	m[i] = '\0';
	free(b->temp_buff);
	if (m[0] == '\0')
	{
		free(m);
		return (NULL);
	}
	return (m);
}

void	ft_re_buff(char **r_buff, t_buff *b)
{
	*r_buff = ft_strdup(b->temp_buff);
	b->temp_buff = ft_cut(b);
}

char	*ft_get_next_line(t_buff *b)
{
	char			*r_buff;
	int				r_read;

	r_read = 1;
	r_buff = NULL;
	b->buff = (char *)malloc((BUFFER_SIZE * sizeof(char)) + 1);
	if (b->buff == NULL)
		return (NULL);
	while (r_read > 0)
	{
		r_read = read(fd, b->buff, BUFFER_SIZE);
		b->buff[r_read] = '\0';
		if (r_read == 0)
			break ;
		b->temp_buff = ft_strjoin(b->temp_buff, b->buff);
		if (ft_strlen_nl(b->temp_buff) != -1)
			break ;
	}
	if (b->temp_buff != NULL)
		ft_re_buff(&r_buff, b);
	free(b->buff);
	return (r_buff);
}

char	*get_next_line(int fd)
{
	static t_buff	b;
	t_buff			temp;
	t_buff			next_b;

	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, NULL, 0) == -1)
		return (NULL);
	if (b != NULL)
	{
		temp = b;
		while (temp != NULL)
		{
			if (temp.fd = fd)
				return (ft_get_next_line(&temp));
			temp = temp.next;
		}
		while (b != NULL)
		{
			if (b.next == NULL)
				b.next == next_b;
			b = b.next;
		}
		return (ft_get_next_line(&b));
	}
	else
	{
		b.fd = fd;
		return (ft_getnext_line(&b));
	}
}
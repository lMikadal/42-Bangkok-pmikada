#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_buff
{
	int				fd;
	char			*buff;
	char			*temp_buff;
	struct s_buff	*next;
}	t_buff;

int		ft_strlen(char *s);
int		ft_strlen_nl(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s);
char	*get_next_line(int fd);

#endif

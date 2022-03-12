#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

int		ft_strrchr(char *str, int c);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_cutstr(char **str, int pos);
char	*get_next_line(int fd);
char	*ft_aret(char **c_line);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
char	*ft_strdup(char *s1);
char	*ft_strchr(char *s, int c);
char	*ft_fixnorm(char *c_line, char *buf, int ret);
#endif
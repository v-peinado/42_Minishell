/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 13:49:27 by vpeinado          #+#    #+#             */
/*   Updated: 2024/04/26 20:12:24 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list		*ft_lstnew(void *content);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstiter(t_list *lst, void (*f)(void *));
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		*ft_memmove(void *str1, const void *str2, size_t n);
void		ft_bzero(void *str, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memset(void *str, int c, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_calloc(size_t nitems, size_t size);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putstr_fd(char *s, int fd);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_free_strs(char **strs);
int			ft_lstsize(t_list *lst);
int			ft_memcmp(const void *str1, const void *str2, size_t n);
int			ft_isalnum(int argument);
int			ft_isalpha(int argument);
int			ft_isascii(int argument);
int			ft_isdigit(int argument);
int			ft_isdigit_string(char *str);
int			ft_isprint(int argument);
int			ft_tolower(int ch);
int			ft_toupper(int ch);
int			ft_strncmp(const char *str1, const char *str2, size_t n);
int			ft_atoi(const char *str);
int    		ft_arraylen(char **array);
char		*ft_strchr(const char *str, int c);
char		*ft_strrchr(const char *str, int c);
char		*ft_strnstr(const char	*big, const char *little, size_t len);
char		*ft_strdup(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		**ft_arraypush(char **strs, char *str);
char		*ft_itoa(int n);
size_t		ft_strlen(const char *str);
size_t		ft_strlcpy(char *dst, const char *src, size_t dst_size);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
void		ft_free_matrix(void **matrix);

//gnl
char	*get_next_line(int fd);
char	*ft_read_to_stash(int fd, char *stash);
char	*ft_get_line(char *stash);
char	*ft_new_stash(char *stash);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_strchr2(const char *s, int c);

//printf
int		ft_printf(const char *format, ...);
void	ft_print_char(char ch, int *len);
void	ft_print_int(int n, int *len);
void	ft_print_str(char *str, int *len);
void	ft_print_uint(unsigned int n, int *len);
void	ft_print_ptr(void *ptr, int *len);
void	ft_print_hex(unsigned int n, int *len, char ch);

#endif
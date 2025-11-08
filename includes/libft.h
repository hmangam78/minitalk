/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@42student.42malaga.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 18:24:02 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/06/06 18:24:02 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdint.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_strlen(const char *s);
void		*ft_memset(void *s, int c, size_t n);
int			ft_toupper(int c);
int			ft_tolower(int c);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dest_str, const void *src_str, size_t n);
void		*ft_memmove(void *dest_str, const void *src_str, size_t n);
size_t		ft_strlcpy(char	*dst, const char *src, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
char		*ft_strchr(const char *string, int c);
char		*ft_strrchr(const char *string, int c);
int			ft_strncmp(const char *string1, const char *string2, size_t count);
int			ft_atoi(const char *string);
void		*ft_memchr(const void *buf, int c, size_t count);
int			ft_memcmp(const void *buf1, const void *buf2, size_t count);
char		*ft_strnstr(const char *string1, const char *string2, size_t len);
char		*ft_strdup(const char *string);
void		*ft_calloc(size_t num, size_t size);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
int			ft_pr_hex(unsigned int nb, const char *base);
int			ft_pr_unsigned(unsigned int nb);
int			ft_printf(char const *str, ...);
int			ft_putchar(int c);
int			ft_putnbr(long long int nb);
int			ft_putchar(int c);
int			ft_putnbr(long long int nb);
int			ft_putptr(unsigned long long ptr);
int			ft_putstr(char *s);
char		*ft_itobin(int n);
int			ft_bintoi(const char *string);
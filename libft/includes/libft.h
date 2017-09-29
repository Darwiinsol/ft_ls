/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:25:29 by apissier          #+#    #+#             */
/*   Updated: 2017/09/25 15:11:28 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <string.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>

# define BUFF_SIZE 10

typedef struct		s_fd
{
	int				n_fd;
	char			*str;
	struct s_fd		*next;
}					t_fd;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_flags
{
	int				width;
	int				precision;
	int				lenght;
	int				sharp;
	int				zero;
	int				blank;
	int				minus;
	int				plus;
	int				letter;
	int				h;
	int				l;
	int				j;
	int				z;
}					t_flags;

int					ft_atoi(const char *nptr);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_isblank(int c);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putnbr(int n);
void				ft_putstr(const char *s);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strdup(const char *s);
void				ft_striter(char *s, void (*f)(char *));
size_t				ft_strlen(const char *s);
int         		ft_intlen(long long nbr);
char				*ft_strncat(char *dest, const char *src, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strnstr(const char *a, const char *b, size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *mdf, const char *a);
size_t          	ft_strcspn(const char *s1, char s2);
int					ft_tolower(int c);
int					ft_toupper(int c);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putnstr(char const *s, size_t n);
void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s1, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strnjoin(int n, ...);
char				*ft_strjoinfree(char *s1, char *s2);
char				*ft_strjoinffree(char *s1, char *s2);
char				*ft_strjoinmulti(char const *s1, char const *s2, char const *s3, char const *s4);
char				*ft_itoa(int n);
char				**ft_strsplit(char const *s, char c);
char				*ft_strtrim(char const *s);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_swap(int *a, int *b);
int					ft_isspace(int c);
char				*ft_strrev(char *str);
void				*ft_realloc(void *ptr, size_t cur_size, size_t new_size);
void				ft_write_null(void);
int					ft_sort_ascii(char *a, char *b);
int					ft_sort_r_ascii(char *a, char*b);
void                ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void                ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void                ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void                ft_lstadd(t_list **alst, t_list *new);
t_list              *ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list              *ft_lstnew(void const *content, size_t content_size);
void				ft_lstaddend(t_list **alst, t_list *new);

int					ft_printf(const char *format, ...);
int					ft_printf_char(va_list ap, t_flags b, char i);
int					ft_printf_hexa(va_list ap, t_flags b, char i);
int					ft_printf_octal(va_list ap, t_flags b, char i);
int					ft_printf_unsigned(va_list ap, t_flags b, char i);
int					ft_printf_percent(t_flags b);
int					ft_printf_pointer(va_list ap, t_flags b);
int					ft_printf_string(va_list ap, t_flags b, char i);
int					ft_check_letter(va_list ap, char i, t_flags b);
t_flags				ft_check_modifier(char i, char j, t_flags b);
t_flags				ft_check_flags(char i, t_flags b);
intmax_t			ft_length_modifier_signed(va_list ap, t_flags b);
uintmax_t			ft_lenght_modifier_unsigned(va_list ap, t_flags b);
int					ft_printf_di(va_list ap, char i, t_flags b);
int					ft_modifier(char i);
int					ft_flags(char i);
char				*ft_unicode(wchar_t wc);
char				*ft_itoa_intmax(intmax_t n);
char				*ft_check_if_flags_int(t_flags b, char *str);
char				*ft_check_if_flags_str(t_flags b, char *str);
char				*ft_join_flags_int(t_flags b, char *str);
char				*ft_size_prec_int(t_flags b, char *str);
char				*ft_size_prec_str(t_flags b, char *str);
char				*ft_size_prec_uni(t_flags b, char *str);
char				*ft_size_lenght_int(t_flags b, char *str);
char				*ft_size_lenght_str(t_flags b, char *str);
char				*ft_join_lenght_int(t_flags b, char *tmp, char *str);
char				*ftf_join_flags(char *str, t_flags b, char *tmp);
char				*ft_is_plus(t_flags b, char *str, size_t negative);
char				*ft_is_blank(t_flags b, char *str, size_t negative);
char				*ft_strchar(char c, size_t size);
int					ft_free_return(char **str);
int					get_next_line(const int fd, char **line);

#endif

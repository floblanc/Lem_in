/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 13:37:06 by maginist          #+#    #+#             */
/*   Updated: 2019/04/04 12:06:01 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPRINTF_H
# define LIBPRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# define BUFF_SIZE 32

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_data
{
	int				diez;
	int				space;
	int				plus;
	int				moins;
	int				zero;
	int				tdc;
	int				pt;
	int				preci;
	int				nb_flgs;
	int				size_aff;
	int				symbol_pos;
	char			flgs;
	char			symbol;
	char			*s;
}					t_data;

typedef	struct		s_fct
{
	char			symbol;
	void			(*f)(t_data *data, va_list ap);
}					t_fct;

char				*lltoa(long long int n);
char				*ltoa(long int n);
char				*stoa(short int n);
char				*ulltoa(unsigned long long int n);
char				*ultoa(unsigned long int n);
char				*utoa(unsigned int n);
char				*ustoa(unsigned short int n);
char				*bulltoa(unsigned long long n, char *base);
char				*bultoa(unsigned long n, char *base);
char				*butoa(unsigned int n, char *base);
char				*bustoa(unsigned short n, char *base);
char				*buctoa(unsigned char n, char *base);
char				*ftoa(double n);
char				*fltoa(long double n);
char				*ctoa(char n);
char				*uctoa(unsigned char n);
int					ft_printf(const char *format, ...);
int					analyse(char *s, int *i, int j, va_list ap);
int					is_valide(char *s, int i);
void				gest_c(t_data *data, va_list ap);
void				gest_s(t_data *data, va_list ap);
void				gest_p(t_data *data, va_list ap);
void				gest_di(t_data *data, va_list ap);
void				gest_o(t_data *data, va_list ap);
void				gest_u(t_data *data, va_list ap);
void				gest_x(t_data *data, va_list ap);
void				gest_majx(t_data *data, va_list ap);
void				gest_f(t_data *data, va_list ap);
void				gest_e(t_data *data, va_list ap);
void				gest_g(t_data *data, va_list ap);
void				gest_b(t_data *data, va_list ap);
void				gest_r(t_data *data, va_list ap);
void				gest_pc(t_data *data, va_list ap);

void				init_struct(t_data *data, char *s, int pos_sym);
void				add_pre_flgs(t_data *data, char *s, int *i, int j);
int					stock_digit(char *s, int *i, int j, va_list ap);
void				stock_flgs(t_data *data, char *s, int *i, int j);
void				redirection(t_data *data, va_list ap);
void				printdc(int tdc);
char				*newstart_cleanbegin(char *num, int size, t_data *data);
char				*fillbegin(char *num, t_data *data);
void				gest_allnum(char *num, t_data *data);
void				printpreci(int size);
unsigned int		ft_abs(int nb);
int					get_next_line(const int fd, char **line);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s);
char				*ft_strndup(const char *s, size_t n);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char*s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,
		size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
long				ft_atol(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char(*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_tabdel(char **tab);
void				ft_puttab(char **tab);
size_t				ft_tab3size(void ***tab);
int					ft_strsearch(char *src, char c);

#endif

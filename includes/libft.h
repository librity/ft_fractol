/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 21:58:19 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/15 20:48:43 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <sys/resource.h>
# include <unistd.h>
# include <stdarg.h>

/******************************************************************************\
 * BOOLEANS
\******************************************************************************/

bool				unless(bool condition);

/******************************************************************************\
 * MATH
\******************************************************************************/

double				ft_abs_d(double number);
float				ft_abs_f(float number);
int					ft_abs_i(int number);
int					ft_abs(int number);

double				ft_min_d(double x, double y);
double				ft_max_d(double x, double y);
double				ft_clamp_d(double x, double min, double max);

void				ft_swap(int *a, int *b);
void				ft_swap_i(int *a, int *b);

void				ft_div_mod(int a, int b, int *div, int *mod);
void				ft_div_mod_i(int a, int b, int *div, int *mod);

int					ft_sqrt(int number);
int					ft_sqrt_i(int number);
int					ft_pow(int number, int power);
int					ft_pow_i(int number, int power);
int					ft_fibonacci(int index);
int					ft_factorial(int number);

typedef struct s_map_d
{
	double	mapped;
	double	start1;
	double	stop1;
	double	start2;
	double	stop2;
}					t_map_d;

double				ft_map_d(t_map_d args);
double				ft_map_clamped_d(t_map_d args);

double				ft_lerp_d(double from, double to, double x);
double				ft_lerp_wsteps_d(double from, double to, double steps,
						double x);

/******************************************************************************\
 * MEMORY
\******************************************************************************/

void				*ft_salloc(size_t size);
void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);

/******************************************************************************\
 * CHARS
\******************************************************************************/

bool				ft_isdigit(int c);
bool				ft_is_whitespace(char character);
bool				ft_is_plus_or_minus(char character);
bool				ft_is_decimal_char(char character);
bool				ft_isupper(int c);
bool				ft_islower(int c);
bool				ft_isalpha(int c);
bool				ft_isalnum(int c);
bool				ft_isascii(int c);
bool				ft_isprint(int c);

int					ft_toupper(int c);
int					ft_tolower(int c);

/******************************************************************************\
 * STRINGS
\******************************************************************************/

size_t				ft_strlen(const char *s);
char				*ft_strcpy(char *dest, char *src);
void				ft_strdel(char **delete_me);
char				*ft_strnchr(const char *s, int c, unsigned int limit);

size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *haystack,
						const char *needle,
						size_t len);
int					ft_strncmp(const char *s1, const char *s2, size_t n);

int					ft_atoi(const char *number_pointer);
unsigned int		ft_atoui(const char *number_pointer);
unsigned int		ft_atoui_strict(const char *number_pointer);

void				*ft_calloc(size_t nmemb, size_t size);
char				*ft_strdup(const char *s);

char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoin_and_free(char *free_me,
						char const *dont_free_me);
char				*ft_strjoin_and_free_free(char *free_me, char *free_me_too);
char				*ft_strjoin_and_del(char *delete_me,
						char const *dont_delete_me);
char				*ft_strjoin_and_del_del(char *delete_me,
						char *delete_me_too);

char				*ft_itoa(int n);
unsigned int		ft_i_to_buffer(int n, char *buffer);

char				*ft_ltoa(long n);

char				*ft_ftoa(float n);
char				*ft_precise_ftoa(float n, int precision);

char				*ft_precise_dtoa(double n, int precision);
char				*ft_dtoa(double n);

char				*ft_ldtoa(long double n);
char				*ft_precise_ldtoa(long double n, int precision);

/******************************************************************************\
 * PRINT STRINGS
\******************************************************************************/

void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

void				ft_putchar(char c);
void				ft_putstr(char *s);
void				ft_putstr_up_to(char *s, size_t up_to);
void				ft_putendl(char *s);

/******************************************************************************\
 * PRINT NUMBERS
\******************************************************************************/

# define DECIMAL_BASE "0123456789"
# define DOWNCASE_HEX_BASE "0123456789abcdef"
# define UPPERCASE_HEX_BASE "0123456789ABCDEF"

bool				ft_is_valid_base(const char *base,
						const size_t base_length);
void				ft_aux_handle_minus_sign_li(long int *number_pointer);

void				ft_putnbr(int n);
void				ft_putnbr_i(int number);
void				ft_putnbr_ui(unsigned int number);
void				ft_putnbr_ul(unsigned long number);
void				ft_putnbr_li(long int number);

void				ft_putnbr_base(int number, char *base);
void				ft_putnbr_base_i(int number, char *base);
void				ft_putnbr_base_ui(unsigned int number, const char *base);
void				ft_putnbr_base_ul(unsigned long number, const char *base);
void				ft_putnbr_base_li(long int number, const char *base);

void				ft_puthex_uppercase(unsigned int number);
void				ft_puthex_downcase(unsigned int number);

unsigned int		ft_count_digits(int number);
unsigned int		ft_count_digits_i(int number);
unsigned int		ft_count_digits_i(int number);
unsigned int		ft_count_digits_ui(unsigned int number);
unsigned int		ft_count_digits_ul(unsigned long number);

unsigned int		ft_count_digits_hex_ui(unsigned int number);
unsigned int		ft_count_digits_hex_ul(unsigned long number);

unsigned int		ft_count_chars_i(int number);

char				*ft_skip_digits(char *digits);
char				*ft_skip_number(char *digits);

/******************************************************************************\
 * LINKED_LISTS
\******************************************************************************/

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst,
						void *(*f)(void *),
						void (*del)(void *));

/******************************************************************************\
 * FT_GET_NEXT_LINE
\******************************************************************************/

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif
# define MAX_FILE_DESCRIPTOR RLIMIT_NOFILE

# define GNL_FOUND_LINEBREAK 1
# define GNL_FOUND_EOF 0
# define GNL_ERROR -1

int					ft_get_next_line(int fd, char **line);

/******************************************************************************\
 * FT_PRINTF
\******************************************************************************/

# ifndef ARG_MAX
#  define ARG_MAX 131072
# endif

# define NULL_STRING "(null)"

typedef struct s_printf
{
	const char		*format;
	va_list			elements;
	int				chars_printed;
	unsigned int	conversion_position;
	char			conversion;
}					t_printf;

typedef struct s_parse_flags
{
	char			parsed_flags[ARG_MAX];
	char			*flags;
	bool			has_wildcards;
	bool			is_left_padded_with_zeros;
	bool			is_left_justified;
	char			left_padder;
	bool			has_minimum_width;
	int				minimum_width;
	bool			has_precision;
	int				precision;
}					t_parse_flags;

typedef struct s_parse_wildcards
{
	char			*found_wildcards;
	unsigned int	conversion_position;
	int				wildcard;
	size_t			parser;
}					t_parse_wildcards;

typedef struct s_handle_percent
{
	unsigned char	print_me;
	int				char_count;
	t_parse_flags	flag_control;
}					t_handle_percent;

typedef struct s_handle_c
{
	unsigned char	print_me;
	int				char_count;
	t_parse_flags	flag_control;
}					t_handle_c;

typedef struct s_handle_s
{
	char			*print_me;
	size_t			length;
	size_t			precision_length;
	bool			is_null;
	t_parse_flags	flag_control;
}					t_handle_s;

typedef struct s_handle_int
{
	long int		print_me;
	int				digit_count;
	int				char_count;
	bool			is_negative;
	bool			is_zero_with_zero_precision;
	t_parse_flags	flag_control;
}					t_handle_int;

typedef struct s_handle_u
{
	unsigned int	print_me;
	int				digit_count;
	bool			is_zero_with_zero_precision;
	t_parse_flags	flag_control;
}					t_handle_u;

typedef struct s_handle_p
{
	unsigned long	print_me;
	int				digit_count;
	bool			is_zero_with_zero_precision;
	t_parse_flags	flag_control;
}					t_handle_p;

typedef struct s_handle_hex
{
	unsigned int	print_me;
	int				digit_count;
	bool			is_uppercase;
	bool			is_zero_with_zero_precision;
	t_parse_flags	flag_control;
}					t_handle_hex;

int					ft_printf(const char *format, ...);
void				ft_vprintf(t_printf *print_control);

void				initialize_print_control(t_printf *print_control,
						const char *format);
void				initialize_flag_control(t_printf *print_control,
						t_parse_flags *flag_control);
void				initialize_wildcard_control(t_printf *print_control,
						t_parse_flags *flag_control,
						t_parse_wildcards *wildcard_control);

bool				handled_no_conversion(t_printf *print_control);
bool				handled_percent(t_printf *print_control);
bool				handled_s(t_printf *print_control);
bool				handled_c(t_printf *print_control);
bool				handled_int(t_printf *print_control);
bool				handled_u(t_printf *print_control);
bool				handled_p(t_printf *print_control);
bool				handled_hex(t_printf *print_control);

void				parse_flags(t_printf *print_control,
						t_parse_flags *control);
void				parse_wildcars(t_printf *print_control,
						t_parse_flags *flag_control);

void				printf_percent(t_printf *print_control,
						t_handle_percent *control,
						t_parse_flags *flag_control);
void				printf_c(t_printf *print_control,
						t_handle_c *control,
						t_parse_flags *flag_control);
void				printf_s(t_printf *print_control,
						t_handle_s *control,
						t_parse_flags *flag_control);
void				printf_int(t_printf *print_control,
						t_handle_int *control,
						t_parse_flags *flag_control);
void				printf_u(t_printf *print_control,
						t_handle_u *control,
						t_parse_flags *flag_control);
void				printf_p(t_printf *print_control,
						t_handle_p *control,
						t_parse_flags *flag_control);
void				printf_hex(t_printf *print_control,
						t_handle_hex *control,
						t_parse_flags *flag_control);

#endif

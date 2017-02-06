/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprovorn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 16:48:04 by dprovorn          #+#    #+#             */
/*   Updated: 2016/12/27 16:38:59 by ebitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef HEADER_H
#	define HEADER_H
#include <unistd.h>
#include <stdint.h>
#include <wchar.h>
#include <stdarg.h>
#include <stdlib.h>
#include <locale.h>
#include <stdio.h>

int			g_cont;
int			g_jump;
int			g_small;
int			g_flag[14];

typedef union			u_u
{
	long long			ll;
	unsigned long long	ull;
	long int			lin;
	long unsigned int	ulin;
	int					in;
	unsigned int		uin;
	short				sh;
	unsigned short		ush;
	char				chr;
	unsigned char		uchr;
	size_t				szt;
	intmax_t			imaxt;
	uintmax_t			uimaxt;
	wchar_t				wchr;
}						t_un;

void					init2(void);
void					init(int *length, short *to_free, char **str,
	wchar_t **wstr);
void					ft_putchar(char c);
void					ft_putstr(char *s);
int						ft_printf(const char *s, ...);
void					get_data_type_2(long long *temp, t_un *uni, short spec);
long long				get_data_type(t_un *uni, short spec);
short					set_pointer(void);
int						get_length_hexadecimal(unsigned long long uns_temp,
	short spec);
int						get_length_octal(unsigned long long uns_temp,
	short spec);
int						get_length_2(long long temp, unsigned long long
	uns_temp, short spec);
int						get_length(t_un *uni, short spec);
void					ft_negate(long long *nr, unsigned long long *uns_nr,
	short spec);
void					ft_print_hexadecimal(unsigned long long uns_nr,
	short spec);
void					ft_print_octal(unsigned long long uns_nr,
	short spec);
void					select_ft_put(unsigned long long uns_nr,
	short spec);
void					print_diez(void);
void					check_f_array_2(short spec);
void					check_f_array_3();
void					check_diez(short spec);
void					check_flag_array(long long nr, short spec);
short					modify_dot();
void					modify_plus();
void					modify_zero();
short					modify_percent(const char *s);
int						check_char(const char *s);
short					check_h_spec_2(const char *s);
short					check_h_spec_3(const char *s);
short					check_h_spec_4(const char *s);
short					check_h_spec_5(const char *s);
short					check_hx(const char *s);
short					check_h_spec_6(const char *s);
short					check_h_spec_7(const char *s);
short					check_h_spec(const char *s);
short					check_l_spec_2(const char *s);
short					check_lc(const char *s);
short					check_l_spec_3(const char *s);
short					check_l_spec_4(const char *s);
short					check_l_spec_5(const char *s);
short					check_l_spec(const char *s);
short					check_z_spec_2(const char *s);
short					check_z_spec(const char *s);
short					check_j_spec_2(const char *s);
short					check_j_spec(const char *s);
short					check_o(const char *s);
short					check_ox(const char *s);
short					check_single(const char *s);
short					is_spec(const char *s);
long long				get_from_list(va_list *my_list, short spec);
int						ft_wlen(wchar_t wchr);
void					modify_wlen(wchar_t *wstr);
void					modify_str_length(int *length, wchar_t *wstr,
	short spec);
void					ft_print_wstr_minus(wchar_t *wstr, int length);
void					ft_print_str_minus(char *str, int length);
void					ft_print_wstr_width(wchar_t *wstr, int length);
void					ft_print_str_width(char *str, int length);
void					print_str_2(wchar_t *wstr, char *str, int length,
	short spec);
void					print_str(va_list *mylist, short spec);
void					print_nbr_2(short spec, int *abs_length, int length,
	long long ll);
void					print_nbr(va_list *mylist, short spec);
void					skip(const char *s);
int						skip_space(const char *s, va_list *mylist);
void					print_letter(const char *s, va_list *mylist);
void					ft_hexa_ui(unsigned n);
void					ft_hexa_ul(unsigned long long n);
void					ft_hexa(unsigned long long n);
void					ft_binar(unsigned long long n);
void					ft_octal_ui(unsigned n);
void					ft_octal_ul(unsigned long long n);
int						g_hex_ui_l(unsigned n);
int						g_hex_ul_l(unsigned long long n);
int						g_o_ui_l(unsigned n);
int						g_o_ul_l(unsigned long long n);
int						ft_nbr_bits(unsigned int nbr);
void					cond2(unsigned int ch, int *i, char *buff);
void					ft_putwchart(int wchar, int *len, char *buff);
void					ft_putchar_fd(int c, int fd);
void					ft_putwstr(wchar_t *wstr);
int						ft_wstrlen(wchar_t *wstr);
char					*ft_strdup(const char *src);
void					reset_bratan(void);
void					delete_sign();
void					reset_flags();
size_t					ft_strlen(const char *str);
char					*ft_strchr(const char *s, int c);
void					ft_putchar(char c);
void					ft_putstr(char *s);
int						ft_atoi(const char *str);
void					ft_putnbr(unsigned long long nb);
int						ft_nbr_bits(unsigned int nbr);
void					cond2(unsigned int ch, int *i, char *buff);
void					ft_putwchart(int wchar, int *len, char *buff);
void					ft_print_hex_ui(unsigned n);
void					ft_print_hex_ul(unsigned long long n);
int						get_length_hex_ui(unsigned n);
int						get_length_hex_ul(unsigned long long n);
void					ft_print_oct_ui(unsigned n);
void					ft_print_oct_ul(unsigned long long n);
int						get_length_oct_ui(unsigned n);
int						get_length_oct_ul(unsigned long long n);
#	endif

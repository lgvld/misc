/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 17:52:07 by lgavalda          #+#    #+#             */
/*   Updated: 2019/07/19 01:10:28 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_print_alphabet(void);
void	ft_print_reverse_alphabet(void);
void	ft_is_negative(int n);
void	ft_print_numbers(void);

void	ft_putnbr(int nb);

void	ft_print_comb(void);
void	ft_print_comb2(void);
void	ft_print_combn(int n);

//

void	ft_putstr(char *str);
int		ft_strlen(char *str);
void	ft_rev_int_tab(int *tab, int size);
void	ft_sort_int_tab(int *tab, int size);

// void	ft_putchar(char c)
// {
// 	write(1, &c, 1);
// }

// void	ft_putstr(char *str)
// {
// 	while (*str)
// 		write(1, str++, 1);
// }

// void	ft_putnbr(int nb)
// {
// 	char c;

// 	if (nb == -2147483648)
// 	{
// 		write(1, "-2147483648", 11);
// 		return ;
// 	}
// 	if (nb < 0)
// 	{
// 		write(1, "-", 1);
// 		nb *= -1;
// 	}
// 	if (nb / 10 != 0)
// 	{
// 		ft_putnbr(nb / 10);
// 	}
// 	c = '0' + nb % 10;
// 	write(1, &c, 1);
// }

// void	print_tab(int *tab, int size)
// {
// 	int i = 0;
// 	while (i < size)
// 	{
// 		ft_putnbr(tab[i]);
// 		ft_putchar('\n');
// 		i++;
// 	}
// }

char			*ft_strupcase(char *str);
char			*ft_strlowcase(char *str);
char			*ft_strcapitalize(char *str);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
void			ft_putstr_non_printable(char *str);
void			ft_print_memory(void *addr, unsigned int size);

//

char			*ft_strcpy(char *dest, char *src);
char			*ft_strcpy(char *dest, char *src);
char			*ft_strncpy(char *dest, char *src, unsigned int n);
int				ft_strcmp(char *s1, char *s2);
int				ft_strncmp(char *s1, char *s2, unsigned int n);
char			*ft_strcat(char *dest, char *src);
char			*ft_strncat(char *dest, char *src, unsigned int nb);
char			*ft_strstr(char *str, char *to_find);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

int	ft_str_is_alpha(char *str);
int	ft_str_is_numeric(char *str);
int	ft_str_is_lowercase(char *str);
int	ft_str_is_printable(char *str);

//

int		ft_atoi(char *str);
void	ft_putnbr_base(int nbr, char *base);

//

int	ft_iterative_factorial(int nb);
int	ft_recursive_factorial(int nb);
int	ft_iterative_power(int nb, int power);
int	ft_recurisve_power(int nb, int power);
int	ft_fibonacci(int index);
int	ft_sqrt(int nb);
int	ft_is_prime(int nb);
int	ft_find_next_prime(int nb);
int	ft_ten_queens_puzzle(void);

//

char	*ft_strdup(char *src);
int		*ft_range(int min, int max);
int		ft_ultimate_range(int **range, int min, int max);
char	*ft_strjoin(int size, char **strs, char *sep);
char	**ft_split(char *str, char *charset);

//

int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;

	// ft_split(argv[1], argv[2]);
	// printf("%s\n", ft_strjoin(argc - 2, argv + 2, argv[1]));

	// int	*tab;
	// int	ret = ft_ultimate_range(&tab, -1, 10);
	// printf("%d\n", ret);
	// printf("%d\n", tab[0]);

	// int	*tab = ft_range(4, 5);
	// printf("%d\n", tab[1]);
	// printf("%s\n", ft_strdup("123 123"));

	// printf("[%d]\n", ft_ten_queens_puzzle());

	// for (int i = 0 ; i < 10000000 ; i++)
		// printf("%d\n", ft_find_next_prime(i));
	// printf("%d\n", ft_find_next_prime(6));
	// printf("%d\n", ft_is_prime(2147483271));
	// printf("%d\n", ft_sqrt(2147483647));

	// printf("%d\n", ft_fibonacci(46));
	// printf("%d\n", ft_recurisve_power(12, 2));
	printf("%d\n", ft_iterative_power(-3, 9));
	// printf("%d\n", ft_recursive_factorial(-50));
	// printf("%d\n", ft_iterative_factorial(5));

	// ft_putnbr_base(42, "01");

	// printf("%d\n", ft_atoi("-123"));

	// char tab[] = {255, ' ', 128, 0};
	// char dest[100] = "d";
	// char src[100] = "asdfgsdr \bfgnb";
	// char str[] = "abababababab";
	// char tf[] = "aba ";

	// printf("[%u] %s", ft_strlcat(dest, src, 1), dest);
	// printf("[%lu] %s", strlcat(dest, src, 1), dest);

	// ft_putstr_non_printable(tab);

	// printf("%s\n", ft_strcapitalize(src));

	// printf("%d\n", ft_str_is_printable(dest));
	// printf("%d\n", ft_str_is_lowercase(dest));
	// printf("%d\n", ft_str_is_numeric(dest));
	// printf("%d\n", ft_str_is_alpha(dest));

	// printf("%s\n%s\n", ft_strstr(str, tf), strstr(str, tf));

	// printf("%s\n", ft_strncat(dest, src, 3));
	// printf("%s\n", strncat(dest, src, 3));

	// printf("%s\n", ft_strcat(dest, src));
	// printf("%s\n", strcat(dest, src));

	// printf("%s\n", s2);
	// ft_print_memory(s2, 500);
	// printf("(%d):(%d)\n", strncmp(dest, src, 0), ft_strncmp(dest, src, 0));
	// printf("(%d):(%d)\n", strncmp(dest, src, 1), ft_strncmp(dest, src, 1));
	// printf("(%d):(%d)\n", strncmp(dest, src, 2), ft_strncmp(dest, src, 2));
	// printf("(%d):(%d)\n", strncmp(dest, src, 10), ft_strncmp(dest, src, 10));

	// printf("%s\n", strcpy(dest, src));
	// printf("%s\n", ft_strcpy(dest, src));
	// printf("%s\n", strncpy(dest, src, 1));
	// printf("%s\n", ft_strncpy(dest, src, 1));

	// printf("%s\n", strcpy(s1, s2));
	// printf("%s\n", ft_strcpy(s1, s2));

	// char	*s1 = "abcd";
	// char	*s2 = "abc";
	// printf("%d\n", ft_strncmp(s1, s2, 3));
	// printf("%d\n", strncmp(s1, s2, 3));

	// char	str[] = "H123facile He";
	// char	str[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	// printf("%s\n", ft_strupcase(str));
	// printf("%s\n", ft_strlowcase(str));
	// printf("%s\n", ft_strcapitalize(str));

	// char *str = "Bonjour les aminches\0 123456789\n\n\nc est fou\ntout.ce qu on peut faire avec\n\n\n";
	// char	str[] = {'B', 'o', 'n', 'j', 'o', '\n', 'r', ' ', 'l', 'e', 's', '\0'};

	// ft_print_memory((void *)str, 33);
	// ft_print_memory((void *)str, sizeof(str) / sizeof(str[0]));

	// char str[] = "salut les amis\n";
	// char str[] = {'a', 31, 33, 'c', '\n', '\0'};
	// ft_putstr_non_printable(str);

	// char src[] = "";
	// char dest[12];
	// printf("%d\n", ft_strlcpy(dest, src, sizeof(src)));
	// printf("%s\n", dest);
	// printf("%u\n", ft_strlcpy(dest, src, sizeof(dest)));
	// printf("%lu\n", strlcpy(dest, src, sizeof(dest)));
	// char	str[] = "test deux salut_123 ABCigloo;; ;\n";
	// char	str[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un\n";
	// ft_putstr(str);
	// ft_putstr(ft_strupcase(str));
	// ft_putstr(ft_strlowcase(str));
	// ft_putstr(ft_strcapitalize(str));

	// ft_is_negative(-1);
	// ft_is_negative(0);
	// ft_is_negative(123);

	// ft_print_alphabet();
	// ft_print_reverse_alphabet();

	// ft_print_numbers();

	// ft_putnbr(1);
	// ft_putnbr(12);
	// ft_putnbr(123);
	// ft_putnbr(2147483647);
	// ft_putnbr(-2147483648);
	// ft_print_comb();
	// ft_print_comb2();
	// ft_print_combn(2);
	// write(1, "\n", 1);
	// ft_print_combn(4);

	// if (ft_strlen("") == 0)
	// {
	// 	ft_putstr("OK ;-)\n");
	// }
	// if (ft_strlen("salut") == 5)
	// {
	// 	ft_putstr("OK ;-)\n");
	// }

	// int tab[] = {1, 1};

	// ft_rev_int_tab(tab, 4);
	// print_tab(tab, sizeof(tab) / sizeof(tab[0]));
	// ft_sort_int_tab(tab, sizeof(tab) / sizeof(tab[0]));
	// print_tab(tab, sizeof(tab) / sizeof(tab[0]));

	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 16:13:12 by lgavalda          #+#    #+#             */
/*   Updated: 2019/07/10 13:03:27 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_spaces(unsigned int n)
{
	while (n)
	{
		write(1, " ", 1);
		n--;
	}
}

void	print_memory(void *mem, unsigned int size)
{
	while (size)
	{
		if (*(unsigned char *)mem < ' ' || *(unsigned char *)mem > '~')
		{
			write(1, ".", 1);
		}
		else
		{
			write(1, (char *)mem, 1);
		}
		mem++;
		size--;
	}
}

void	ul2hex(unsigned long n, char *buf, unsigned int buf_size)
{
	while (n != 0 && buf_size > 0)
	{
		*(buf + buf_size - 1) = "0123456789abcdef"[n % 16];
		n /= 16;
		buf_size--;
	}
	while (buf_size > 0)
	{
		*(buf + buf_size - 1) = '0';
		buf_size--;
	}
}

void	print_line(void *addr, unsigned int size)
{
	char			buf[15];
	unsigned int	i;

	ul2hex((unsigned long)addr, buf, 15);
	print_memory(buf, 15);
	write(1, ":", 1);
	i = 0;
	while (i < size)
	{
		if (i++ % 2 == 0)
		{
			write(1, " ", 1);
		}
		ul2hex((unsigned long)*(char *)addr++, buf, 2);
		print_memory(buf, 2);
	}
	print_spaces(40 - 2 * size - (size - 1) / 2);
	print_memory((char *)addr - i, size);
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	void	*addr_save;

	if (size == 0)
		return (addr);
	addr_save = addr;
	while (size > 16)
	{
		print_line(addr, 16);
		addr += 16;
		size -= 16;
	}
	print_line(addr, size);
	return (addr_save);
}

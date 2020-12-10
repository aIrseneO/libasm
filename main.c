/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 19:37:30 by atemfack          #+#    #+#             */
/*   Updated: 2020/12/09 19:37:41 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "libasm.h"

int main(int ac, char **av)
{
	int n, m;
	char **s;

	n = 20; m = 60;
	if (!(s = (char **)malloc(sizeof(*s) * n)))
	{
		printf("ERROR: Malloc failled\n");
		return (-1);
	}
	for (int i = 0; i < n; i++)
	{
		if (!(s[i] = (char *)malloc(sizeof(**s) * m)))
		{
			for (--i; i >= 0 ; i--)
				free(s[i]);
			free(s);
			printf("ERROR: Malloc failled\n");
			return (-1);
		}
		bzero(s[i], m);
	}
	strcpy(s[0], "test_string");
	strcpy(s[1], "");
	strcpy(s[2], ".");
	strcpy(s[3], "!@$^&@#*DGJKFQJKFV");
	s[4][0] = 200; s[4][1] = 130; s[4][2] = '\0';
	strcpy(s[5], "42");
	strcpy(s[6], "aergh;oqenqoevnroifneo  fnocbw  obvwe;obneo;WCN");
	strcpy(s[7], "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
	strcpy(s[8], "\t\t\t\\r\n");
	strcpy(s[9], "!@#$*_~?><AD:FUEFJS}|EHOE*");
	strcpy(s[10], "let's try with     \n     \t\v      \r \n         \f  spaces");
	strcpy(s[11], "a");
	strcpy(s[12], "   ");
	strcpy(s[13], "\\\\");
	strcpy(s[14], "\v");
	strcpy(s[15], "=-{}[];',./\t#$");
	strcpy(s[16], "~~``");
	strcpy(s[17], "42SV_43^3r");
	strcpy(s[18], "%%%%%%");
	strcpy(s[19], "That's enough, isn't it?");

	
	if (ac == 1)
	{
		ft_strlen_test(s, n);
		ft_strcpy_test(s, n, m);
		ft_strcmp_test(s, n);
		ft_write_test(s, n, m);
		ft_read_test(s, n, m);
		ft_strdup_test(s, n, m);
	}
	for (int i = 0; i < ac; i++)
	{
		if (!strcmp(av[i], "ft_strlen"))
			ft_strlen_test(s, n);
		else if (!strcmp(av[i], "ft_strcpy"))
			ft_strcpy_test(s, n, m);
		else if (!strcmp(av[i], "ft_strcmp"))
			ft_strcmp_test(s, n);
		else if (!strcmp(av[i], "ft_write"))
			ft_write_test(s, n, m);
		else if (!strcmp(av[i], "ft_read"))
			ft_read_test(s, n, m);
		else if (!strcmp(av[i], "ft_strdup"))
			ft_strdup_test(s, n, m);
	}
	return (1);
}

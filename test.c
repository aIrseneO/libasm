/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 22:24:00 by atemfack          #+#    #+#             */
/*   Updated: 2020/12/09 21:30:39 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define GRN   "\x1B[32m"
#define RED   "\x1B[31m"
#define RESET "\x1B[0m"

#include "libasm.h"
#include "header.h"

void ft_strlen_test(char **s, int n)
{

	printf("\n---> ft_strlen <---\n");
	for (int i = 0; i < n; i++)
	{
		/*printf("%d - s: |%s|\n", i, s[i]);
		printf("ft_strlen: |%ld|\n", ft_strlen(s[i]));
		printf("   strlen: |%ld|\n",    strlen(s[i]));
		printf("\n");*/
		if (ft_strlen(s[i]) != strlen(s[i]))
		{
			printf(RED "     [Failled]\n" RESET);
			return ;
		}
	}
	printf(GRN "        [Ok]\n" RESET);
}

void ft_strcpy_test(char **s, int n, int m)
{
	char *dest1, *dest2;

	dest1 = NULL; dest2 = NULL;
	if (!(dest1 = (char *)malloc(sizeof(*dest1) * m)) || 
		!(dest2 = (char *)malloc(sizeof(*dest2) * m)))
	{
		printf("ERROR: Couldn't allocate space for strcpy test");
		free(dest1); free(dest2); return ;
	}
	printf("\n---> ft_strcpy <---\n");
	for (int i = 0; i < n; i++)
	{
		bzero(dest1, m); bzero(dest2, m);
		/*printf("%d - source: |%s|\n", i, s[i]);
		printf("ft_strcpy: |%s|, dest1: |%s|\n", ft_strcpy(dest1, s[i]), dest1);
		printf("   strcpy: |%s|, dest2: |%s|\n",    strcpy(dest2, s[i]), dest2);
		printf("\n");*/
		if (memcmp(ft_strcpy(dest1, s[i]), strcpy(dest2, s[i]), m) ||
			memcmp(dest1, dest2, m))
		{
			printf(RED "     [Failled]\n" RESET);
			free(dest1); free(dest2); return ;
		}
	}
	printf(GRN "        [Ok]\n" RESET);
	free(dest1); free(dest2);
}

void ft_strcmp_test(char **s, int n)
{
	int a, b;

	printf("\n---> ft_strcmp <---\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j >= 0; j--)
		{
			/*printf("%d-%d - s1: |%s|, s2: |%s|\n", i, j, s[i], s[j]);
			printf("ft_strcmp: |%d|\n", ft_strcmp(s[i], s[j]));
			printf("   strcmp: |%d|\n",    strcmp(s[i], s[j]));
			printf("\n");*/
			a = ft_strcmp(s[i], s[j]);
			b =    strcmp(s[i], s[j]);
			if (a != b)
			{
				printf(RED "     [Failled]\n" RESET);
				return ;
			}

		}
	}
	printf(GRN "        [Ok]\n" RESET);
}

void ft_write_test(char **s, int n, int m)
{
	int errnum1, errnum2;
	int c1, c2;
	int fd1, fd2;

	if ((fd1 = open("test1", O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, 0644)) == -1
			|| (fd2 = open("test2", O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, 0644)) == -1)
	{
		printf("Couldn't open/create files\n");
		close(fd1); return ;
	}

	printf("\n---> ft_write <---\n");
	for (int i = 0; i < n; i++)
	{
		if (ft_write(fd1, s[i], m) != write(fd2, s[i], m))
		{
			printf(RED "     [Failled]\n" RESET);
			close(fd1); close(fd2); system("rm -f test1 test2"); return ;
		}
	}
	close(fd1); close(fd2); 
	c1 = ft_write(42, "This won't be written", 42); errnum1 = errno;
	c2 =    write(42, "This won't be written", 42); errnum2 = errno;
	if (system("diff test1 test2") || c1 != c2 ||
			strcmp(strerror(errnum1), strerror(errnum2)))
	{
		printf(RED "     [Failled]\n" RESET);
		system("rm -f test1 test2"); return ;
	}
	printf(GRN "        [Ok]\n" RESET);
	system("rm -f test1 tet2");
}

void ft_read_test(char **s, int n, int m)
{
	int errnum1, errnum2;
	int c1, c2;
	int fd1, fd2;

	if ((fd1 = open("test1", O_RDWR | O_CREAT | O_TRUNC | O_APPEND, 0644)) == -1
			|| (fd2 = open("test2", O_RDWR | O_CREAT | O_TRUNC | O_APPEND, 0644)) == -1)
	{
		printf("Couldn't open/create files\n");
		close(fd1); return ;
	}

	printf("\n---> ft_read <---\n");
	for (int i = 0; i < n; i++)
	{
		if (write(fd1, s[i], m) < 0 || write(fd2, s[i], m) < 0)
		{
			printf("Couldn't write in test file\n");
			close(fd1); close(fd2); system("rm -f test1 test2"); return ;
		}
	}
	close(fd1); close(fd2);
	if ((fd1 = open("test1", O_RDONLY)) == -1
			|| (fd2 = open("test2", O_RDONLY)) == -1)
	{
		printf("Couldn't open/create files\n");
		close(fd1); return ;
	}
	while ((c1 = ft_read(fd1, s[1], m)) && (c2 = read(fd2, s[2], m)))
	{
		if (c1 != c2 || strncmp(s[1], s[2], c1))
		{
			printf(RED "     [Failled]\n" RESET);
			close(fd1); close(fd2); system("rm -f test1 test2"); return ;
		}
	}
	close(fd1); close(fd2); system("rm -f test1 test2");
	c1 = ft_read(42, "This won't be read", 42); errnum1 = errno;
	c2 =    read(42, "This won't be read", 42); errnum2 = errno;
	if (c1 != c2 || strcmp(strerror(errnum1), strerror(errnum2)))
	{
		printf(RED "     [Failled]\n" RESET);
		return ;
	}
	printf(GRN "        [Ok]\n" RESET);
}

void ft_strdup_test(char **s, int n, int m)
{
	char *str;

	(void)m;
	printf("\n---> ft_strdup <---\n");
	for (int i = 0; i < n; i++)
	{
		if (strcmp((str = ft_strdup(s[i])), s[i]))
		{
			printf(RED "     [Failled]\n" RESET);
			return ;
		}
		free(str);
	}
	printf(GRN "        [Ok]\n" RESET);
}

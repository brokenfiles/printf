/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <llaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 14:07:10 by llaurent          #+#    #+#             */
/*   Updated: 2019/11/21 17:02:09 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

int main (int ac, char **av)
{
	int second, first, ko, ok, number;
	float rate;
	char *color;
	int index;
	char **kos;

	number = 1234;
	ko = 0;
	ok = 0;
	index = 0;
	kos = (char **)malloc(sizeof(char *) * 100);
	if (ac > 1 && av[1][0] == 'a')
	{
		second = ft_printf(  "---- FAKE PRINTF ----\nresult : %d\\ ", 1337);
		first =     printf("\n---- REAL PRINTF ----\nresult : %d\\", 1337);
		printf("\nfirst: %d, second: %d, equals: %s\033[00m\n", second, first, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO]<--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nresult : %s\\ ", "yo lekip");
		first =     printf("\n---- REAL PRINTF ----\nresult : %s\\", "yo lekip");
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", second, first, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nresult : %u\\ ", (unsigned int)1337);
		first =     printf("\n---- REAL PRINTF ----\nresult : %u\\", (unsigned int)1337);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", second, first, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nresult : %p\\ ", &rate);
		first =     printf("\n---- REAL PRINTF ----\nresult : %p\\", &rate);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", second, first, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nresult : %x\\ ", 1337);
		first =     printf("\n---- REAL PRINTF ----\nresult : %x\\", 1337);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", second, first, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nresult : %X\\ ", 1337);
		first =     printf("\n---- REAL PRINTF ----\nresult : %X\\", 1337);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", second, first, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nresult : %c\\ ", 'c');
		first =     printf("\n---- REAL PRINTF ----\nresult : %c\\", 'c');
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", second, first, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nresult : %%\\ ");
		first =     printf("\n---- REAL PRINTF ----\nresult : %%\\");
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", second, first, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nresult : %-5c\\ ", 'c');
		first =     printf("\n---- REAL PRINTF ----\nresult : %-5c\\", 'c');
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", second, first, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nresult : %-5s\\ ", "yo lekip");
		first =     printf("\n---- REAL PRINTF ----\nresult : %-5s\\", "yo lekip");
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", second, first, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nresult : %-5p\\ ", &number);
		first =     printf("\n---- REAL PRINTF ----\nresult : %-5p\\", &number);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", second, first, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nresult : %-5d\\ ", 1337);
		first =     printf("\n---- REAL PRINTF ----\nresult : %-5d\\", 1337);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", second, first, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nresult : %-5i\\ ", 1337);
		first =     printf("\n---- REAL PRINTF ----\nresult : %-5i\\", 1337);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", second, first, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nresult : %-5u\\ ", (unsigned int)4294967295);
		first =     printf("\n---- REAL PRINTF ----\nresult : %-5u\\", (unsigned int)4294967295);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", second, first, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nresult : %-8x\\ ", 1685);
		first =     printf("\n---- REAL PRINTF ----\nresult : %-8x\\", 1685);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", second, first, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nresult : %-8X\\ ", 1685);
		first =     printf("\n---- REAL PRINTF ----\nresult : %-8X\\", 1685);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", second, first, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nresult : %-5%\\ ");
		first =     printf("\n---- REAL PRINTF ----\nresult : %-5%\\");
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", second, first, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nresult : %010d\\ ", 1337);
		first =     printf("\n---- REAL PRINTF ----\nresult : %010d\\", 1337);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", second, first, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nresult : %010i\\ ", 1337);
		first =     printf("\n---- REAL PRINTF ----\nresult : %010i\\", 1337);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", second, first, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nresult : %010u\\ ", (unsigned int)1337);
		first =     printf("\n---- REAL PRINTF ----\nresult : %010u\\", (unsigned int)1337);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", second, first, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nresult : %010x\\ ", 1337);
		first =     printf("\n---- REAL PRINTF ----\nresult : %010x\\", 1337);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", second, first, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nresult : %010X\\ ", 1337);
		first =     printf("\n---- REAL PRINTF ----\nresult : %010X\\", 1337);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", second, first, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;		if (second != first)
			sprintf(kos[ko], "test #%d failed.", ko+ok);
		second = ft_printf(  "---- FAKE PRINTF ----\nresult : %010%\\ ");
		first =     printf("\n---- REAL PRINTF ----\nresult : %010%\\");
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", second, first, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nresult : %5.3s\\ ", "forty-two");
		first =     printf("\n---- REAL PRINTF ----\nresult : %5.3s\\", "forty-two");
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", second, first, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nresult : %.10d\\ ", 42);
		first =     printf("\n---- REAL PRINTF ----\nresult : %.10d\\", 42);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", second, first, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nresult : %.10i\\ ", 42);
		first =     printf("\n---- REAL PRINTF ----\nresult : %.10i\\", 42);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", second, first, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nresult : %.10u\\ ", (unsigned int)1337);
		first =     printf("\n---- REAL PRINTF ----\nresult : %.10u\\", (unsigned int)1337);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", second, first, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nresult : %.10x\\ ", 42);
		first =     printf("\n---- REAL PRINTF ----\nresult : %.10x\\", 42);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", second, first, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nresult : %.10X\\ ", 42);
		first =     printf("\n---- REAL PRINTF ----\nresult : %.10X\\", 42);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", second, first, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nresult : %.10%\\ ");
		first =     printf("\n---- REAL PRINTF ----\nresult : %.10%\\");
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", second, first, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nresult : %*c\\ ", 10, 'f');
		first =     printf("\n---- REAL PRINTF ----\nresult : %*c\\", 10, 'f');
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", second, first, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nresult : %*s\\ ", 10, "yo lekip");
		first =     printf("\n---- REAL PRINTF ----\nresult : %*s\\", 10, "yo lekip");
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", second, first, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nresult : %*p\\ ", 20, &number);
		first =     printf("\n---- REAL PRINTF ----\nresult : %*p\\", 20, &number);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", second, first, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nresult : %*d\\ ", 10, 42);
		first =     printf("\n---- REAL PRINTF ----\nresult : %*d\\", 10, 42);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", second, first, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nresult : %*i\\ ", 10, 42);
		first =     printf("\n---- REAL PRINTF ----\nresult : %*i\\", 10, 42);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", second, first, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nresult : %*u\\ ", 56, (unsigned int)4294967295);
		first =     printf("\n---- REAL PRINTF ----\nresult : %*u\\", 56, (unsigned int)4294967295);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", second, first, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nresult : %*x\\ ", 10, 42);
		first =     printf("\n---- REAL PRINTF ----\nresult : %*x\\", 10, 42);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", second, first, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nresult : %*X\\ ", 10, 42);
		first =     printf("\n---- REAL PRINTF ----\nresult : %*X\\", 10, 42);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", second, first, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nresult : %*%\\ ", 10);
		first =     printf("\n---- REAL PRINTF ----\nresult : %*%\\", 10);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", second, first, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nresult : %-2.10s\\ ", "forty-two-leet");
		first =     printf("\n---- REAL PRINTF ----\nresult : %-2.10s\\", "forty-two-leet");
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", second, first, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nresult : %-.10d\\ ", 421337);
		first =     printf("\n---- REAL PRINTF ----\nresult : %-.10d\\", 421337);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", second, first, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nresult : %-.10i\\ ", 421337);
		first =     printf("\n---- REAL PRINTF ----\nresult : %-.10i\\", 421337);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", second, first, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nresult : %-.10u\\ ", (unsigned int)421337);
		first =     printf("\n---- REAL PRINTF ----\nresult : %-.10u\\", (unsigned int)421337);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", second, first, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nresult : %-.10x\\ ", 421337);
		first =     printf("\n---- REAL PRINTF ----\nresult : %-.10x\\", 421337);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", second, first, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nresult : %-.10X\\ ", 421337);
		first =     printf("\n---- REAL PRINTF ----\nresult : %-.10X\\", 421337);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", second, first, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nresult : %-8.10%\\ ");
		first =     printf("\n---- REAL PRINTF ----\nresult : %-8.10%\\");
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", second, first, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nresult : %010.8d\\ ", 42);
		first =     printf("\n---- REAL PRINTF ----\nresult : %010.8d\\", 42);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", second, first, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nresult : %010.8i\\ ", 42);
		first =     printf("\n---- REAL PRINTF ----\nresult : %010.8i\\", 42);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", second, first, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nresult : %010.8u\\ ", (unsigned int)42133721);
		first =     printf("\n---- REAL PRINTF ----\nresult : %010.8u\\", (unsigned int)42133721);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", second, first, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nresult : %010.8x\\ ", 42);
		first =     printf("\n---- REAL PRINTF ----\nresult : %010.8x\\", 42);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", second, first, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nresult : %010.8X\\ ", 42);
		first =     printf("\n---- REAL PRINTF ----\nresult : %010.8X\\", 42);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", second, first, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nresult : %010.8%\\ ");
		first =     printf("\n---- REAL PRINTF ----\nresult : %010.8%\\");
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", second, first, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nresult : %.010s\\ ", "hello");
		first =     printf("\n---- REAL PRINTF ----\nresult : %.010s\\", "hello");
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", second, first, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nresult : %.010d\\ ", 42);
		first =     printf("\n---- REAL PRINTF ----\nresult : %.010d\\", 42);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", second, first, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nresult : %.010i\\ ", 42);
		first =     printf("\n---- REAL PRINTF ----\nresult : %.010i\\", 42);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", second, first, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nresult : %.010u\\ ", 42);
		first =     printf("\n---- REAL PRINTF ----\nresult : %.010u\\", 42);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", second, first, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nresult : %.010x\\ ", 42);
		first =     printf("\n---- REAL PRINTF ----\nresult : %.010x\\", 42);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", second, first, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nresult : %.010X\\ ", 42);
		first =     printf("\n---- REAL PRINTF ----\nresult : %.010X\\", 42);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", second, first, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nresult : %.010%\\ ");
		first =     printf("\n---- REAL PRINTF ----\nresult : %.010%\\");
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", second, first, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nresult : %*.10s\\ ", 5, "not the same as others");
		first =     printf("\n---- REAL PRINTF ----\nresult : %*.10s\\", 5, "not the same as others");
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", second, first, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nresult : %*.10d\\ ", 16, 42);
		first =     printf("\n---- REAL PRINTF ----\nresult : %*.10d\\", 16, 42);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", second, first, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nresult : %*.10i\\ ", 16, 42);
		first =     printf("\n---- REAL PRINTF ----\nresult : %*.10i\\", 16, 42);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", second, first, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nresult : %*.10u\\ ", 16, (unsigned int)42133721);
		first =     printf("\n---- REAL PRINTF ----\nresult : %*.10u\\", 16, (unsigned int)42133721);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", second, first, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nresult : %*.10x\\ ", 16, 42);
		first =     printf("\n---- REAL PRINTF ----\nresult : %*.10x\\", 16, 42);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", second, first, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nresult : %*.10X\\ ", 16, 42);
		first =     printf("\n---- REAL PRINTF ----\nresult : %*.10X\\", 16, 42);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", second, first, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nresult : %*.10%\\ ", 16);
		first =     printf("\n---- REAL PRINTF ----\nresult : %*.10%\\", 16);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", second, first, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nresult : %*.*d\\ ", 16, 16, 1337);
		first =     printf("\n---- REAL PRINTF ----\nresult : %*.*d\\", 16, 16, 1337);
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", second, first, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}
		second = ft_printf(  "---- FAKE PRINTF ----\nresult : %---12s\\ ", "bonjour");
		first =     printf("\n---- REAL PRINTF ----\nresult : %---12s\\", "bonjour");
		printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", second, first, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
		ko += (second != first) ? 1 : 0;
		ok += (second == first) ? 1 : 0;
		if (second != first)
		{
			kos[ko] = malloc(sizeof(char) * 35);
			sprintf(kos[ko], "test #%d failed at line %d.", ko+ok, __LINE__ - 8);
		}

		kos[ko + 1] = 0;
		index++;
		if (kos[1])
			printf("\n\033[1;31mTEST ERRORS:\033[00m\n");
		while (kos[index])
		{
			printf("- \033[1;31m%s\033[00m\n", kos[index]);
			free(kos[index]);
			index++;
		}
		free(kos);
	}
	else
	{
        second = ft_printf(  "---- FAKE PRINTF ----\nresult : %10.7s\\ ", "yo lekip");
        first =     printf("\n---- REAL PRINTF ----\nresult : %10.7s\\" , "yo lekip");
        printf("%s\nfirst: %d, second: %d, equals: %s\033[00m\n", first != second ? "\n": "", second, first, first == second ? "\033[1;32m[OK]" : "\033[1;31m[KO] <--------------\n");
        ko += (second != first) ? 1 : 0;
        ok += (second == first) ? 1 : 0;
	}

	rate = (float)(100 * ko)/(ko + ok);
	if (rate > 0 && rate < 15)
		color = ft_strdup("\033[01;33m");
	else if (rate == 0)
		color = ft_strdup("\033[1;32m");
	else
		color = ft_strdup("\033[1;31m");
	printf("\n\033[01;33mFINAL RESULT :\033[00m\n\033[1;32m[OK] \033[00m: %d, \033[1;31m[KO] \033[00m: %d, KO rate : %s%.2f%% %s\033[00m\n", ok, ko, color, rate, rate == 0 ? "😃" : "😞");
	free(color);
	return (0);
}

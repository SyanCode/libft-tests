#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	printf("\n=== fs1: chaines et affichage ===\n");

	// Test de la fonction ft_substr
	printf("\n-- ft_substr --\n");
    char str[] = "Hello World";
    char *sub = ft_substr(str, 6, 5);
    if (sub)
    {
        printf("Sub: %s\n", sub); // Attendu "World"
        free(sub);
    }

	// Test de la fonction ft_strjoin
	printf("\n-- ft_strjoin --\n");
    char str1[] = "Hello ";
    char str2[] = "World";
    char *joined = ft_strjoin(str1, str2);
    if (joined)
    {
        printf("Joined: %s\n", joined); // Attendu "Hello World"
        free(joined);
    }

	// Test de la fonction ft_putchar_fd
	printf("\n-- ft_putchar_fd --\n");
    ft_putchar_fd('A', 1);
    ft_putchar_fd('\n', 1);

	// Test de la fonction ft_putstr_fd
	printf("\n-- ft_putstr_fd --\n");
    ft_putstr_fd("Hello World\n", 1);

	// Test de la fonction ft_putendl_fd
	printf("\n-- ft_putendl_fd --\n");
    ft_putendl_fd("Hello World", 1);

	// Test de la fonction ft_putnbr_fd
	printf("\n-- ft_putnbr_fd --\n");
    ft_putnbr_fd(42, 1);
    ft_putchar_fd('\n', 1);
    return 0;
}

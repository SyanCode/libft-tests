#include "libft.h"
#include <stdio.h>

int main(void)
{
	printf("\n=== libc3: conversions et recherche de caracteres ===\n");

	// Test de la fonction ft_toupper
	printf("\n-- ft_toupper --\n");
	printf("%c\n", ft_toupper('a')); // Attendu : A
	printf("%c\n", ft_toupper('A')); // Attendu : A
	printf("%c\n", ft_toupper('z')); // Attendu : Z
	printf("%c\n", ft_toupper('1')); // Attendu : 1

	// Test de la fonction ft_tolower
	printf("\n-- ft_tolower --\n");
	printf("%c\n", ft_tolower('A')); // Attendu : a
	printf("%c\n", ft_tolower('a')); // Attendu : a
	printf("%c\n", ft_tolower('Z')); // Attendu : z
	printf("%c\n", ft_tolower('1')); // Attendu : 1

	// Test de la fonction ft_strchr
	printf("\n-- ft_strchr --\n");
	printf("%s\n", ft_strchr("Hello", 'e')); // Attendu : ello
	char *missing = ft_strchr("Hello", 'x');
	if (missing)
		printf("%s\n", missing);
	else
		printf("(null)\n");

	// Test de la fonction ft_strrchr
	printf("\n-- ft_strrchr --\n");
	printf("%s\n", ft_strrchr("Hello", 'l')); // Attendu : lo
	missing = ft_strrchr("Hello", 'x');
	if (missing)
		printf("%s\n", missing);
	else
		printf("(null)\n");
	return (0);
}

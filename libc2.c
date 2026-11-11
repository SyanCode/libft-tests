#include "libft.h"
#include <stdio.h>

int main(void)
{
	printf("\n=== libc2: fonctions de verification de caracteres ===\n");

	// Test de la fonction ft_isalpha
	printf("\n-- ft_isalpha --\n");
	printf("%d\n", ft_isalpha('a')); // Attendu : 1
	printf("%d\n", ft_isalpha('1')); // Attendu : 0
	printf("%d\n", ft_isalpha('Z')); // Attendu : 1
	printf("%d\n", ft_isalpha('%')); // Attendu : 0

	// Test de la fonction ft_isdigit
	printf("\n-- ft_isdigit --\n");
	printf("%d\n", ft_isdigit('5')); // Attendu : 1
	printf("%d\n", ft_isdigit('a')); // Attendu : 0
	printf("%d\n", ft_isdigit('%')); // Attendu : 0
	
	// Test de la fonction ft_isalnum
	printf("\n-- ft_isalnum --\n");
	printf("%d\n", ft_isalnum('a')); // Attendu : 1
	printf("%d\n", ft_isalnum('1')); // Attendu : 1
	printf("%d\n", ft_isalnum('%')); // Attendu : 0
	
	// Test de la fonction ft_isascii
	printf("\n-- ft_isascii --\n");
	printf("%d\n", ft_isascii('a')); // Attendu : 1
	printf("%d\n", ft_isascii(128)); // Attendu : 0
	printf("%d\n", ft_isascii(127)); // Attendu : 1
	printf("%d\n", ft_isascii(-1)); // Attendu : 0
	
	// Test de la fonction ft_isprint
	printf("\n-- ft_isprint --\n");
	printf("%d\n", ft_isprint('a')); // Attendu : 1
	printf("%d\n", ft_isprint(' ')); // Attendu : 1
	printf("%d\n", ft_isprint(127)); // Attendu : 0
	printf("%d\n", ft_isprint(31)); // Attendu : 0
	
	return (0);
}

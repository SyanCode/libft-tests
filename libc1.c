#include "libft.h"
#include <stdio.h>

int main(void)
{
	printf("\n=== libc1: fonctions memoire et chaine ===\n");

	// Test de la fonction ft_strlen
	printf("\n-- ft_strlen --\n");
	printf("%zu\n", ft_strlen("Hello")); // Attendu : 5
	printf("%zu\n", ft_strlen("")); // Attendu : 0
	printf("%zu\n", ft_strlen("Bonjour")); // Attendu : 7
	printf("%zu\n", ft_strlen("42")); // Attendu : 2
	
	// Test de la fonction ft_memcpy
	printf("\n-- ft_memcpy --\n");
	char src[] = "Hello";
	char dest[6];
	ft_memcpy(dest, src, 6);
	printf("%s\n", dest); // Attendu : Hello
	
	// Test de la fonction ft_memset
	printf("\n-- ft_memset --\n");
	ft_memset(dest, 'A', 5);
	dest[5] = '\0';
	printf("%s\n", dest); // Attendu : AAAAA
	
	// Test de la fonction ft_bzero
	printf("\n-- ft_bzero --\n");
	ft_bzero(dest, 6);
	printf("%s\n", dest); // Attendu : (chaine vide)
	
	// Test de la fonction ft_memmove
	printf("\n-- ft_memmove --\n");
	char overlap[] = "Hello";
	ft_memmove(overlap + 2, overlap, 4);
	printf("%s\n", overlap); // Attendu : HeHell
	
	// Test de la fonction ft_memcmp
	printf("\n-- ft_memcmp --\n");
	char buf1[] = "Hello";
	char buf2[] = "Hello";
	printf("%d\n", ft_memcmp(buf1, buf2, 5)); // Attendu : 0
	char buf3[] = "Hello";
	char buf4[] = "Hella";
	printf("%d\n", ft_memcmp(buf3, buf4, 5)); // Attendu : > 0
	char buf5[] = "Hella";
	char buf6[] = "Hello";
	printf("%d\n", ft_memcmp(buf5, buf6, 5)); // Attendu : < 0
	
	// Test de la fonction ft_memchr
	printf("\n-- ft_memchr --\n");
	char buf7[] = "Hello";
	printf("%s\n", (char *)ft_memchr(buf7, 'e', 5)); // Attendu : ello
	char *missing = (char *)ft_memchr(buf7, 'x', 5);
	if (missing)
		printf("%s\n", missing);
	else
		printf("(null)\n");
	return (0);
}

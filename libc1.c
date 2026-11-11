#include "libft.h"
#include <stdio.h>

int main(void)
{
	printf("\n=== libc1: fonctions memoire et chaine ===\n");

	// Test de la fonction ft_strlen
	printf("\n-- ft_strlen --\n");
	printf("Expected: 5 | Result: %zu\n", ft_strlen("Hello"));
	printf("Expected: 0 | Result: %zu\n", ft_strlen(""));
	printf("Expected: 7 | Result: %zu\n", ft_strlen("Bonjour"));
	printf("Expected: 2 | Result: %zu\n", ft_strlen("42"));
	
	// Test de la fonction ft_memcpy
	printf("\n-- ft_memcpy --\n");
	char src[] = "Hello";
	char dest[6];
	ft_memcpy(dest, src, 6);
	printf("Expected: \"Hello\" | Result: \"%s\"\n", dest);
	
	// Test de la fonction ft_memset
	printf("\n-- ft_memset --\n");
	ft_memset(dest, 'A', 5);
	dest[5] = '\0';
	printf("Expected: \"AAAAA\" | Result: \"%s\"\n", dest);
	
	// Test de la fonction ft_bzero
	printf("\n-- ft_bzero --\n");
	ft_bzero(dest, 6);
	printf("Expected: \"\" | Result: \"%s\"\n", dest);
	
	// Test de la fonction ft_memmove
	printf("\n-- ft_memmove --\n");
	char overlap[] = "Hello";
	ft_memmove(overlap + 2, overlap, 4);
	printf("Expected: \"HeHell\" | Result: \"%s\"\n", overlap);
	
	// Test de la fonction ft_memcmp
	printf("\n-- ft_memcmp --\n");
	char buf1[] = "Hello";
	char buf2[] = "Hello";
	printf("Expected: 0 | Result: %d\n", ft_memcmp(buf1, buf2, 5));
	char buf3[] = "Hello";
	char buf4[] = "Hella";
	printf("Expected: > 0 | Result: %d\n", ft_memcmp(buf3, buf4, 5));
	char buf5[] = "Hella";
	char buf6[] = "Hello";
	printf("Expected: < 0 | Result: %d\n", ft_memcmp(buf5, buf6, 5));
	
	// Test de la fonction ft_memchr
	printf("\n-- ft_memchr --\n");
	char buf7[] = "Hello";
	char *found = (char *)ft_memchr(buf7, 'e', 5);
	printf("Expected: \"ello\" | Result: %s\n", found ? found : "(null)");
	char *missing = (char *)ft_memchr(buf7, 'x', 5);
	printf("Expected: (null) | Result: %s\n", missing ? missing : "(null)");
	return (0);
}

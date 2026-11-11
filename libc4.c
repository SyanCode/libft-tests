#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	printf("\n=== libc4: chaines et allocation ===\n");

	// Test de la fonction ft_strlcat
	printf("\n-- ft_strlcat --\n");
    char dest[20] = "Hello";
    char src[] = " World";
    size_t size = sizeof(dest);
    size_t result = ft_strlcat(dest, src, size);
    printf("Result: %zu\n", result); // Attendu 11
    printf("Dest: %s\n", dest); // Attendu "Hello World"

	// Test de la fonction ft_strlcpy
	printf("\n-- ft_strlcpy --\n");
    char dest2[20];
    char src2[] = "Hello World";
    size_t size2 = sizeof(dest2);
    size_t result2 = ft_strlcpy(dest2, src2, size2);
    printf("Result: %zu\n", result2); // Attendu 11
    printf("Dest: %s\n", dest2); // Attendu "Hello World"
	char dest3[20];
	char src3[] = "Hello";
	size_t size3 = sizeof(dest3);
	size_t result3 = ft_strlcpy(dest3, src3, size3);
	printf("Result: %zu\n", result3); // Attendu 5
	printf("Dest: %s\n", dest3); // Attendu "Hello"

	// Test de la fonction ft_atoi
	printf("\n-- ft_atoi --\n");
    char str[] = "12345";
    int result4 = ft_atoi(str);
    printf("Result: %d\n", result4); // Attendu 12345

	// Test de la fonction ft_strnstr
	printf("\n-- ft_strnstr --\n");
    char big[] = "Hello World";
    char little[] = "World";
    size_t len = sizeof(big);
    char *result5 = ft_strnstr(big, little, len);
    if (result5)
        printf("Result: %s\n", result5); // Attendu "World"
    else
    {
        printf("Result: (null)\n");
    }
	
	// Test de la fonction ft_strncmp
	printf("\n-- ft_strncmp --\n");
    char s1[] = "Hello";
    char s2[] = "Hello";
    size_t n = 5;
    int result6 = ft_strncmp(s1, s2, n);
    printf("Result: %d\n", result6); // Attendu 0

	// Test de la fonction ft_calloc
	printf("\n-- ft_calloc --\n");
    size_t count = 5;
	size_t i = 0;
    size_t element_size = sizeof(int);
    int *arr = (int *)ft_calloc(count, element_size);
    if (arr)
    {
        while (i < count)
        {
            printf("arr[%zu] = %d\n", i, arr[i]); // Attendu 0
            i++;
        }
        free(arr);
    }

	// Test de la fonction ft_strdup
	printf("\n-- ft_strdup --\n");
    char str4[] = "Hello World";
    char *dup = ft_strdup(str4);
    if (dup)
    {
        printf("Dup: %s\n", dup); // Attendu "Hello World"
        free(dup);
    }
    return 0;
}

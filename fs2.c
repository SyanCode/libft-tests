#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static char	shift_char(unsigned int index, char character)
{
	(void)index;
	return (character + 1);
}

static void	shift_in_place(unsigned int index, char *character)
{
	(void)index;
	*character += 1;
}

int	main(void)
{
	char	str[] = "Hello";
	char	str2[] = "Hello";
	char	str3[] = "  Hello World  ";
	char	str4[] = "Hello World";
	char	*mapped;
	char	*trimmed;
	char	**split;
	char	*number;
	int		index;

	printf("\n=== fs2: transformations de chaines ===\n");
	printf("\n-- ft_strmapi --\n");
	mapped = ft_strmapi(str, shift_char);
	if (mapped)
	{
		printf("Mapped (expected Ifmmp): %s\n", mapped);
		free(mapped);
	}
	printf("\n-- ft_striteri --\n");
	ft_striteri(str2, shift_in_place);
	printf("Iteri (expected Ifmmp): %s\n", str2);
	printf("\n-- ft_strtrim --\n");
	trimmed = ft_strtrim(str3, " ");
	if (trimmed)
	{
		printf("Trimmed (expected Hello World): %s\n", trimmed);
		free(trimmed);
	}
	printf("\n-- ft_split --\n");
	split = ft_split(str4, ' ');
	if (split)
	{
		index = 0;
		while (split[index])
		{
			printf("Split[%d]: %s\n", index, split[index]);
			free(split[index]);
			index++;
		}
		free(split);
	}
	printf("\n-- ft_itoa --\n");
	number = ft_itoa(12345);
	if (number)
	{
		printf("Itoa (expected 12345): %s\n", number);
		free(number);
	}
	return (EXIT_SUCCESS);
}

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char *duplicate_string(const char *source)
{
	size_t	length;
	char	*copy;

	length = strlen(source) + 1;
	copy = malloc(length);
	if (copy)
		memcpy(copy, source, length);
	return (copy);
}

static t_list *create_node(const char *content)
{
	char	*content_copy;
	t_list	*node;

	content_copy = duplicate_string(content);
	if (!content_copy)
		return (NULL);
	node = ft_lstnew(content_copy);
	if (!node)
		free(content_copy);
	return (node);
}

static void print_content(void *content)
{
	printf("%s\n", (char *)content);
}

static void *duplicate_content(void *content)
{
	return (duplicate_string((char *)content));
}

static int	test_new_node(void)
{
	t_list	*node;

	printf("\n-- ft_lstnew --\n");
	node = ft_lstnew("Hello");
	if (!node)
		return (0);
	printf("New node content (expected Hello): %s\n", (char *)node->content);
	free(node);
	return (1);
}

static int	test_delete_node(void)
{
	t_list	*node;

	printf("\n-- ft_lstdelone --\n");
	node = create_node("Goodbye");
	if (!node)
		return (0);
	printf("Node content before deletion (expected Goodbye): %s\n",
		(char *)node->content);
	printf("Deleting node...\n");
	ft_lstdelone(node, free);
	printf("Node deleted\n");
	return (1);
}

static int	test_clear_list(void)
{
	t_list	*head;
	t_list	*node;

	printf("\n-- ft_lstclear --\n");
	head = create_node("Node 1");
	node = create_node("Node 2");
	if (!head || !node)
	{
		if (head)
			ft_lstdelone(head, free);
		if (node)
			ft_lstdelone(node, free);
		return (0);
	}
	ft_lstadd_back(&head, node);
	ft_lstclear(&head, free);
	if (!head)
		printf("List cleared successfully\n");
	printf("Head after clearing (expected NULL): %p\n", (void *)head);
	return (1);
}

static t_list	*create_test_list(void)
{
	t_list	*head;
	t_list	*new_head;
	t_list	*back_node;

	printf("\n-- ft_lstadd_front / ft_lstadd_back --\n");
	head = create_node("Middle");
	if (!head)
		return (NULL);
	new_head = create_node("New Head");
	if (!new_head)
	{
		ft_lstclear(&head, free);
		return (NULL);
	}
	ft_lstadd_front(&head, new_head);
	printf("New head content (expected New Head): %s\n",
		(char *)head->content);
	printf("New head next content (expected Middle): %s\n",
		(char *)head->next->content);
	back_node = create_node("Back Node");
	if (!back_node)
	{
		ft_lstclear(&head, free);
		return (NULL);
	}
	ft_lstadd_back(&head, back_node);
	printf("Back node content (expected Back Node): %s\n",
		(char *)back_node->content);
	printf("Head next content after adding back (expected Middle): %s\n",
		(char *)head->next->content);
	return (head);
}

static int	test_list(t_list *head)
{
	t_list	*last_node;
	t_list	*mapped_list;
	int		success;

	printf("\n-- ft_lstsize / ft_lstlast --\n");
	printf("List size (expected 3): %d\n", ft_lstsize(head));
	last_node = ft_lstlast(head);
	if (last_node)
		printf("Last node content (expected Back Node): %s\n",
			(char *)last_node->content);
	printf("\n-- ft_lstiter --\n");
	ft_lstiter(head, print_content);
	printf("\n-- ft_lstmap --\n");
	mapped_list = ft_lstmap(head, duplicate_content, free);
	if (!mapped_list)
		success = 0;
	else
	{
		printf("Mapped list first node content (expected New Head): %s\n",
			(char *)mapped_list->content);
		ft_lstclear(&mapped_list, free);
		success = 1;
	}
	ft_lstclear(&head, free);
	return (success);
}

int	main(void)
{
	t_list	*head;

	printf("\n=== bonus: fonctions de listes chainees ===\n");
	if (!test_new_node() || !test_delete_node() || !test_clear_list())
		return (EXIT_FAILURE);
	head = create_test_list();
	if (!head)
		return (EXIT_FAILURE);
	if (!test_list(head))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

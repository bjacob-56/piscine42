#include <stddef.h>
#include <stdio.h>

char *ft_strjoin(int size, char **strs, char *sep);

int main()
{
	char *strs[3] = {NULL, NULL, NULL};

	printf("%s\n", ft_strjoin(3, strs, ", "));
}

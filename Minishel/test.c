#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int i = 0;
	char str[10] = "hamza";
	char *p;

	p = malloc(6 * sizeof(char));
	while (str[i])
	{
		p[i] = str[i];
		i++;
	}
	p[i] = '\0';
	i = 0;
	while (p[i])
	{
		printf("%c\n", p[i]);
		printf("%c__\n", p[i + 1]);
		printf("%c__\n", p[i + 2]);
		printf("%c__\n", p[i + 6]);
		i++;
	}
}
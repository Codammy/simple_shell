#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char s[] = "         /bin/ls           uu      ";
        char *tok, *new;
        int count = 0, i = 0, j = 0;
	
	printf("%s\n", s);
        tok = strtok(s, " ");
        while (tok != NULL)
                tok = strtok(NULL, " ");
	printf("%s\n", s);
	while (s[i])
	{
		if (s[i] == ' ')
		{
			printf("\\0");
			i++;
		}
		else
		printf("%c", s[i++]);
	}
	putchar('\n');
        while (s[i])
        {
                if (s[i] == ' ')
                {
                        i++;
                        continue;
                }
		count++;
                i++;
        }
	i = 0;
        new = malloc(count * sizeof(char));
        while (s[i])
        {
		if (s[i] == ' ')
                {
                        i++;
                        continue;
                }
                new[j] = s[i];
		j++;
                i++;
        }
	printf("%s\n", new);
	
        return (0);
}

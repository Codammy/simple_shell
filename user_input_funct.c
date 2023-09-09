#include "shell.h"

void user_entries(char *entries, size_t size)
{
	if (fgets(entries, size, stdin) == NULL)
	{
		if (feof(stdin))
		{
			ebu_dami_print("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			ebu_dami_print("error in taking input.\n");
			exit(EXIT_FAILURE);
		}
	}
	entries[strcspn(entries, "\n")] = '\0';
}

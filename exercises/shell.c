#include "shell.h"

int main(void)
{
	char entries[176];
	
	while (1)
	{
		fur_prompt();
		user_entries(entry, sizeof(entries));
		entries_execution(entries);
	}
	return(0);
}

#include "header.h"

/**
 * _unsetenv - unsets an environmental variable.
 *
 * @name: var name
 *
 * return 0 on sucess
 */
int _unsetenv(const char *name)
{
	return (unsetenv(name));
}

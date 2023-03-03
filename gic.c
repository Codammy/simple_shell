#include "header.h"

/**
 *  * main - simple shell.
 *   * @argc: number of arguments passed at run time.
 *    * @argv: array of pointers to string (passed at run time)
 *     *
 *      * Return: 0.
 *      */
int main(int argc __attribute__((unused)), char *argv[])
{
		struct stat st;
			pid_t pid;
				char *buf, *command;
					int status;
						size_t size = 0;

							while (1)
									{
											pid = fork();
												if (pid == 0)
														{
																	printf("$ ");
																			if (getline(&buf, &size, stdin) == -1)
																							exit(1);
																					command = strtok(buf, "\n");
																							argv[0] = command;
																									argv[1] = NULL;
																											if (stat(command, &st) == -1)
																														{
																																		perror("Error:");
																																					exit(1);
																																							}
																													if (execve(argv[0], argv, NULL))
																																{
																																				perror("Error:");
																																							exit(1);
																																									}
																														}
													else
																wait(&status);
														}
								return (0);
}

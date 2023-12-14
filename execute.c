#include "shell.h"
/**
 * execute - execute command with its complete set of path variables.
 * @data: program's data pointer
 * Return: If sucess returns zero, otherwise, return -1.
 */
int execute(data_of_program *data)
{
	int retval = 0, status;
	pid_t pidd;

	/* check for program in built ins */
	retval = builtins_list(data);
	if (retval != -1)/* if program was found in built ins */
		return (retval);

	/* check for program file system */
	retval = find_program(data);
	if (retval)
	{/* if program not found */
		return (retval);
	}
	else
	{/* if program was found */
		pidd = fork(); /* create a child process */
		if (pidd == -1)
		{ /* if the fork call failed */
			perror(data->command_name);
			exit(EXIT_FAILURE);
		}
		if (pidd == 0)
		{/* I am the child process, I execute the program*/
			retval = execve(data->tokens[0], data->tokens, data->env);
			if (retval == -1) /* if error when execve*/
				perror(data->command_name), exit(EXIT_FAILURE);
		}
		else
		{/* as the parent, I wait and verify the child's exit status */
			wait(&status);
			if (WIFEXITED(status))
				errno = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
				errno = 128 + WTERMSIG(status);
		}
	}
	return (0);
}

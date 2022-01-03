#include <stdio.h>
#include <unistd.h>
#include <wait.h>

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	int status;
	char	*tab[2] = {"cat", NULL};
	char	*tab1[2] = {"ls", NULL};
	int pipes[2];

	pipe(pipes);
	pid_t pid = fork();
	if (pid == 0)
	{
		close(pipes[0]);
		dup2(pipes[1], STDOUT_FILENO);
		close(pipes[1]);
		execve("/bin/cat", tab, env);
	}
	// else
		// close(pipes[1]);

	pid_t	pid1 = fork();
	if (pid1 == 0)
	{
		dup2(pipes[0], STDIN_FILENO);
		close(pipes[0]);
		close(pipes[1]);
		execve("/bin/ls", tab1, env);
	}
	else
	{
		close(pipes[0]);
		close(pipes[1]);
		waitpid(0, &status, WNOHANG);
	}
	return (0);
}
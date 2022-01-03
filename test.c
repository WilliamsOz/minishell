#include <stdio.h>
#include <unistd.h>
#include <wait.h>

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	int status;
	int h;
	char	*tab[2] = {"cat", NULL};
	char	*tab2[2] = {"ls", NULL};

	h = dup(STDIN_FILENO);
	pid_t pid = fork();
	int pipes[2];
	pipe(pipes);
	if (pid == 0)
	{
		// printf("%d\n", h);
		// dup2(h, STDIN_FILENO);
		// close (h);
		dup2(pipes[0], STDIN_FILENO);
		dup2(pipes[1], STDOUT_FILENO);
		execve("/bin/cat", tab, env);
	}
	pid_t	pid1 = fork();
	int pipes1[2];
	pipe(pipes1);
	if (pid1 == 0)
	{
		execve("/bin/ls", tab2, env);
	}
	else
	{
		waitpid(0, &status, WNOHANG);
		printf("%d\n", status);
		close(pipes[0]);
		close(pipes[1]);
	}
	return (0);
}
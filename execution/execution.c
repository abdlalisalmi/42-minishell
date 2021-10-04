#include "execution.h"


int main(int argc, char **argv, char **envp)
{
    collect_env(envp);
    ft_env(NULL, 0);

    // if (g_all.n_commands == 1)
	// 	exec_single_cmd(g_all.commands[0], envp);
	// else
	// {
	// 	printf("Multiple commands? Coming Soon...\n");
	// }
}
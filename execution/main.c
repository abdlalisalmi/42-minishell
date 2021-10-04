#include "execution.h"


void test()
{
	g_all.n_commands = 1;
	g_all.commands = malloc(sizeof(t_commands) * g_all.n_commands);
	g_all.commands[0].n_args = 3;
	g_all.commands[0].args = malloc(sizeof(char *) * g_all.commands[0].n_args);
	g_all.commands[0].args[0] = "ls";
	g_all.commands[0].args[1] = "-l";
	g_all.commands[0].args[2] = 0;
}


int main(int argc, char **argv, char **envp)
{
    collect_env(envp);
    // ft_env(NULL, 0);

    // char **env;
    // env = to_envp();
    // int i = -1;
    // while (++i < g_all.n_env - 1)
    //     printf("%s\n", env[i]);
    
	test();
	
	start_execution();
}
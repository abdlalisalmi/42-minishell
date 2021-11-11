#include "execution.h"


void test()
{
	g_all.n_commands = 1;
	g_all.commands = malloc(sizeof(t_commands) * g_all.n_commands);
	g_all.commands[0].n_args = 3;
	g_all.commands[0].args = malloc(sizeof(char *) * g_all.commands[0].n_args);
	g_all.commands[0].args[0] = "echo";
	g_all.commands[0].args[1] = "hello";
	g_all.commands[0].args[2] = 0;

	// g_all.commands[1].n_args = 3;
	// g_all.commands[1].args = malloc(sizeof(char *) * g_all.commands[1].n_args);
	// g_all.commands[1].args[0] = "cat";
	// g_all.commands[1].args[1] = "file";
	// g_all.commands[1].args[2] = 0;
	
	// g_all.commands[2].n_args = 3;
	// g_all.commands[2].args = malloc(sizeof(char *) * g_all.commands[2].n_args);
	// g_all.commands[2].args[0] = "cat";
	// g_all.commands[2].args[1] = "-e";
	// g_all.commands[2].args[2] = 0;

	g_all.commands[0].n_redirect = 1;
	g_all.commands[0].redirect = malloc(sizeof(t_redirect) * g_all.commands[0].n_redirect);

	// g_all.commands[0].redirect[0].type = LEFT;
	// g_all.commands[0].redirect[0].file = "Makefile";

	g_all.commands[0].redirect[0].type = RIGHT;
	g_all.commands[0].redirect[0].file = "file";

	// g_all.commands[0].redirect[2].type = RIGHT;
	// g_all.commands[0].redirect[2].file = "file2.txt";

}


int main(int argc, char **argv, char **envp)
{
    collect_env(envp);
	(void)argc;
	(void)argv;
    // ft_env(NULL, 0);

    // char **env;
    // env = to_envp();
    // int i = -1;
    // while (++i < g_all.n_env - 1)
    //     printf("%s\n", env[i]);
    
	test();
	
	start_execution();
}
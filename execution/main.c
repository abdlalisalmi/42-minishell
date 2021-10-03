#include "execution.h"



int main(int argc, char **argv, char **envp)
{
    collect_env(envp);
    printf("the first test\n");
    ft_env(NULL, 0);
}
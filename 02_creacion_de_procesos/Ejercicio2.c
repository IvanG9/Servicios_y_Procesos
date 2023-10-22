#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    int valorVariable = 6;
    pid_t pid;

    pid = fork();

    if (pid < 0)
    {
        fprintf(stderr, "Error al crear el proceso hijo\n");
        return 1;
    }

    if (pid == 0)
    {
        valorVariable -= 5;
        printf("Soc el fill. Valor variable: %d\n", valorVariable);
    }
    else
    {
        valorVariable += 5;
        printf("Soc el pare. Valor variable: %d\n", valorVariable);
    }

    return 0;
}

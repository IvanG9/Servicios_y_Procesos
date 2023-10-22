#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t neto, padre, abuelo;

    printf("Soc l'avi (%d, fill de %d)\n", getpid(), getppid());

    fork(); 

    if (padre == 0)
    { 
        printf("Soc el pare (%d, fill de %d)\n", getpid(), getppid());

        neto = fork(); 

        if (neto == 0)
        { 
            printf("Soc el net (%d, fill de %d)\n", getpid(), getppid());
        }
        else
        {
            wait(NULL); 
        }
    }
    else
    {
        wait(NULL);
    }

    return 0;
}

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int valor1, valor2;

    // Solicitar dos valores enteros positivos
    printf("Introduce dos valores enteros positivos: ");
    scanf("%d %d", &valor1, &valor2);

    pid_t pid_B, pid_E, pid_F, pid_G;

    // Nivel A
    printf("A (PID %d)\n", getpid());
    printf("Operación A: %d\n", valor1);

    pid_B = fork(); // Crear proceso B

    if (pid_B == 0)
    { // Código de B
        printf("B (PID %d, PID padre %d)\n", getpid(), getppid());
        printf("Operación B: Suma %d + %d = %d\n", valor1, valor2, valor1 + valor2);
    }
    else
    {
        // Esperar a B
        wait(NULL);

        pid_E = fork(); // Crear proceso E

        if (pid_E == 0)
        { // Código de E
            printf("E (PID %d, PID padre %d)\n", getpid(), getppid());
            printf("Operación E: Primer operando al cuadrado %d * %d = %d\n", valor1, valor1, valor1 * valor1);
        }
        else
        {
            // Esperar a E
            wait(NULL);

            pid_F = fork(); // Crear proceso F

            if (pid_F == 0)
            { // Código de F
                printf("F (PID %d, PID padre %d)\n", getpid(), getppid());
                printf("Operación F: Segundo operando al cuadrado %d * %d = %d\n", valor2, valor2, valor2 * valor2);
            }
            else
            {
                // Esperar a F
                wait(NULL);

                pid_G = fork(); // Crear proceso G

                if (pid_G == 0)
                { // Código de G
                    printf("G (PID %d, PID padre %d)\n", getpid(), getppid());
                    printf("Operación G: Media de los valores (%d + %d) / 2 = %.2f\n", valor1, valor2, (float)(valor1 + valor2) / 2);
                }
                else
                {
                    // Esperar a G
                    wait(NULL);
                }
            }
        }
    }

    // Nivel C
    pid_t pid_C = fork();
    if (pid_C == 0)
    {
        printf("C (PID %d, PID padre %d)\n", getpid(), getppid());
        printf("Operación C: Resta %d - %d = %d\n", valor1, valor2, valor1 - valor2);
    }
    else
    {
        // Esperar a C
        wait(NULL);

        // Nivel D
        pid_t pid_D = fork();
        if (pid_D == 0)
        {
            printf("D (PID %d, PID padre %d)\n", getpid(), getppid());
            printf("Operación D: Multiplicación %d * %d = %d\n", valor1, valor2, valor1 * valor2);
        }
        else
        {
            // Esperar a D
            wait(NULL);
        }
    }

    return 0;
}

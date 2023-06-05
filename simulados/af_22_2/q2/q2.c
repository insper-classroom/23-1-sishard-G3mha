// Leia o PDF ou MD antes de iniciar este exercício!

// inclua libs aqui!
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    char *palavra;
    palavra = argv[1];
    pid_t filho;

    while (1) {
        filho = fork();
        if (filho == 0) {
            char *args[] = {"./verify", palavra, NULL};
            execvp(args[0], args);
        } else {
            int status;
            sleep(2);
            if (waitpid(filho, &status, WNOHANG) > 0) {
                int retorno = (char)WEXITSTATUS(status);
                printf("VERIFY RETORNOU %d\n", retorno);
                return retorno;
            } else {
                printf("VERIFY TEMINOU COM SINAL %s\n", strsignal(status));
                kill(filho, SIGKILL);
            }
        }
    }

    return 0;
}

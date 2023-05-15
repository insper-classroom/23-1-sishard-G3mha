#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>  //open

char *get_url()
{
    int file = open("config.ic", O_RDONLY);
    if (file == -1) {
        printf("Arquivo de configuração não encontrado!\n");
        exit(1);
    }
    char c[16];
    char *url = malloc(100 * sizeof(char));
    char c2;
    read(file, &c, 16);
    char *c3 = "INSPER_COIN_URL=";
    if (strncmp(c, c3, 16) == 0) {
        int i = 0;
        char newline = '\n';
        read(file, &c2, 1);
        while (c2 != newline) {
            url[i] = c2;
            i++;
            read(file, &c2, 1);
        }
    }
    close(file);
    return url;
}

int main(void) {
    char *url = get_url();
    printf("URL: %s\n", url);
    free(url);
    return 0;
}
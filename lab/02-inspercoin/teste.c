#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>  //open

char *get_default_wallet(void)
{
    int file = open("config.ic", O_RDONLY);
    if (file == -1) {
        printf("Arquivo de configuração não encontrado!\n");
        exit(1);
    }

    int i = 0;
    int bytes;
    char each_char;
    char label_found = 0;
    char write_value = 0;
    char *default_wallet = malloc(100 * sizeof(char));
    while (1) {
        bytes = read(file, &each_char, 1);
        if (bytes == 0 || bytes == -1) {
            break;
        }
        if (each_char == 'D') {
            label_found = 1;
            continue;
        }
        if (label_found) {
            if (write_value) {
                if (each_char == '\n') {
                    write_value = 0;
                    label_found = 0;
                    continue;
                }
                default_wallet[i] = each_char;
                i++;
            }
            if (each_char == '=') {
                write_value = 1;
                continue;
            }
        }
    }
    realloc(default_wallet, strlen(default_wallet) + 1);
    close(file);
    return default_wallet;
}

int main(void) {
    char *default_wallet = get_default_wallet();
    printf("default_wallet: %s\n", default_wallet);
    free(default_wallet);
    return 0;
}
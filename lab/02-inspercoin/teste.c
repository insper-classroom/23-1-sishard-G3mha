#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <jansson.h>
#include <sodium.h>
#include <curl/curl.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "coin.h"
#include "key.h"
#include <unistd.h> //sleep
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
    char *wallet = get_default_wallet();
    t_key *public_key = load_public_key(wallet);
    unsigned char *address_from = key_to_hex(public_key);
    printf("address_from: %s\n", address_from);
    printf("default_wallet: %s\n", wallet);
    free(wallet);
    free(address_from);
    return 0;
}
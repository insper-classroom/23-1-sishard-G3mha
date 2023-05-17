char *get_url(void)
{
    int file = open("config.ic", O_RDONLY);

    int i = 0;
    int bytes;
    char each_char;
    char label_found = 0;
    char write_value = 0;
    char *url = malloc(100 * sizeof(char));
    while (1) {
        bytes = read(file, &each_char, 1);
        if (bytes == 0 || bytes == -1) {
            break;
        }
        if (each_char == 'I') {
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
                url[i] = each_char;
                i++;
            }
            if (each_char == '=') {
                write_value = 1;
                continue;
            }
        }
    }
    realloc(url, strlen(url) + 1);
    close(file);
    return url;
}

// old one 

char *get_url(void)
{
    int file = open("config.ic", O_RDONLY);

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
    realloc(url, strlen(url) + 1);
    close(file);
    return url;
}
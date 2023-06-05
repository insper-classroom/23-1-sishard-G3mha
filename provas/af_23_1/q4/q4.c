// Leia o PDF ou MD antes de iniciar este exercício!

// inclua libs aqui!
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <pthread.h>

char *read_word(int fd);

typedef struct
{
    int id_thread;   // identificador da thread
    int *count_ceps; // para as threads saberem onde guardar o resultado!
    int file_desc;   // descritor do arquivo
} t_arg;

/*
 * Função que verifica se um char é numérico
 */
int isnum(char c)
{
    return c >= '0' && c <= '9';
}

/*
 * Função que verifica se uma palavra é um cep válido
 * do ponto de vista do formado DDDDD-DDD
 * onde D é um dígito
 *
 * ENTRADA:
 * char *txt: cep a ser validado
 *
 * SAIDA:
 *   (int) 0: o CEP é válido
 *   (int) 1: Tamanho da palavra não é tamanho de CEP!
 *   (int) 2: Tamanho ok mas formato inválido!
 */
int validade_cep(char *txt)
{
    char *p;
    int valid = 1;
    int qtde = 0;
    for (qtde = 0; txt[qtde] != '\0'; qtde++)
        ;
    if (qtde != 9)
    {
        return 1;
    }
    if (isnum(txt[0]) &&
        isnum(txt[1]) &&
        isnum(txt[2]) &&
        isnum(txt[3]) &&
        isnum(txt[4]) &&
        txt[5] == '-' &&
        isnum(txt[6]) &&
        isnum(txt[7]) &&
        isnum(txt[8]))
    {
        return 0;
    }
    else
    {
        return 2;
    }
}

/*
 * Faz validação de cep em Thread.
 *
 * A thread recebe um descritor de arquivo e deve ler
 * palavras dele enquanto o arquivo não acabar!
 * 
 */
void *cep_validation_thread(void *_arg)
{
    t_arg *arg = _arg;

    while (1)
    {
        // Tenta ler uma palavra do arquivo
        char *palavra = read_word(arg->file_desc);

        if (palavra == NULL)
        {
            // FUNCAO read_word NAO IMPLEMENTADA OU FINAL DO ARQUIVO!
            break;
        }

        printf("THREAD %02d VAI PROCESSAR PALAVRA [%s]\n", arg->id_thread, palavra);
        fflush(stdout);

        int ret = validade_cep(palavra);
        if (ret == 0)
        {
            *arg->count_ceps = *arg->count_ceps + 1;
        }
    }
}

/* Função que lê uma palavra de um arquivo.
 * Considere que o arquivo contém apenas uma linha, sem \n no final.
 * A linha possui diversas palavras, separadas por um único espaço
 *
 * Entradas:
 *   int fd: descritor do arquivo
 *
 * Saída:
 *   Ponteiro (char *) para uma string com a palavra lida. Caso o arquivo termine, retorne NULL.
 */
char *read_word(int fd)
{
    // Implemente AQUI!
    return NULL;
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("USAGE:\n./q4 <n_threads> <file_name>\n");
        return EXIT_FAILURE;
    }

    int n_threads = atoi(argv[1]); // Info da linha de comando
    char *file_name = argv[2];     // Info da linha de comando

    int fd1 = open(file_name, O_RDONLY); // Abre o arquivo

    if (fd1 == -1)
    {
        fprintf(stderr, "Falha ao abrir o arquivo!\n");
        exit(EXIT_FAILURE);
    }

    // Inicializa contador de CEPs encontrados
    int count_ceps = 0;

    // Aloca espaço para tids e args das threads
    pthread_t *tids = malloc(sizeof(pthread_t) * n_threads);
    t_arg **args = malloc(sizeof(t_arg *) * n_threads);

    for (int i = 0; i < n_threads; i++)
    {

        t_arg *arg = malloc(sizeof(t_arg));
        arg->file_desc = fd1; // Thread recebe o file descriptor
        arg->count_ceps = &count_ceps;
        arg->id_thread = i;
        args[i] = arg;

        pthread_create(&tids[i], NULL, cep_validation_thread, arg);
        printf("CRIOU THREAD %02d\n", i);
    }

    for (int i = 0; i < n_threads; i++)
    {
        pthread_join(tids[i], NULL);
        printf("THREAD %02d TERMINOU\n", i);
    }

    printf("RESULTADO:\nFORAM ENCONTRADOS %02d CEPS VALIDOS\n", count_ceps);

    close(fd1);
    free(tids);

    return 0;
}
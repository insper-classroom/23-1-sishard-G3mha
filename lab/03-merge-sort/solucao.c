#include "sort-merge.h"
// ... aqui começa sua solucao.
// para compilar use
// gcc -g -Og -Wall sort.o solucao.c -o sort -pthread

/*
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "sort-merge.h"

void * sort(void *args);

int main(int nArgs, char **argv)
{   
    int nThreads, nItens;
    FILE *fp;
    if(nArgs != 4)
        return -1;

    nThreads = atoi(argv[1]);
    nItens   = atoi(argv[2]);

    fp = fopen(argv[3],"r");
    if( !fp ){
        printf("Erro ao abrir arquivo: %s\n",argv[3]);
        return -1;
    }
    printf("Serao criadas %d threads.\n",nThreads);
    fflush(stdout);

    pthread_t *tids = malloc(nThreads * sizeof(pthread_t));

    struct sort_args *vet_sort = malloc(nThreads * sizeof(struct sort_args));
    pthread_mutex_t mutex_file = PTHREAD_MUTEX_INITIALIZER;

    for (int i = 0; i < nThreads; i++) {
        vet_sort[i].idxThread = i;
        vet_sort[i].nThreads = nThreads;
        vet_sort[i].lineFiles = nItens;
        vet_sort[i].mutex_file = &mutex_file;
        vet_sort[i].fp = fp;
        pthread_create(&tids[i], NULL, sort, &vet_sort[i]);
        printf("Criou thread:%d fase sort\n", i);
    }

    printf("Funcao main() espera as threads sort finalizarem...\n");
    fflush(stdout);
    FILE **fpOut = malloc(nThreads*sizeof(FILE));
    for (int i = 0; i < nThreads; i++) {
        pthread_join(tids[i], (void**)&fpOut[i]);
        fclose(fpOut[i]);   
    }
    fclose(fp);
    free(vet_sort);
    free(tids);
    free(fpOut);
    printf("Funcao main() finalizando normalmente...\n");

    return 0;
}
*/

void * sort(void * args) {
    struct sort_args *arg = (struct sort_args *) args;
    int idxThread = arg->idxThread;
    int lineFiles = arg->lineFiles / arg->nThreads;
    FILE *fp = arg->fp;
    rewind(fp);
    char *str = malloc(30 * sizeof(char));
    // limpa lixo do file
    for (int i = 0; i < idxThread; i++) {
        for (int j = 0; j < lineFiles; j++) {
            fscanf(fp, "%s", str);
        }
    }
    char** vet = malloc(lineFiles * sizeof(char*));
    for (int i = 0; i < lineFiles; i++) {
        vet[i] = (char*) malloc(30 * sizeof(char));
        fscanf(fp, "%s", vet[i]);
    }

    // sort algorithm
    for (int i = 0; i < lineFiles; i++) {
        for (int j = i + 1; j < lineFiles; j++) {
            if (strcmp(vet[i], vet[j]) > 0) {
                char aux[30];
                strcpy(aux, vet[i]);
                strcpy(vet[i], vet[j]);
                strcpy(vet[j], aux);
            }
        }
    }

    // escreve no txt com o nome <idxThread>.txt
    char *name = malloc(20 * sizeof(char));
    sprintf(name, "%d.txt", idxThread);
    FILE *fpOut = fopen(name, "w");
    for (int i = 0; i < lineFiles; i++) {
        fprintf(fpOut, "%s\n", vet[i]);
    }
    free(str);
    free(name);
    return fpOut;
}
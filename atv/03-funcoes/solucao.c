// TODO implemente aqui uma funcao chamada "solucao"

int solucao(int edi, long rsi, long *rdx) {
    int eax = rsi * 5;
    eax = eax + edi;
    *rdx = eax;
    eax = rsi * 3;
    eax = eax + (4 * edi);
    return eax;
}

// Questao 04
// Implemente aqui uma funcao chamada ex4_solucao

int ex4_solucao(long rdi, long rsi, long rdx, long rcx) {
    long *r11 = &rdi;
    long *r10 = &rsi;
    long *r9d = &rdx;
    int eax = 0;
    while (1) {
        rdx = eax;
        if (rsi >= rdx) {
            eax = 0;
            break;
        }
        rdx = eax;
        rsi = (4*rdx) + r11;

        rdx = *r10;
        rdi = r9d;
        rdi -= rcx;
        eax++;
        if (rdi < rdx) {
            continue;
        }
        rdi = rcx + r9d;
        if (rdi > rdx) {
            continue;
        }
        else {
            eax = rsi;
            break;
        }
    }
    return eax;
}
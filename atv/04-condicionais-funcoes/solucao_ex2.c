long vezes2(long a);

/* Implementar função solucao_ex2 */

// rdi = a, rsi = b, rbx = c
long solucao_ex2(long a, long b){
    long c = a;
    long retval = vezes2(b);
    c = (retval > c) ? c + c : c;
    retval += c;
    return retval;
}

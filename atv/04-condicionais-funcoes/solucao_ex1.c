/* Implementar função solucao_ex1 */

// rdi = a, rsi = b, rdx = c, rcx = d

int solucao_ex1(long a, long b, long c, long d){
    d = (c * 4) + b + a;
    a *= a;
    c = c + (2 * b) + a;
    return d >= c;
}

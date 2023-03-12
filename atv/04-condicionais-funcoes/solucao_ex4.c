/* Implementar função solucao_ex4 */

int solucao_ex4(short di, int esi) {
    if (di <= 0x11)
        return 0x12 - di;
    
    if ((unsigned char) esi - 0x41 > 1)
        return 0xffffffff;
    
    di -= 0x11;
    return di;
}

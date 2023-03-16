# Baixo Nível Cheatsheet

## Bits e bytes

Agrupamos 8 bits em 1 byte. Um byte é a menor unidade de informação que podemos manipular.

## Número

Como converter:

- Decimal para binário: dividir sucessivamente por 2 e anotar o resto (de baixo para cima)
- Binário para decimal: multiplicar cada bit por 2 elevado a sua posição (de baixo para cima)
- Hexadecimal para binário: converter cada caractere para binário e concatenar

## Tipos em C

- `char`: 1 byte -> biggest number: 2^8 - 1
- `short`: 2 bytes -> biggest number: 2^16 - 1
- `int`: 4 bytes -> biggest number: 2^32 - 1
- `long`: 8 bytes -> biggest number: 2^64 - 1

## Complementos de 2

- Se o bit mais significativo for 0, o número é positivo
- Se o bit mais significativo for 1, o número é negativo e para converter para decimal, fazemos o seguinte:
  - Sinal negativo no inteiro que representa o bit mais significativo
  - Somamos ao outros convertidos

## Big and little endian numbers

Big endian numbers are stored in memory with the most significant byte first. Little endian numbers are stored in memory with the least significant byte first.
_example: in the number 0x12345678, the most significant byte is 0x12 and the least significant byte is 0x78_

## Most and least significant bit

The most significant bit is the bit that is furthest to the left. The least significant bit is the bit that is furthest to the right.
_example: in the number 0b1101, the most significant bit is 1 and the least significant bit is 1_

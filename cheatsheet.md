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

## Tipos na RAM

- Structs:
  - Structs são armazenadas na memória de forma contígua
  - A ordem dos campos é a ordem em que eles são declarados
  - As variáveis de uma struct quando são declaradas são armazenadas em blocos de 8 em 8 bytes
- Ponteiros:
  - Ponteiros representam um endereço de memória
  - O tamanho de um ponteiro é sempre o mesmo, independente do tipo apontado
- Strings:
  - Strings são armazenadas na memória de forma contígua
  - A string termina com o caractere nulo `\0`
  - O tamanho de uma string é sempre o tamanho da string + 1 (para o caractere nulo)

## Comandos para o gdb

- `info`: mostra informações sobre o programa
  - `info registers`: mostra os valores dos registradores
  - `info functions`: mostra as funções do programa
  - `info variables`: mostra as variáveis do programa
- `break`: define um breakpoint
  - `break <function>`: define um breakpoint na função
  - `break <line>`: define um breakpoint na linha
  - `break <file>:<line>`: define um breakpoint no arquivo na linha
  - `break *<address>`: define um breakpoint no endereço
- `run`: executa o programa
- `next`: executa a próxima linha
- `step`: executa a próxima linha e entra na função se houver
- `continue`: continua a execução do programa
- `print <variable>`: imprime o valor da variável
  - `print <variable>[<index>]`: imprime o valor da variável no índice
  - `print <variable>.<field>`: imprime o valor do campo da variável
  - `print <variable>-><field>`: imprime o valor do campo da variável
- `x`: imprime o conteúdo de uma região de memória
  - `x <number><type><format>`: imprime o conteúdo de uma região de memória
    - `<number>`: número de elementos a serem impressos
    - `<type>`: tipo dos elementos a serem impressos
      - `b`: byte
      - `h`: halfword
      - `w`: word
      - `g`: giantword
    - `<format>`: formato de impressão
      - `x`: hexadecimal
      - `d`: decimal
      - `u`: unsigned decimal
      - `o`: octal
      - `t`: binary
      - `f`: float
      - `a`: address
      - `c`: char
      - `s`: string
      - `i`: instruction
      - `z`: zero-terminated string
      - `Z`: zero-terminated wide string
      - `@`: dereference as address
- `disassemble`: desmonta o código
  - `disassemble <function>`: desmonta o código da função
  - `disassemble <line>`: desmonta o código da linha
  - `disassemble <file>:<line>`: desmonta o código do arquivo na linha
- `set`: define uma variável
  - `set $<register>=<value>`: define o valor do registrador
  - `set $<register>[<index>]=<value>`: define o valor do registrador no índice
  - `set $<register>.<field>=<value>`: define o valor do campo do registrador
  - `set $<register>-><field>=<value>`: define o valor do campo do registrador
  - `set $<register>-><field>[<index>]=<value>`: define o valor do campo do registrador no índice
- `help`: mostra a ajuda
  - `help <command>`: mostra a ajuda do comando

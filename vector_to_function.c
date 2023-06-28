/*======================================================

    Passando dados de vetores para funções. Exercício criptografia

    Autor: Gabriel Leonardo

    Linguagem C, o curso definitivo WR Kits

======================================================*/

/* Inclusão de bibliotecas*/
#include <stdio.h>
#include <stdlib.h>

/* Declaração das funções*/
int cripto (int bytes[], int i);
int descripto (int bytes[], int i);

main()
{
    int i, N;
    
    printf("Digite o número de bytes: ");
    scanf("%d", &N);
    
    int entrada[N], info_seg[N]; /* Após o tamanho definido, os vetores são criados. entrada armazena os bytes originais. info_seg armazenará os bytes criptografados*/

    printf("Entre com os bytes em hexadecimal (maiusculo).\n");

    for(i=0; i<N; i++)
    {
        printf("byte %d: ", i+1);
        scanf(" %X", &entrada[i]);
    }
    
    printf("O resultado criptografado é mostrado a seguir.\n");

    for(i=0; i<N; i++)
    {
        printf("byte %d: ", i+1);
        info_seg[i] = cripto(entrada, i);
        printf(" %X\n", info_seg[i]);

    }

    printf("O resultado descriptografado é mostrado a seguir.\n");

    for(i=0; i<N; i++)
    {
        printf("byte %d: ", i+1);
        printf(" %X \n", descripto(info_seg, i));
    }
} /*end main*/

/* Desenvolvimento das funções*/

int cripto (int bytes[], int i) /* Função criptografia, irá criptografar o elemento i do vetor passado como parâmetro*/
{
    if(!(bytes[i] % 2)) /* Caso elemento seja par, irá somar 5*/
        bytes[i] += 5;
    else
        bytes[i] -= 3; /* Caso elemento seja ímpar, irá subtrair 3*/

    return bytes[i]; /* retorna elemento criptografado */

}

int descripto (int bytes[], int i) /* Função descriptografia, irá descriptografar o elemento i do vetor passado como parâmetro*/
{
    if((bytes[i] % 2)) /* Caso elemento seja ímpar, irá subtrair 5. Observe que todo elemento par se tornou ímpar após a criptografia*/
        bytes[i] -= 5;
    else
        bytes[i] += 3; /* Caso elemento seja par, irá somar 3*/

    return bytes[i]; /* retorna elemento descriptografado */

}
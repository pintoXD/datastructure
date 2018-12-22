#include <stdio.h>

int main(void)
{
    //Este codigo gera um erro. E nao exibi o valor da variavel "ponteiroDoPonteiro".

    int *ponteiro, **ponteiroDoPonteiro, valor, valor2;

    valor = 50;

    valor2 = 666;

    ponteiro = &valor;

    ponteiroDoPonteiro = &ponteiro;

    printf("\nValor: %d\n", **ponteiroDoPonteiro);

    
    *ponteiroDoPonteiro;








    return 0;
}
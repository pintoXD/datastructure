#include <stdio.h>
#include <stdlib.h>
// #include <assert.h>
#include "ring_buffer.h"


struct circular_buf_t{
    uint8_t* buffer;
    size_t head;
    size_t tail;
    size_t max;
    bool full; //pode ser tirado numa versão lock_free
};

//Criação do buffer circular
cbuf_handle_t circular_buf_init(uint8_t* buffer, size_t size){

    assert(buffer && size);

    cbuf_handle_t cbuf = malloc(sizeof(circular_buf_t));

    assert(cbuf);

    cbuf->buffer = buffer;
    cbuf->max = size;

    circular_buf_reset(cbuf);

    assert(circular_buf_empty(cbuf));

    return cbuf;

}

//Inicialização dos valores do buffer
void circular_buf_reset(cbuf_handle_t cbuf){

    assert(cbuf);

    cbuf->head = 0;
    cbuf->tail = 0;
    cbuf->full = false;

    
}

//Destruição do buffer
void circular_buf_free(cbuf_handle_t cbuf){
    
    assert(cbuf);
    free(cbuf);
}

//Checa se o buffer tá cheio ou não (usado para thread safety)
bool circular_buf_full(cbuf_handle_t cbuf){

    assert(cbuf);

    return cbuf->full;
}

//Verfica se o buffer está vazio ou não. Necessário adaptar pra não usar
//a flag full.
bool circular_buf_empty(cbuf_handle_t cbuf){
    
    assert(cbuf);

    return (!cbuf->full && (cbuf->head == cbuf->tail));

}

//Retorna o tamanho máximo do buffer antes dele começar a querer sobrescrever
//algum dado importante.
size_t circular_buf_capacity(cbuf_handle_t cbuf){

    assert(cbuf);

    return cbuf->max;
}

//Função que calcula o tamanho atual(quantidade de itens) do buffer atualmente
size_t circular_buf_size(cbuf_handle_t cbuf){

    assert(cbuf);

    size_t size = cbuf->max;

    if(!cbuf->full){

        if(cbuf->head >= cbuf->tail){
            size = (cbuf->head - cbuf->tail);
        }
        else{
            size = (cbuf->max + cbuf->head - cbuf->tail);
        }

    }

    return size;
}

//Avança os ponteiros pra quando for preciso fazer uma
//inserção de dados no buffer.
static void advance_pointer(cbuf_handle_t cbuf){

    assert(cbuf);

    if(cbuf->full){
        cbuf->tail = (cbuf->tail + 1) % cbuf->max;
    }

    cbuf->head = (cbuf->head + 1) % cbuf->max;
    cbuf->full = (cbuf->head == cbuf->tail);

    /* Ou pode ser feito como abaixo. O custo computacional é menor
    e ainda é mais elegante:
        assert(cbuf);

        if(cbuf->full)
        {
            if (++(cbuf->tail) == cbuf->max) 
            { 
                cbuf->tail = 0;
            }
        }

        if (++(cbuf->head) == cbuf->max) 
        { 
            cbuf->head = 0;
        }
        cbuf->full = (cbuf->head == cbuf->tail);
        
    */
}

//Função pra quando é tirado algum valor do buffer.
//Atualiza o ponteiro de tail.
static void retreat_pointer(cbuf_handle_t cbuf)
{

    assert(cbuf);
    cbuf->full = false;
    //Se tail for igual ao tamanho do buffer, quer dizer
    //que ele passou foi do final do vetor e precisar voltar
    //pro começo dele, pra criar a caraterística de circularidade.
    if(++(cbuf->tail) == cbuf->max)
        cbuf->tail = 0;

}


//Coloca item no buffer circular. Se o buffer tiver cheio,
//sobrescreve o primeiro item da fila.
void circular_buf_put(cbuf_handle_t cbuf, uint8_t data)
{
    assert(cbuf && cbuf->buffer);

    cbuf->buffer[cbuf->head] = data;

    advance_pointer(cbuf);

}

int circular_buf_get(cbuf_handle_t cbuf, uint8_t* data)
{
    assert(cbuf && data && cbuf->buffer);

    int r = -1;

    if(!circular_buf_empty(cbuf)){

        *data = cbuf->buffer[cbuf->tail];

        r = 0;

    }

    retreat_pointer(cbuf);

    return r;

}





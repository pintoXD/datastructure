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


void circular_buf_reset(cbuf_handle_t cbuf){
    
}








#include <assert.h>
#include <stddef.h>
#include <stdio.h>

#include "../src/mempool.h"

int main(void)
{
    mp_pool_t pool;
    size_t block_size = 4096, block_count = 10;
    puts("[initializing memory pool]\n");
    assert(mp_init(block_size, block_count, &pool) == 0);

    puts("[allocating blocks from memory pool]\n");
    char *block;
    for(size_t i = 0; i < block_count; i++) {
        printf("\t[block: %i]\n", i);
        block = (char *) mp_malloc(&pool);
        if(!block) {
            printf("error value: %d\n", mp_error);
        }
        //assert(block);
    }

    puts("[destroying memory pool]\n");
    mp_destroy(&pool);

    return 0;
}
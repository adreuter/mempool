#include <stddef.h>
#include <stdlib.h>

#include "mempool.h"

mp_error_t mp_error;

int mp_init(size_t block_size, size_t block_count, mp_pool_t *pool)
{
    if(!pool) {
        mp_error = MP_POOL_POINTER_NULL;
        return -1;
    }

    if(block_size < sizeof(size_t)) {
        mp_error = MP_INVALID_BLOCKSIZE;
        return -1;
    }

    // initialization of the pool
    pool->block_size = block_size;
    pool->block_count = block_count;
    pool->pool_ptr = malloc(block_size * block_count);
    if(!pool->pool_ptr) {
        mp_error = MP_MALLOC_ERROR;
        return -1;
    }

    // initialization of the list storing the free blocks
    pool->block_ptr = pool->pool_ptr;
    if(block_count == 0)
        return 0;
    
    union block {
        union block *next_block;
        char block_data[block_size];
    } *curr_block = (union block *) pool->block_ptr;

    for(size_t i = 0; i < block_count - 1; i++)
        curr_block->next_block = ++curr_block;
    curr_block->next_block = NULL;

    return 0;
}

void *mp_malloc(mp_pool_t *pool)
{
    if(!pool) {
        mp_error = MP_POOL_POINTER_NULL;
        return NULL;
    }

    if(!pool->block_ptr) {
        mp_error = MP_OUT_OF_MEMORY;
        return NULL;
    }

    union block {
        union block *next_block;
        char block_data[pool->block_size];
    } *curr_block = (union block *) pool->block_ptr;

    pool->block_ptr = (void *) curr_block->next_block;

    return (void *) curr_block;
}

int mp_free(mp_pool_t *pool, void *block)
{
    if(!pool) {
        mp_error = MP_POOL_POINTER_NULL;
        return -1;
    }

    if(!block) {
        mp_error = MP_BLOCK_POINTER_NULL;
        return -1;
    }

    union block {
        union block *next_block;
        char block_data[pool->block_size];
    } *curr_block = (union block *) block;

    curr_block->next_block = (union block *) pool->block_ptr;
    pool->block_ptr = (void *) curr_block;

    return 0;
}

int mp_destroy(mp_pool_t *pool)
{
    if(!pool) {
        mp_error = MP_POOL_POINTER_NULL;
        return -1;
    }

    free(pool->pool_ptr);

    return 0;
}

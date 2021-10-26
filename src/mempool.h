#ifndef MEMPOOL_H
#define MEMPOOL_H

#include <stddef.h> /* size_t */

struct mp_data {
    size_t block_size, block_count;
    void *pool_ptr, *block_ptr;
};

enum mp_error {
    MP_OUT_OF_MEMORY,
    MP_POOL_POINTER_NULL,
    MP_BLOCK_POINTER_NULL,
    MP_INVALID_BLOCKSIZE,
    MP_MALLOC_ERROR
};

typedef struct mp_data mp_pool_t;
typedef enum mp_error mp_error_t;

int mp_init(size_t block_size, size_t block_count, mp_pool_t *pool);
void *mp_malloc(mp_pool_t *pool);
int mp_free(mp_pool_t *pool, void *block);
int mp_destroy(mp_pool_t *pool);

extern mp_error_t mp_error;

#endif /* MEMPOOL_H */
#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "../src/mempool.h"

int main(void)
{
    size_t bc = 10;
    size_t bs = 8;
    mp_pool_t mp;
    void *m = malloc(bc * bs);
    assert(m);
    // initialize mp
    mp_init(bs, bc, m, &mp);
    
    for(int i = 0; i < 10; i++) {
        int *b = (int *) mp_malloc(&mp);
        assert(b);
        *b = i;
        mp_free(&mp, (void *) b);
    }

    for(int i = 10; i > 0; i--) {
        int *b = (int *) mp_malloc(&mp);
        assert(b);
        *b = i;
    }
    assert(!mp_malloc(&mp));
    assert(mp_error == MP_OUT_OF_MEMORY);

    free(m);
    return 0;
}
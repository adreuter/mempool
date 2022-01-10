# mempool
## Description
mempool is a tiny static C-library providing a minimal and efficient implementation of a memory pool. For more information on memory pool based allocation see [this Wikipedia Page](https://en.wikipedia.org/wiki/Memory_pool)
## Usage
```C
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "mempool.h"

int main(void)
{
    size_t bc = 8;    // block count
    size_t bs = 512;  // block size
    mp_pool_t mp;

    // first we need to allocate the pool memory on the heap
    void *m = malloc(bc * bs);
    if(!m) {
        return -1;
    }

    // initialize mp
    mp_init(bs, bc, m, &mp);

    // now we can request blocks from the pool using mp_malloc
    // and free blocks using mp_free

    // free the pool's memory after we don't need it anymore
    free(m);
    return 0;
}
```
## Documentation
### Types
```C
mp_pool_t
```
This type represents the memory pool.
### Functions
```C
int mp_init(size_t bs, size_t bc, void *m, mp_pool_t *mp)
```
Initializes the memory pool given blocksize `bs`, blockcount `bc` and a pointer `m` to a piece of memory of minimum size `bc * bs`. `bs` is required to be at least `sizeof(size_t)`. Otherwise it returns `-1`. Guaranteed to run in constant time.
```C
void *mp_malloc(mp_pool_t *mp)
```
Returns a pointer to a free block in the memory pool. If no free blocks are left it will return `NULL`. Guaranteed to run in constant time.
```C
void mp_free(mp_pool_t *mp, void *b)
```
Adds b to the list of free blocks. Guaranteed to run in constant time.
## Dependencies
stddef.h
## License
MIT License

Copyright (c) 2021 Adrian Reuter

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
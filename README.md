# mempool
## Description
mempool is a tiny static C-library providing a minimal and efficient implementation of a memory pool. For more information on memory pool based allocation see [this Wikipedia Page](https://en.wikipedia.org/wiki/Memory_pool)
## Usage
See test/test.c
## Documentation
### Types
#### mp_pool_t
This type represents the memory pool.
#### mp_error_t
A value of this type can be
- MP_INVALID_BLOCKSIZE
- MP_OUT_OF_MEMORY
### Functions
#### int mp_init(size_t bs, size_t bc, void *m, mp_pool_t *mp);
Initializes the memory pool given blocksize bs, blockcount bc and a pointer m to a piece of memory of size bc * bs. bs is required to be at least sizeof(size_t). Otherwise it sets mp_error to MP_INVALID_BLOCKSIZE and returns -1. Guaranteed to run in constant time.
#### void *mp_malloc(mp_pool_t *mp);
Returns a pointer to a free block in the memory pool. If no free blocks are left it will set mp_error to MP_OUT_OF_MEMORY and return NULL. Guaranteed to run in constant time.
#### void mp_free(mp_pool_t *mp, void *b);
Adds b to the list of free blocks.
### Variables
#### mp_error_t mp_error
Global error variable used for error handling in case any library function exits abnormally.
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
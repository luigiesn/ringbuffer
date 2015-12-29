#ringbuffer

This is a simply ring buffer.

The main characteristics and objectives of this buffer are:

- 8x8bits
- Optimized for 8 bits uP
- Can be filled with up to 254 elements (255 - 1)
- 8 bits elements
  
##Coming Soon:

- A function that returns reservable size in the buffer and pointer for the first location of this vector.

    `unsigned char ringbufferReserve(ringbuffer_t rb, unsigned char** v)`

- A function that confirms previously reserved space. Suggested prototype:

    `bool ringbufferAddReserved(ringbuffer_t rb, unsigned char size)`



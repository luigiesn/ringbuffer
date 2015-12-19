#ringbuffer

This is a simply ring buffer.

The main characteristics and objectives of this buffer are:

- Optimized for 8 bits uP
- Can be filled with up to 254 elements (255 - 1)
- 8 bits elements

What this code doesn't do:

- Verify if can store or remove elements without buffer corruption. These verifications are user responsibilty. Made in this way to make it faster.
  
TODOs:

- Make a function that returns reservable size in the buffer and pointer for the first location of this vector. Suggested prototype: 

    `unsigned char ringbufferReserve(ringbuffer_t rb, unsigned char** v)`

- Make a function that confirms previously reserved space. Suggested prototype:

    `bool ringbufferAddReserved(ringbuffer_t rb, unsigned char size)`


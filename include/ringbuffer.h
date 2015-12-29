/*
 * Ring buffer - Optimized for 8 bits uP
 * Copyright (C) 2015 - Luigi E. Sica Nery
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of  MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 */
 
 /*
  * ----------------------------------
  * V 1.0 - Release
  * 	Dec 14, 2015 
  * ----------------------------------
  * V 1.1 - Added ringbufferCount() 
  * 	Dec 27, 2015 
  * ----------------------------------
  */

#ifndef _RINGBUFFER_H_
#define _RINGBUFFER_H_

typedef struct ringbuffer ringbuffer_t; ///< @typedef Ring buffer type definition

struct ringbuffer {
    unsigned char* buffer; ///<Points to a char vector
    unsigned char size; ///<Ring buffer size
    unsigned char start; ///<Ring buffer start pointer
    unsigned char end; ///<Ring buffer end pointer
};

/**
 * @brief Initialize a previously created ring buffer
 *
 * Assing a vector and size to a ring buffer and empty the buffer
 *
 * @param rb Ring buffer pointer
 * @param buffer Pointer to a char vector to compose the ring buffer
 * @param size Size of ring buffer
 *
 *  @warning Actually, the final buffer capacity is size minus 1
 */
void ringbufferInit(ringbuffer_t* ringbuffer, unsigned char* buffer, unsigned char size);

/**
 * @brief Add a byte to the ring buffer
 *
 * @param rb Ring buffer pointer
 * @param buffer Char vector to add to ring buffer
 * @param size Size of the new data added
 *
 * @warning It do not verifies if there is free space on ring buffer before add
 */
void ringbufferAdd(ringbuffer_t* rb, unsigned char* buffer, unsigned char size);

/**
 * @brief Remove a byte to the ring buffer
 *
 * @param rb Ring buffer pointer
 * @param size Size of the data to be removed
 *
 * @warning It do not verifies if there data on ring buffer before remove
 */
void ringbufferRemove(ringbuffer_t* rb, unsigned char size);

/**
 * @brief Calculate free space on ring buffer
 *
 * @param rb Ring buffer pointer
 *
 * @return Total free space in ring buffer
 */
unsigned char ringbufferFree(ringbuffer_t* rb);

/**
 * @brief Verify if buffer is empty
 *
 * @param rbb Ring buffer pointer
 *
 * @return Returns "1" if buffer is empty, "0" if not
 */
unsigned char ringbufferEmpty(ringbuffer_t* rb);

/**
 * @brief Get count of elements in the buffer
 *  
 * Returns data amount on ring buffer
 *
 * @param rb Ring buffer pointer
 *
 * @return Number of elements in ring buffer vector
 */
unsigned char ringbufferCount(ringbuffer_t* rb);

/**
 * @brief Get elements on ring buffer
 *  
 * Get by reference the start pointer and returns data amount on ring buffer can be read
 *
 * @param rb Ring buffer pointer
 * @param buffer Pointer to buffer
 *
 * @return Number of elements up to the last position in ring buffer vector
 *
 * @warning A new verification on buffered data should be performed to check if all data has been read
 */
unsigned char ringbufferGetElements(ringbuffer_t* rb, unsigned char** buffer);

#endif // _RINGBUFFER_H_

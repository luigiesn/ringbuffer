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

#include "../include/ringbuffer.h"

void ringbufferInit(ringbuffer_t* rb, unsigned char* buffer, unsigned char size) {
    rb->buffer = buffer;
    rb->size = size;
    rb->start = 0;
    rb->end = 0;
}

void ringbufferAdd(ringbuffer_t* rb, unsigned char* buffer, unsigned char size){
    unsigned char i;

    for(i = 0 ; i < size ; i++){

        rb->buffer[rb->end] = buffer[i];

        rb->end = rb->end + 1;

        if(rb->end >= rb->size){
            rb->end = 0;
        }
    }
}

void ringbufferRemove(ringbuffer_t* rb, unsigned char size){
    rb->start += size;
    if(rb->start >= rb->size){
        rb->start = 0;
    }
}

unsigned char ringbufferFree(ringbuffer_t* rb){
    unsigned char free;

    if(rb->end >= rb->start)
        free = rb->size - rb->end + rb->start - 1;
    else{
        free = rb->start - rb->end - 1;
    }
    return free;
}

unsigned char ringbufferEmpty(ringbuffer_t* rb){
    if(rb->start == rb->end)
        return 1;
    
    return 0;
}

unsigned char ringbufferCount(ringbuffer_t* rb){
    unsigned char cnt;

    if(rb->end >= rb->start){
        cnt = rb->end - rb->start + 1;
    }
    else{
        cnt = rb->size - rb->start;
    }
	
    return cnt;
}

unsigned char ringbufferGetElements(ringbuffer_t* rb, unsigned char** buffer){
    unsigned char num;

    if(rb->end >= rb->start){
        num = rb->end - rb->start + 1;
    }
    else{
        num = rb->size - rb->start;
    }

    *buffer = rb->buffer + rb->start;

    return num;
}


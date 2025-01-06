#ifndef cwillem_chunk_h
#define cwillem_chunk_h

#include "common.h"
#include "value.h"
#include <stdint.h>


typedef enum {
    OP_CONSTANT,
    OP_RETURN,
} OpCode;

typedef struct {
    int count;
    int capacity;
    uint8_t *code;
    int *lines;
    ValueArray constants;
} Chunk;

void initChunk(Chunk *chunk);
void writeChunk(Chunk *chunk, uint8_t byte, int line);
int addConstant(Chunk *chunk, Value value);
void freeChunk(Chunk *chunk);

#endif

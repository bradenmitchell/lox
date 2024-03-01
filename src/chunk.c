#include <stdlib.h>

#include "chunk.h"
#include "memory.h"

void initChunk(Chunk* chunk) {
  chunk->capacity = 0;
  chunk->count    = 0;
  chunk->code     = NULL;
  chunk->lines    = NULL;
  initValueArray(&chunk->constants);
}

void freeChunk(Chunk* chunk) {
  FREE_ARRAY(uint8_t, chunk->code, chunk->capacity);  // Free internal 'code' array
  FREE_ARRAY(int, chunk->lines, chunk->capacity);     // Free internal 'lines' array
  freeValueArray(&chunk->constants);                  // Free internal 'constants' array
  initChunk(chunk);
}

void writeChunk(Chunk* chunk, uint8_t byte, int line) {
  // Test if chunk has capacity for new byte
  if (chunk->capacity < chunk->count + 1) {
    // Capacity insufficient, increase capacity
    int oldCapacity = chunk->capacity;
    chunk->capacity = GROW_CAPACITY(oldCapacity);
    chunk->code     = GROW_ARRAY(uint8_t, chunk->code, oldCapacity, chunk->capacity);
    chunk->lines    = GROW_ARRAY(int, chunk->lines, oldCapacity, chunk->capacity);
  }

  chunk->code[chunk->count]  = byte;
  chunk->lines[chunk->count] = line;
  chunk->count++;
}

int addConstant(Chunk* chunk, Value value) {
  writeValueArray(&chunk->constants, value);
  return chunk->constants.count - 1;  // Return index of value in constants array
}

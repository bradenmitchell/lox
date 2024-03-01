#ifndef _vm_h
#define _vm_h

#include "chunk.h"
#include "value.h"

#define STACK_MAX 256

typedef struct VM {
  Chunk* chunk;
  uint8_t* ip;  // Instruction pointer: points to next instruction to be executed
  Value stack[STACK_MAX];
  Value* stackTop;
} VM;

typedef enum InterpretResult {
  INTERPRET_OK,
  INTERPRET_COMPILE_ERROR,
  INTERPRET_RUNTIME_ERROR,
} InterpretResult;

void initVM(void);
void freeVM(void);

InterpretResult interpret(const char* source);

void push(Value value);
Value pop(void);

#endif  // _vm_h

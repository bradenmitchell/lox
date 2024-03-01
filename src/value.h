#ifndef _value_h
#define _value_h

#include "common.h"

typedef double Value;

typedef struct ValueArray {
  int capacity;
  int count;
  Value* values;
} ValueArray;

void initValueArray(ValueArray* array);
void freeValueArray(ValueArray* array);
void writeValueArray(ValueArray* array, Value value);

void printValue(Value value);

#endif  // _value_h

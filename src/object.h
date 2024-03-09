#ifndef _object_h
#define _object_h

#include "chunk.h"
#include "common.h"
#include "value.h"

// Extracts object type from value
#define OBJ_TYPE(value) (AS_OBJ(value)->type)

// Type guards
#define IS_FUNCTION(value) isObjType(value, OBJ_FUNCTION)
#define IS_NATIVE(value)   isObjType(value, OBJ_NATIVE)
#define IS_STRING(value)   isObjType(value, OBJ_STRING)

// Convert Lox value to C value
#define AS_FUNCTION(value) ((ObjFunction*)AS_OBJ(value))
#define AS_NATIVE(value)   (((ObjNative*)AS_OBJ(value))->function)  // Extracts C function pointer
#define AS_STRING(value)   ((ObjString*)AS_OBJ(value))              // Returns ObJString* pointer
#define AS_CSTRING(value)  (((ObjString*)AS_OBJ(value))->chars)     // Returns char* of ObjString

typedef enum ObjType {
  OBJ_FUNCTION,
  OBJ_NATIVE,
  OBJ_STRING,
} ObjType;

struct Obj {
  ObjType type;
  struct Obj* next;
};

typedef struct ObjFunction {
  Obj obj;
  int arity;
  Chunk chunk;
  ObjString* name;
} ObjFunction;

typedef Value (*NativeFn)(int argCount, Value* args);

typedef struct ObjNative {
  Obj obj;
  NativeFn function;
} ObjNative;

struct ObjString {
  Obj obj;
  int length;
  char* chars;
  uint32_t hash;
};

ObjFunction* newFunction(void);

ObjNative* newNative(NativeFn function);

ObjString* takeString(char* chars, int length);
ObjString* copyString(const char* chars, int length);

void printObject(Value value);

static inline bool isObjType(Value value, ObjType type) {
  return IS_OBJ(value) && AS_OBJ(value)->type == type;
}

#endif  // _object_h

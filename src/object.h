#ifndef _object_h
#define _object_h

#include "common.h"
#include "value.h"

// Extracts object type from value
#define OBJ_TYPE(value) (AS_OBJ(value)->type)

// Type guards
#define IS_STRING(value) isObjType(value, OBJ_STRING)

// Convert Lox value to C value
#define AS_STRING(value)  ((ObjString*)AS_OBJ(value))           // Returns ObJString* pointer
#define AS_CSTRING(value) (((ObjString*)AS_OBJ(value))->chars)  // Returns char* of ObjString

typedef enum ObjType {
  OBJ_STRING,
} ObjType;

struct Obj {
  ObjType type;
  struct Obj* next;
};

struct ObjString {
  Obj obj;
  int length;
  char* chars;
};

ObjString* takeString(char* chars, int length);
ObjString* copyString(const char* chars, int length);

void printObject(Value value);

static inline bool isObjType(Value value, ObjType type) {
  return IS_OBJ(value) && AS_OBJ(value)->type == type;
}

#endif  // _object_h

#ifndef _compiler_h
#define _compiler_h

#include "object.h"
#include "vm.h"

ObjFunction* compile(const char* source);

#endif  // _compiler_h

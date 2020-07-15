#ifndef clox_vm_h
#define clox_vm_h

#include "object.h"
#include "table.h"
#include "value.h"

#define FRAME_MAX 64
#define STACK_MAX (FRAME_MAX * UINT8_COUNT)

typedef struct {
  ObjClosure* closure;
  uint8_t* ip;
  Value* slots;
} CallFrame;

typedef struct {
  CallFrame frames[FRAME_MAX];
  int frameCount;

  Value stack[STACK_MAX];
  Value* stackTop;
  Table globals;
  Table strings;
  ObjUpvalue* openUpvalues;

  Obj* objects;
  int grayCount;
  int grayCapacity;
  Obj** grayStack;
} VM;

typedef enum {
  INTERPRET_OK,
  INTERPRET_COMPILE_ERROR,
  INTERPRET_RUNTIME_ERROR
} InterpretResult;

extern VM vm;

void initVM();
void freeVM();
InterpretResult interpret(const char* source);
void push(Value value);
Value pop();

#endif

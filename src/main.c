#include "chunk.h"
#include "common.h"
#include "debug.h"
#include "vm.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  initVM();

  Chunk chunk;
  initChunk(&chunk);

  int offset = addConstant(&chunk, 1.2);
  writeChunk(&chunk, OP_CONSTANT, 123);
  writeChunk(&chunk, offset, 123);
  writeChunk(&chunk, OP_RETURN, 123);

  // disassembleChunk(&chunk, "test chunk");

  InterpretResult result = interpret(&chunk);
  if (result == INTERPRET_COMPILE_ERROR) {
    printf("Compile error.\n");
  } else if (result == INTERPRET_RUNTIME_ERROR) {
    printf("Runtime error.\n");
  } else if (result == INTERPRET_OK) {
    printf("OK.\n");
  }

  freeVM();
  freeChunk(&chunk);

  return 0;
}

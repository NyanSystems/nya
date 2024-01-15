//
// Created by Sokhibjon Orzikulov on 15/01/24.
//

#include "../includes/compiler.h"

int compile_file(const char* filename, const char* out_filename, int flags)
{
  struct compiler_process* process = compile_process_create(filename, out_filename, flags);

  if (!process)
    return COMPILER_FAILED_WITH_ERRORS;

  // TODO: Leksik analiz qilish kerak bu yerda

  // TODO: Parsing qilish kerak bu yerda

  // TODO: Code generatsiya qilish kerak bu yerda

  return COMPILER_FILE_COMPILED_OK;
}


//
// Created by Sokhibjon Orzikulov on 15/01/24.
//

#ifndef NYA_COMPILER_H
#define NYA_COMPILER_H

#include <stdio.h>

enum { COMPILER_FILE_COMPILED_OK, COMPILER_FAILED_WITH_ERRORS };

struct compile_process {
  // Fayllar qanday kompilyatsiya bo'lishi kerakligi haqidagi ko'rsatmalar
  int flags;

  struct compiler_process_input_file {
    FILE *fp;
    const char *abs_path;
  } cfile;

  FILE *ofile;
};

int compile_file(const char *filename, const char *out_filename, int flags);

struct compile_process *compile_process_create(const char *filename,
                                               const char *filename_out,
                                               int flags);

#endif // NYA_CPROCESS_H
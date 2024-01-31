//
// Created by Sokhibjon Orzikulov on 15/01/24.
//

#ifndef NYA_COMPILER_H
#define NYA_COMPILER_H

#include "buffer.h"
#include <stdbool.h>
#include <stdio.h>

struct pos {
  int line;
  int col;
  const char *filename;
};

enum {
  TOKEN_TYPE_IDENTIFIER,
  TOKEN_TYPE_KEYWORD,
  TOKEN_TYEP_OPERATOR,
  TOKEN_TYEP_SYMBOL,
  TOKEN_TYPE_NUMBER,
  TOKEN_TYPE_STRING,
  TOKEN_TYPE_COMMENT,
  TOKEN_TYPE_NEWLINE,
};

struct token {
  int type;
  int flags;

  union {
    char cval;
    const char *sval;
    unsigned int inum;
    unsigned long lnum;
    unsigned long long llnum;
    void *any;
  };

  // "true" agar tokenlar orasida bo'sh joy bo'lsa
  bool whitespace;

  // (Salom Dunyo)
  const char *between_brackets;
};

struct lex_process;

typedef char (*LEX_PROCESS_NEXT_CHAR)(struct lex_process *process);
typedef char (*LEX_PROCESS_PEEK_CHAR)(struct lex_process *process);
typedef void (*LEX_PROCESS_PUSH_CHAR)(struct lex_process process, char c);

struct lex_process_functions {
  LEX_PROCESS_NEXT_CHAR next_char;
  LEX_PROCESS_PEEK_CHAR peek_char;
  LEX_PROCESS_PUSH_CHAR push_char;
};

struct lex_process {
  struct pos pos;
  struct vector *token_vec;
  struct compile_process *compiler;

  /**
   * Nechta qavs bor
   * ((50))
   */
  int current_expression_count;
  struct buffer *parentheses_buffer;
  struct lex_process_functions *function;

  // Lekser tushunmagan maxvfiy ma'lumotlar
  // Lekin lekser ishlatayotgan inson tushunadi
  void *private;
};

enum { COMPILER_FILE_COMPILED_OK, COMPILER_FAILED_WITH_ERRORS };

struct compile_process {
  // Fayllar qanday kompilyatsiya bo'lishi kerakligi haqidagi ko'rsatmalar
  int flags;

  struct pos pos;
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

// Umumman biz tomondan implementatsiya qilingan qadamlar
char compile_process_next_char(struct lex_process *lex_process);
char compile_process_peek_char(struct lex_process *lex_process);
void compile_process_push_char(struct lex_process *lex_process, char c);

// Lekser
struct lex_process *lex_process_create(struct compile_process *compiler,
                                       struct lex_process_functions *functions,
                                       void *private);
void lex_process_free(struct lex_process *process);
void *lex_process_private(struct lex_process *process);
struct vector *lex_process_tokens(struct lex_process *process);

#endif // NYA_COMPILER_H

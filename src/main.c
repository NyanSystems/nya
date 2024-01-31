//
// Created by Sokhibjon Orzikulov on 15/01/24.
//

#include <stdio.h>

#include "../include/compiler.h"

int main()
{
  int res = compile_file("./test/test.c", "./test/test", 0);

  if (res == COMPILER_FILE_COMPILED_OK) {
    printf("Hamma narsa muvaffaqiyatli kompilyatsiya qilindi\n");
  }
  else if (res == COMPILER_FAILED_WITH_ERRORS) {
    printf("Kompilyatsiyada xatolik yuz berdi\n");
  }
  else {
    printf("Kompilyatsion fayl uchun noma'lum javob qaytarildi\n");
  }

  return 0;
}

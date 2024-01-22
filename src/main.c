//
// Created by Sokhibjon Orzikulov on 15/01/24.
//

#include <stdio.h>

#include "../helpers/vector.h"
#include "../includes/compiler.h"

int main()
{
  // ==============================================
  // Vektorlarni sinab ko'rish uchun yozilgan kod
  // ==============================================
  struct vector *vec = vector_create(sizeof(int));

  int x = 50;
  vector_push(vec, &x);
  x = 20;
  vector_push(vec, &x);

  vector_pop(vec);

  vector_set_peek_pointer(vec, 0);
  int *ptr = vector_peek(vec);

  while (ptr) {
    printf("%i\n", *ptr);
    ptr = vector_peek(vec);
  }
  // ==============================================

  int res = compile_file("./test/simple.c", "./test/simple", 0);

  if (res == COMPILER_FILE_COMPILED_OK) {
    printf("Hamma narsa muvaffaqiyatli kompilyatsiya qilindi\n");
  }
  else if (res == COMPILER_FAILED_WITH_ERRORS) {
    printf("Kompilyatsiyada xatolik yuz berdi\n");
  }
  else {
    printf("Kompilyatsion fayl uchun noma'lum javob qaytarildi\n");
  }

  printf("Salom Dunyo!\n");
  return 0;
}

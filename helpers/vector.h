//
// Created by Sokhibjon Orzikulov on 15/01/24.
//

/**
 * @file vector.h
 * 
 * @brief A vector implementation in C
 * @brief C da vektor implementatsiyasi
 * 
 * @author Sokhibjon Orzikulov
 * @license MIT
 */

#ifndef VECTOR_H
#define VECTOR_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * We want at least 20 vector element spaces in reserve before having
 * to reallocate memory again
 * Xotirani qayta alokatsiya qilishdan oldin kamida 20 vektor element
 * joyi bo'lishini istaymiz
 */
#define VECTOR_ELEMENT_INCREMENT 20

/**
 * The vector flag that tells the vector to decrement the peek pointer
 * when peeking
 * Peek qilishda peek pointer ni kamaytirish uchun vektor bayrog'i
 */
enum { VECTOR_FLAG_PEEK_DECREMENT = 0b00000001 };

/**
 * The vector struct.
 * Vektor structi.
 */
struct vector {
  /**
   * The data pointer is the pointer to the data that this vector holds
   * Data pointer bu ushbu vektorning egallagan ma'lumotlarning manzili
   */
  void *data;
  
  /**
   * The pointer index is the index that will be read next upon calling
   * "vector_peek". This index will then be incremented. Pointer indeksi
   * "vector_peek" chaqirilganda keyingi o'qiladigan indeks bo'ladi. Keyingi
   * o'qiladigan indeks keyingi o'qiladigan indeks bo'ladi.
   */
  int pindex;
  int rindex;
  int mindex;
  int count;
  int flags;
  size_t esize;
  
  /**
   * Vector of struct vector, holds saves of this vector. YOu can save the
   * internal state at all times with vector_save Data is not restored and is
   * permenant, save does not respect data, only pointers and variables are
   * saved. Useful to temporarily push the vector state and restore it later.
   */
  struct vector *saves;
};

/**
 * Creates a new vector with the given element size
 * Berilgan element hajmi bilan yangi vektor yaratadi
 * 
 * \param esize The element size of the vector
 * \return Returns a new vector
 * 
 * \param esize Vektor element hajmi
 * \return Yangi vektor qaytaradi
 */
struct vector *vector_create(size_t esize);

/**
 * Frees the vector
 * Vektorni bo'shatadi
 * 
 * \param vector The vector to free
 * 
 * \param vector Bo'shatish uchun vektor
 */
void vector_free(struct vector *vector);

/**
 * Returns the element at the given index
 * Berilgan indeksdagi elementni qaytaradi
 * 
 * \param vector The vector to get the element of
 * \param index The index to get the element at
 * \return Returns the element at the given index
 * 
 * \param vector Elementni olish uchun vektor
 * \param index Elementni olish uchun indeks
 * \return Berilgan indeksdagi elementni qaytaradi
 */
void *vector_at(struct vector *vector, int index);

/**
 * Returns the peek element at the given index
 * Berilgan indeksdagi peek elementni qaytaradi
 * 
 * \param vector The vector to get the element of
 * \param index The index to get the element at
 * \return Returns the element at the given index
 * 
 * \param vector Elementni olish uchun vektor
 * \param index Elementni olish uchun indeks
 * \return Berilgan indeksdagi elementni qaytaradi
 */
void *vector_peek_ptr_at(struct vector *vector, int index);

/**
 * Returns 
*/
void *vector_peek_no_increment(struct vector *vector);
void *vector_peek(struct vector *vector);
void *vector_peek_at(struct vector *vector, int index);
void vector_set_flag(struct vector *vector, int flag);
void vector_unset_flag(struct vector *vector, int flag);

/**
 * Pops off the last peeked element
 * Oxirgi peek qilingan elementni olib tashlaydi
 * 
 * \param vector The vector to pop the last peeked element off of
 * 
 * \param vector Oxirgi peek qilingan elementni olib tashlash uchun vektor
 */
void vector_pop_last_peek(struct vector *vector);

/**
 * Peeks into the vector of pointers, returning the pointer value its self
 * Use this function instead of vector_peek if this is a vector of pointers
 * Pointerlarni o'qib, o'zini qaytaradi. Agar bu pointerlar vektori bo'lsa,
 * Ushbu funksiyadan vector_peek foydalaning
 * 
 * \param vector The vector to peek into
 * 
 * \param vector Peek qilish uchun vektor
 */
void *vector_peek_ptr(struct vector *vector);

/**
 * Peeks into the vector of pointers, returning the pointer value its self
 * Use this function instead of vector_peek if this is a vector of pointers
 * Pointerlarni o'qib, o'zini qaytaradi. Agar bu pointerlar vektori bo'lsa,
 * Ushbu funksiyadan vector_peek foydalaning
 * 
 * \param vector The vector to peek into
 * \param index The index to peek at
 * 
 * \param vector Peek qilish uchun vektor
 * \param index Peek qilish uchun indeks
 */
void vector_set_peek_pointer(struct vector *vector, int index);

/**
 * Peeks into the vector of pointers, returning the last pointer value its self
 * Vektorning pointerlariga peek qilib, oxirgi pointer qiymatini o'zini qaytaradi
 * 
 * \param vector The vector to peek into
 * 
 * \param vector Peek qilish uchun vektor
 */
void vector_set_peek_pointer_end(struct vector *vector);

/**
  * Pushes the given value to the vector
  * Berilgan qiymatni vektorga qo'shadi
  * 
  * \param vector The vector to push the value to
  * \param elem The value to push to the vector
  * 
  * \param vector Qiymatni qo'shish uchun vektor
  * \param elem Vektorga qo'shish uchun qiymat
  */
void vector_push(struct vector *vector, void *elem);

/**
 * Pushes the given value to the vector at the given index
 * Berilgan qiymatni vektorga berilgan indeksda qo'shadi 
 * 
 * \param vector The vector to push the value to
 * \param index The index to push the value at
 * \param ptr The value to push to the vector
 * 
 * \param vector Qiymatni qo'shish uchun vektor
 * \param index Qiymatni qo'shish uchun indeks
 * \param ptr Vektorga qo'shish uchun qiymat
 */
void vector_push_at(struct vector *vector, int index, void *ptr);

/**
 * Pop the given value from the vector
 * Vektordan berilgan qiymatni olib tashlaydi
 * 
 * \param vector The vector to pop the value from
 * 
 * \param vector Qiymatni olib tashlash uchun vektor
 */
void vector_pop(struct vector *vector);

/**
 * Pops the last element off the vector
 * Vektordan oxirgi elementni olib tashlaydi
 * 
 * \param vector The vector to pop the last element off of
 * 
 * \param vector Oxirgi elementni olib tashlash uchun vektor
 */
void vector_peek_pop(struct vector *vector);

/**
 * Returns the back pointer of the vector
 * Vektorning orqa pointerini qaytaradi
 * 
 * \param vector The vector to get the back pointer of
 * 
 * \param vector Orqa pointerini olish uchun vektor
 */
void *vector_back(struct vector *vector);

/**
 * Returns the back pointer of the vector or null if the vector is empty
 * Vektorning orqa pointerini qaytaradi yoki vektor bo'sh bo'lsa null
 * 
 * \param vector The vector to get the back pointer of
 * 
 * \param vector Orqa pointerini olish uchun vektor
 */
void *vector_back_or_null(struct vector *vector);

/**
 * Returns the back pointer of the vector
 * Vektorning orqa pointerini qaytaradi
 * 
 * \param vector The vector to get the back pointer of
 * 
 * \param vector Orqa pointerini olish uchun vektor
 */
void *vector_back_ptr(struct vector *vector);

/**
 * Returns the back pointer of the vector or null if the vector is empty
 * Vektorning orqa pointerini qaytaradi yoki vektor bo'sh bo'lsa null
 * 
 * \param vector The vector to get the back pointer of
 * 
 * \param vector Orqa pointerini olish uchun vektor
 */
void *vector_back_ptr_or_null(struct vector *vector);

/**
 * Returns the vector data as a char pointer
 * Vektor ma'lumotlarini char pointer sifatida qaytaradi
 *
 * \param vec The vector to get the data of
 * \return Returns the data of the vector
 *
 * \param vec Ma'lumotlarini olish uchun vektor
 * \return Vektor ma'lumotlarini qaytaradi
 */
const char *vector_string(struct vector *vec);

/**
 * Check if the vector is empty
 * Vektorni bo'shligini tekshirish
 *
 * \param vector The vector to check if empty
 * \return Returns true if the vector is empty
 *
 * \param vector Bo'shligini tekshirish uchun vektor
 * \return Vektor bo'sh bo'lsa true qaytaradi
 */
bool vector_empty(struct vector *vector);

/**
 * Clears the vector
 * Vektor tozalanadi
 *
 * \param vector The vector to clear
 *
 * \param vector Tozalanadigan vektor
 */
void vector_clear(struct vector *vector);

/**
 * Returns the amount of elements in this vector
 * Bu vektorda elementlar sonini qaytaradi
 *
 * \param vector The vector to get the element count of
 *
 * \param vector Elementlar sonini olish uchun vektor
 */
int vector_count(struct vector *vector);

/**
 * Freads from the file directly into the vector
 * Fread ni to'g'ridan-to'g'ri vektorga o'qiladi
 *
 * \param vector The vector to fread into
 * \param amount The amount of elements to fread
 * \param fp The file pointer to fread from
 *
 * \param vector Vektorga fread qilish uchun vektor
 * \param amount Fread qilinadigan elementlar soni
 * \param fp Fread qilish uchun fayl pointeri
 */
int vector_fread(struct vector *vector, int amount, FILE *fp);

/**
 * Returns a void pointer pointing to the data of this vector
 * Bu vektorning ma'lumotlariga ishora qiladigan void pointerini qaytaradi
 *
 * \param vector The vector to get the data pointer of
 *
 * \param vector Ma'lumotlar manzilini olish uchun vektor
 */
void *vector_data_ptr(struct vector *vector);

/**
 * Insert all elements from vector_src into vector_dst at the specified index
 * dst_index vector_src dan vector_dst ga barcha elementlarni dst_index
 * indeksiga qo'shadi
 *
 * \param vector_dst The vector to insert the elements into
 * \param vector_src The vector to insert the elements from
 * \param dst_index The index to insert the elements at
 * \return Returns the index that the elements were inserted at
 */
int vector_insert(struct vector *vector_dst, struct vector *vector_src,
                  int dst_index);

/**
 * Pops the element at the given data address.
 * Berilgan ma'lumotlar manzilidagi elementni olib tashlaydi.
 *
 * \param vector The vector to pop an element on
 * \param address The address that is part of the vector->data range to pop off.
 * \return Returns the index that we popped off.
 *
 * \param vector Elementni olib tashlash uchun vektor
 * \param address Vektorga tegishli bo'lgan vector->data oraliqida olib
 * tashlanadigan manzil \return Olib tashlangan indeksni qaytaradi
 */
int vector_pop_at_data_address(struct vector *vector, void *address);

/**
 * Pops the given value from the vector. Only the first value found is popped
 * Vektordan berilgan qiymatni olib tashlaydi. Faqatgina topilgan birinchi
 * qiymat olib tashlanadi
 *
 * \param vector The vector to pop the value from
 * \param val The value to pop from the vector
 * \return Returns the index that the value was popped from
 *
 * \param vector Qiymatni olib tashlash uchun vektor
 * \param val Vektordan olib tashlanadigan qiymat
 * \return Qiymatni olib tashlandigi indeksni qaytaradi
 */
int vector_pop_value(struct vector *vector, void *val);

/**
 * Pops a value from the vector at the given index
 * Berilgan indeksdagi qiymatni vektordan olib tashlaydi
 *
 * \param vector The vector to pop a value from
 *
 * \param vector Qiymatni olib tashlash uchun vektor
 */
void vector_pop_at(struct vector *vector, int index);

/**
 * Decrements the peek pointer so that the next peek
 * will point at the last peeked token
 * Peek pointer ni kamaytiradi, shunda keyingi peek
 * oxirgi peek qilib qo'yiladi
 *
 * \param vector The vector to decrement the peek pointer of
 *
 * \param vector Peek pointer ni kamaytirish uchun vektor
 */
void vector_peek_back(struct vector *vector);

/**
 * Returns the current index that a vector_push would push too
 * vector_push itarishi mumkin bo'lgan hozirgi indeksni qaytaradi
 *
 * \param vector The vector to get the current index of
 * \return Returns the current index of the vector
 *
 * \param vector Hozirgi indeksni olish uchun vektor
 * \return Vektorni hozirgi indeksini qaytaradi
 */
int vector_current_index(struct vector *vector);

/**
 * Saves the state of the vector
 * Vektorning holatini saqlaydi
 *
 * \param vector The vector to save the state of
 *
 * \param vector Vektor holatini saqlash uchun vektor
 */
void vector_save(struct vector *vector);

/**
 * Restores the state of the vector
 * Vektor holatini tiklaydi
 *
 * \param vector The vector to restore the state of
 *
 * \param vector Vektor holatini tiklash uchun vektor
 */
void vector_restore(struct vector *vector);

/**
 * Purges the last save state as if it never happend
 * Oxirgi saqlangan holatni hech qachon bo'lmaganday yo'q qiladi
 *
 * \param vector The vector to purge the last save state of
 *
 * \param vector Oxirgi saqlangan holatni tozalash uchun vektor
 */
void vector_save_purge(struct vector *vector);

/**
 * Returns the element size per element in this vector
 * Shu vektorda har bir element uchun element hajmini qaytaradi
 *
 * \param vector The vector to get the element size of
 * \return Returns the element size of the vector
 *
 * \param vector Element hajmini olish uchun vektor
 * \return Vektorni element hajmi qaytaradi
 */
size_t vector_element_size(struct vector *vector);

/**
 * Clones the given vector including all vector data, saves are ignored
 * Berilgan vektorni nusxalaydi, vektor ma'lumotlari bilan birga, saqlashlar
 * e'tiborsiz
 *
 * \param vector The vector to clone
 * \return Returns a new vector that is a clone of the given vector
 *
 * \param vector Nusxalash uchun vektor
 * \return Berilgan vektorni nusxasi bo'lgan yangi vektorni qaytaradi
 */
struct vector *vector_clone(struct vector *vector);

#endif
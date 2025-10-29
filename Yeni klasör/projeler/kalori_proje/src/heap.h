
#ifndef HEAP_H  // Include guard başlangıcı
#define HEAP_H  // HEAP_H makrosunu tanımla

#include "recipe.h"  // Recipe veri yapısı için

typedef struct {
    Recipe** recipes;  // Tarif pointer'ları dizisi (dinamik dizi)
    int size;          // Heap'te şu anda bulunan eleman sayısı
    int capacity;      // Heap'in maksimum kapasitesi
} Heap;

Heap* heap_create(int capacity);

int heap_insert(Heap* heap, Recipe* recipe);

Recipe* heap_extract_min(Heap* heap);

Recipe* heap_peek(Heap* heap);

void heapify_up(Heap* heap, int index);

void heapify_down(Heap* heap, int index);

void heap_swap(Recipe** recipe1, Recipe** recipe2);

void heap_sort_recipes(Recipe** recipes, int count);

int heap_is_empty(Heap* heap);

int heap_is_full(Heap* heap);

void heap_destroy(Heap* heap);

int heap_parent(int index);

int heap_left_child(int index);

int heap_right_child(int index);

#endif // HEAP_H - Include guard sonu

#include "spisok.h"
#include <stdlib.h>

void InitList(List* lst) { lst->size = 0; }

bool IsEmpty(List* lst) { return lst->size == 0; }

bool IsFull(List* lst) { return lst->size >= MAX_SIZE; }

bool Add(List* lst, Element x) {
    if (IsFull(lst)) return false;
    lst->data[lst->size++] = x;
    return true;
}

bool RemoveAt(List* lst, int i, Element* x) {
    if (i < 0 || i >= lst->size) return false;
    *x = lst->data[i];
    for (int j = i; j < lst->size - 1; j++)
        lst->data[j] = lst->data[j + 1];
    lst->size--;
    return true;
}

int GetSize(List* lst) { return lst->size; }

Element Get(List* lst, int i) { return (i < 0 || i >= lst->size) ? -1 : lst->data[i]; }

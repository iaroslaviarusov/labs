#ifndef SPISOK_H
#define SPISOK_H

#include <stdbool.h>

#define MAX_SIZE 100

typedef int Element;

typedef struct {
    Element data[MAX_SIZE];
    int size;
} List;

void InitList(List* lst);
bool IsEmpty(List* lst);
bool IsFull(List* lst);
bool Add(List* lst, Element value);
bool RemoveAt(List* lst, int index, Element* value); 
int GetSize(List* lst);                     
Element Get(List* lst, int index);          

#endif

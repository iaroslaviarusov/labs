#include "sort.h"

Element ExtractMax(List* lst) {
    int maxIndex = 0;
    Element maxValue = Get(lst, 0);
    for (int i = 1; i < GetSize(lst); i++) {
        Element v = Get(lst, i);
        if (v > maxValue) {
            maxValue = v;
            maxIndex = i;
        }
    }
    Element removed;
    RemoveAt(lst, maxIndex, &removed);
    return removed;
}

void SelectionSort(List* lst, List* sorted) {
    if (IsEmpty(lst)) return;
    Element x = ExtractMax(lst);
    Add(sorted, x);
    SelectionSort(lst, sorted);
}

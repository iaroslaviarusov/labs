#include "spisok.h"
#include "sort.h"
#include <stdio.h>

int main() {
    List lst, lstCopy, sorted, sorted2;
    InitList(&lst);
    InitList(&lstCopy);
    InitList(&sorted);
    InitList(&sorted2);

    int x;
    while (scanf("%d", &x) == 1) {
        Add(&lst, x);
        Add(&lstCopy, x);
        if (getchar() == '\n') break;
    }

    SelectionSort(&lst, &sorted);
    for (int i = 0; i < GetSize(&sorted); i++) printf("%d ", Get(&sorted, i));
    printf("\n");

    ExtractMax(&lstCopy);

    SelectionSort(&lstCopy, &sorted2);
    for (int i = 0; i < GetSize(&sorted2); i++) printf("%d ", Get(&sorted2, i));
    printf("\n");

    return 0;
}

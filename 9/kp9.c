#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 12   // максимум элементов

typedef struct {
    int k;       // ключ
    char d[20];  // данные
} T;

T t[MAX];  // таблица
int n = 0; // количество элементов

// Загрузка таблицы из файла
void ld(char* fn) {
    FILE* f = fopen(fn, "r");
    if (!f) { printf("Fail\n"); exit(1); }
    while (fscanf(f, "%d %s", &t[n].k, t[n].d) == 2) n++;
    fclose(f);
}

// Печать таблицы
void pt() {
    for (int i = 0; i < n; i++)
        printf("Key: %d | Data: %s\n", t[i].k, t[i].d);
    printf("\n");
}

// Сортировка линейным выводом с обменом
void sx() {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (t[i].k > t[j].k) {
                T tmp = t[i];
                t[i] = t[j];
                t[j] = tmp;
            }
}

// Двоичный поиск по ключу
int bs(int x) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (t[m].k == x) return m;
        else if (t[m].k < x) l = m + 1;
        else r = m - 1;
    }
    return -1;
}

int main() {
    FILE* f = fopen("data0.txt", "r");
    if (!f) {
        printf("File data.txt wasnt found!\n");
        return 1;
    }
    ld("data0.txt");

    printf("Table:\n");
    pt();

    sx();
    printf("Table after sorting:\n");
    pt();

    int m, key;
    printf("Amount of keys ");
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        printf("Key #%d: ", i + 1);
        scanf("%d", &key);
        int p = bs(key);
        if (p != -1) printf("Found element: Key: %d | Data: %s\n", t[p].k, t[p].d);
        else printf("Element with key %d wasnt found\n", key);
    }

    return 0;
}

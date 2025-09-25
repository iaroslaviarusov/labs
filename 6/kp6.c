#include <stdio.h>

int main() {
    FILE* f = fopen("input.txt", "r");
    if (!f) {
        printf("Cant open input.txt\n");
        return 1;
    }

    int p;  
    printf("Score: ");
    scanf("%d", &p);

    char sur[50];  
    char i1, i2;    
    int sch, med, sc, es;         

    int mb = 0;     

    while (fscanf(f, "%s %c %c %d %d %d %d", sur, &i1, &i2, &sch, &med, &sc, &es) == 7) {
        if (med == 1 && sc < p) {
            mb++;
            printf("%s %c %c\n",
                sur, i1, i2, sch, sc);
        }
    }
    if (mb == 0)
        printf("No results found\n");

    fclose(f);


    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef enum { N_OP, N_NUM, N_VAR } T;

typedef struct Node {
    T t;
    char op;
    double val;
    char v;
    struct Node* l;
    struct Node* r;
} Node;


Node* num(double x) {
    Node* node = malloc(sizeof(Node));
    node->t = N_NUM;
    node->val = x;
    node->l = node->r = NULL;
    return node;
}


Node* var(char x) {
    Node* node = malloc(sizeof(Node));
    node->t = N_VAR;
    node->v = x;
    node->l = node->r = NULL;
    return node;
}


Node* op(char c, Node* l, Node* r) {
    Node* node = malloc(sizeof(Node));
    node->t = N_OP;
    node->op = c;
    node->l = l;
    node->r = r;
    return node;
}

Node* s(Node* r) {
    if (!r) return NULL;
    if (r->t == N_OP) {
        r->l = s(r->l);
        r->r = s(r->r);
        if (r->op == '/' && r->l && r->l->t == N_OP && r->l->op == '*' && r->l->l->t == N_NUM && r->r->t == N_NUM) {
            double x = r->l->l->val / r->r->val;
            if (x == 1) {
                Node* res = r->l->r;
                free(r->l); free(r->r); free(r);
                return res;
            }
            Node* nl = num(x);
            Node* nr = r->l->r;
            free(r->l); free(r->r); free(r);
            return op('*', nl, nr);
        }
    }
    return r;
}

void p(Node* r) {
    if (!r) return;
    if (r->t == N_NUM) printf("%.0f", r->val);
    else if (r->t == N_VAR) printf("%c", r->v);
    else {p(r->l); printf(" %c ", r->op); p(r->r); }
}

void f(Node* r) {
    if (!r) return;
    f(r->l);
    f(r->r);
    free(r);
}

Node* parse(char* e) {
    Node* n1 = num(e[0] - '0');
    Node* v = var(e[2]);
    Node* n2 = num(e[4] - '0');
    return op('/', op('*', n1, v), n2);
}

int main() {
    char e[10];
    scanf("%s", e);
    Node* r = parse(e);
    r = s(r);
    p(r); printf("\n");
    f(r);
    return 0;
}

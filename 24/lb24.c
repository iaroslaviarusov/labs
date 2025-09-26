#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;


Node* insert(Node* t, int v) {
    if (t == NULL) {
        Node* n = malloc(sizeof(Node));
        n->data = v;
        n->left = NULL;
        n->right = NULL;
        return n;
    }
    if (v < t->data) {
        t->left = insert(t->left, v);
    } else if (v > t->data) {
        t->right = insert(t->right, v);
    }
    return t;
}


Node* del(Node* t, int v) {
    if (t == NULL) return t;

    if (v < t->data) {
        t->left = del(t->left, v);
    } else if (v > t->data) {
        t->right = del(t->right, v);
    } else {
        if (t->left == NULL) {
            Node* r = t->right;
            free(t);
            return r;
        }
        if (t->right == NULL) {
            Node* r = t->left;
            free(t);
            return r;
        }
        Node* tmp = t->right;
        while (tmp->left != NULL) tmp = tmp->left;
        t->data = tmp->data;
        t->right = del(t->right, tmp->data);
    }
    return t;
}


void print(Node* t, int l) {
    if (t == NULL) return;
    for (int i = 0; i < l; i++) printf(" ");
    printf("%d\n", t->data);
    print(t->left, l + 1);
    print(t->right, l + 1);
}


int leaves(Node* t) {
    if (t == NULL) return 0;
    if (t->left == NULL && t->right == NULL) return 1;
    return leaves(t->left) + leaves(t->right);
}

int main() {
    Node* root = NULL;
    char c;
    int v;

    //a - add, b - del, c - print, d - count, f - finish

    while (1) {
        scanf_s(" %c", &c, 1);   
        if (c == 'a') {
            scanf_s("%d", &v);
            root = insert(root, v);
        } else if (c == 'b') {
            scanf_s("%d", &v);
            root = del(root, v);
        } else if (c == 'c') {
            print(root, 0);
        } else if (c == 'd') {
            printf("%d\n", leaves(root));
        } else if (c == 'f') {
            break;
        }
    }

    return 0;
}

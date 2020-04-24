#include<stdio.h>
#include<stdlib.h>

typedef struct BTNode {
    char data;
    struct BTNode *lchild;
    struct BTNode *rchild;
} BTNode;

char pre[100], mid[100];
int num;

void init() {
    char s;
    for (int i = 0; i < 100; i++) {
        pre[i] = '#';
        mid[i] = '#';
    }
    int i = 0;
    while ((s = getchar()) != '\n') {
        pre[i] = s;
        i++;
    }
    i = 0;
    while ((s = getchar()) != '\n') {
        mid[i] = s;
        i++;
    }
    i = 0;
    while (pre[i] != '#') {
        i++;
    }
    num = i;
}

BTNode *create(int prestart, int preend, int midstart, int midend) {
    int i, lnum, rnum;
    BTNode *root = (BTNode *) malloc(sizeof(BTNode));
    root->data = pre[prestart];
    root->lchild = NULL;
    root->rchild = NULL;
    i = midstart;
    while (root->data != mid[i])
        i++;
    lnum = i - midstart;//left child
    rnum = midend - i;//right child
    if (lnum) {
        root->lchild = create(prestart + 1, prestart + lnum, midstart, i - 1);
    }
    if (rnum) {
        root->rchild = create(prestart + lnum + 1, preend, i + 1, midend);
    }
    return root;
}

void print(BTNode *root) {
    if (root->lchild) {
        print(root->lchild);
    }
    if (root->rchild) {
        print(root->rchild);
    }
    printf("%c", root->data);
}

int main() {
    BTNode *root = (BTNode *) malloc(sizeof(BTNode));
    init();
    root = create(0, num - 1, 0, num - 1);
    print(root);
    return 0;
}//
// Created by sqx08 on 2020/4/24.
//


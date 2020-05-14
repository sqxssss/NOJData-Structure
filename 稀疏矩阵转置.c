#include<stdio.h>

typedef struct {
    int r;
    int c;
    int v;
} Triple;

int main() {
    int m, n, i = 0, j = 0;
    scanf("%d%d", &m, &n);
    Triple A[130000];
    for (;;) {
        int r, c, v;
        scanf("%d%d%d", &r, &c, &v);
        if (r == 0 && c == 0 && v == 0)
            break;
        A[i].r = r, A[i].c = c, A[i].v = v;
        i++;
    }
    for (j = 0; j < i; j++) {
        printf("%d %d %d\n", A[j].c, A[j].r, A[j].v);
    }
    return 0;
}//
// Created by sqx08 on 2020/5/14.
//


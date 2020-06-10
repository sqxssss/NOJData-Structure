#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    char data;
    struct node *next;
} node, *pnode;

typedef struct stack {
    struct node *bottom;
    struct node *top;
} stack, *pstack;

void init(stack *list) {
    node *p = (pnode) malloc(sizeof(node));
    p->data = '#';
    p->next = NULL;
    list->bottom = p;
    list->top = p;
}

void push(stack *list, char x) {
    node *p = (pnode) malloc(sizeof(node));
    p->data = x;
    p->next = NULL;
    list->top->next = p;
    list->top = p;
}

bool isempty(stack *list) {
    if (list->top == list->bottom)
        return true;
    else
        return false;
}

void pop(stack *list) {
    pnode p, q;
    p = list->top;
    q = list->bottom;
    while (q->next != p) {
        q = q->next;
    }
    list->top = q;
    free(p);
}

bool judgelow(pstack list, char x) {
    char y;
    y = list->top->data;
    if ((x == '*' || x == '/') && (y == '+' || y == '-'))
        return false;
    else
        return true;
}

int main() {
    char s;
    pstack list = (pstack) malloc(sizeof(stack));
    pnode p;
    init(list);
    while (scanf("%c", &s)) {
        if (s == '\n')
            break;
        else if (s >= 'a' && s <= 'z')
            printf("%c", s);
        else if (s == '(')
            push(list, s);
        else if (s == ')') {
            while (list->top->data != '(') {
                printf("%c", list->top->data);
                pop(list);
            }
            pop(list);
        } else {
            while (1) {
                if (!judgelow(list, s) || isempty(list) || list->top->data == '(') {
                    push(list, s);
                    break;
                } else {
                    printf("%c", list->top->data);
                    pop(list);
                }
            }
        }
    }
    while (!isempty(list)) {
        printf("%c", list->top->data);
        pop(list);
    }
    return 0;
}//
// Created by sqx08 on 2020/6/10.
//


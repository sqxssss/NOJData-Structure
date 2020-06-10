#include<stdio.h>
#include<stdlib.h>

#define max 200

typedef struct data {
    int num;
    struct data *next;
} data;

typedef struct queue {
    struct data *head;
    struct data *rear;
} queue;

typedef struct ArcNode {
    int Adjvex;
    struct ArcNode *nextarc;
} ArcNode;

typedef struct VNode {
    int code;
    struct ArcNode *firstarc;
} VNode, AdjList[max];

typedef struct LGraph {
    AdjList vertices;
    int Nv;
    int Ne;
} LGraph;

int visited[max] = {0};
int flag = 1;

void InitQueue(queue *Q, int n) {
    data *p = (data *) malloc(sizeof(data));
    p->num = 0;
    p->next = NULL;
    Q->head = p;
    Q->rear = p;
}

void push(queue *Q, int n) {
    data *p, *q;
    p = (data *) malloc(sizeof(data));
    p->num = n;
    q = Q->head->next;
    if (q == NULL) {
        p->next = NULL;
        Q->head->next = p;
        Q->rear = p;
    } else {
        Q->head->next = p;
        p->next = q;
    }
}

int pop(queue *Q) {
    data *p, *q;
    int codenum;
    p = Q->head;
    q = Q->rear;
    codenum = q->num;
    while (p->next != q) {
        p = p->next;
    }
    Q->rear = p;
    Q->rear->next = NULL;
    free(q);
    return codenum;
}

int EmptyQueue(queue *Q) {
    if (Q->rear == Q->head)
        return 1;
    else
        return 0;
}

void CreateGraph(LGraph *List) {
    int i, x, y;
    scanf("%d%d", &x, &y);
    List->Nv = x;
    List->Ne = y;
    for (i = 1; i <= List->Nv; i++) {
        scanf("%d", &List->vertices[i].code);
        List->vertices[i].firstarc = NULL;
    }
    for (i = 1; i <= List->Ne; i++) {
        ArcNode *p = (ArcNode *) malloc(sizeof(ArcNode));
        scanf("%d%d", &x, &y);
        p->Adjvex = y;
        p->nextarc = List->vertices[x].firstarc;
        List->vertices[x].firstarc = p;
    }
}

int BFS(queue *Q, LGraph *List, int x, int y) {
    int i, tmp, tmp1;
    ArcNode *p;
    while (!EmptyQueue(Q) || flag == 1) {
        flag = 0;
        tmp = pop(Q);
        visited[tmp] = 1;
        p = List->vertices[tmp].firstarc;
        for (; p != NULL; p = p->nextarc) {
            tmp1 = p->Adjvex;
            if (tmp1 == y)
                return 1;
            else if (!(visited[tmp1]))
                push(Q, tmp1);
        }
    }
    return 0;
}

int main() {
    LGraph List;
    queue *Q = (queue *) malloc(sizeof(queue));
    int n, m;
    CreateGraph(&List);
    scanf("%d%d", &n, &m);
    InitQueue(Q, n);
    push(Q, n);
    if (BFS(Q, &List, n, m)) {
        printf("yes\n");
    } else {
        printf("no\n");
    }
    return 0;
}//
// Created by sqx08 on 2020/6/10.
//


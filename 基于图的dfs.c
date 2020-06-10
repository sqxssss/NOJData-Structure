//
// Created by sqx08 on 2020/6/10.
//
#include<stdio.h>
#include<stdlib.h>

#define max 200

typedef char VertexType;
typedef struct AdjVNode *PtrToAdjVNode;
typedef struct GNode *PtrToGNode;

int visited[max] = {0};

typedef struct VNode {
    VertexType data;
    PtrToAdjVNode FirstEdge;
} AdjList[max];//the gathering of vertex

struct AdjVNode {
    VertexType AdjV;
    PtrToAdjVNode next;
};//the adjcent vertex

struct GNode {
    int Nv;//number of vertex
    int Ne;//number of edge
    AdjList G;//adjcent list
};
typedef PtrToGNode LGraph;

void CreateLGraph(LGraph g, int vex, int arc) {
    int node[100];
    for (int i = 0; i < vex; i++) {
        scanf("%d", &node[i]);
    }
    g->Ne = arc;
    g->Nv = vex;
    int v1, v2, i;
    for (i = 1; i <= vex; i++) {
        g->G[i].FirstEdge = NULL;
    }
    for (i = 1; i <= arc; i++) {
        scanf("%d%d", &v1, &v2);
        PtrToAdjVNode q = (PtrToAdjVNode) malloc(sizeof(AdjVNode));
        q->AdjV = v2;
        q->next = g->G[v1].FirstEdge;
        g->G[v1].FirstEdge = q;
    }
}

int DFS(LGraph p, int i, int j) {
    visited[i] = 1;
    PtrToAdjVNode q = p->G[i].FirstEdge;
    while (q) {
        if (q->AdjV == j)
            return 1;
        if (!(visited[q->AdjV]) && DFS(p, q->AdjV, j))
            return 1;
        q = q->next;
    }
    return 0;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    GNode a;
    LGraph g = &a;
    CreateLGraph(g, n, m);
    int v1, v2;
    scanf("%d%d", &v1, &v2);
    int flag = DFS(g, v1, v2);
    if (flag) {
        printf("yes\n");
    } else {
        printf("no\n");
    }
    return 0;
}

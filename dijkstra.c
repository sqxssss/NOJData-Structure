#include<stdio.h>
#include<stdlib.h>

#define inf 10000

typedef struct {
    int vexs[100];
    int arc[100][100];
    int vexnum, arcnum;
} LGraph;

int Getinfo(LGraph *G, int j) {
    for (int i = 0; i < G->vexnum; i++) {
        if (G->vexs[i] == j) {
            return i;
        }
    }
    return -1;
}

void create(LGraph *G, int vex, int arc) {
    G->vexnum = vex;
    G->arcnum = arc;
    for (int i = 0; i < G->vexnum; i++) {
        G->vexs[i] = i + 1;
    }
    for (int i = 0; i < G->vexnum; i++) {
        for (int j = 0; j < G->vexnum; j++) {
            G->arc[i][j] = inf;
        }
    }
    for (int i = 0; i < G->arcnum; i++) {
        int v1, v2, num;
        scanf("%d%d%d", &v1, &v2, &num);
        int m = Getinfo(G, v1);
        int n = Getinfo(G, v2);
        G->arc[m][n] = num;
    }
}

void Dijkstra(LGraph *G, int v0, int *dist) {
    int k;
    int visited[100];
    for (int i = 0; i < G->vexnum; i++) {
        visited[i] = 0;
        dist[i] = G->arc[v0][i];
    }
    dist[v0] = 0;
    visited[v0] = 1;
    for (int i = 1; i < G->vexnum; i++) {
        int mindist = inf;
        for (int j = 0; j < G->vexnum; j++) {
            if (!visited[j]) {
                if (dist[j] < mindist) {
                    k = j;
                    mindist = dist[j];
                }
            }
        }
        visited[k] = 1;
        for (int j = 0; j < G->vexnum; j++) {
            if (!visited[j] && (mindist + G->arc[k][j] < dist[j])) {
                dist[j] = mindist + G->arc[k][j];
            }
        }
    }
}

void BubbleSort(LGraph *G, int *dist) {
    int temp;
    for (int i = 1; i < G->vexnum; i++) {
        for (int j = 1; j < G->vexnum - i; j++) {
            if (dist[j] > dist[j + 1]) {
                temp = dist[j];
                dist[j] = dist[j + 1];
                dist[j + 1] = temp;
                temp = G->vexs[j];
                G->vexs[j] = G->vexs[j + 1];
                G->vexs[j + 1] = temp;
            }
        }
    }
}

void print(LGraph *G, int *dist) {
    for (int i = 1; i < G->vexnum; i++) {
        if (dist[i] != inf) {
            printf("%d %d %d \n", G->vexs[0], G->vexs[i], dist[i]);
        } else {
            printf("%d %d -1 \n", G->vexs[0], G->vexs[i]);
        }
    }
}

int main() {
    LGraph G;
    int dist[100];
    int i, j;
    int vex, arc;
    scanf("%d%d", &vex, &arc);
    create(&G, vex, arc);
    Dijkstra(&G, 0, dist);
    BubbleSort(&G, dist);
    print(&G, dist);
    return 0;
}//
// Created by sqx08 on 2020/6/10.
//


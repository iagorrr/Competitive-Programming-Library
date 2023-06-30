// iagorrr ;)
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define min(a, b) (a < b ? a : b)

const int NOT_CONNECTED = INT_MAX;
typedef struct graph_st {
  int v;
  int e;
  int **adj;
} graph_st;

graph_st *graph_init(int v) {
  graph_st *g = (graph_st *)malloc(sizeof(graph_st));
  g->v = v;
  g->adj = (int **)malloc(sizeof(int **) * v);
  for (int i = 0; i < v; i++) {
    g->adj[i] = (int *)malloc(sizeof(int *) * v);
    for (int j = 0; j < v; ++j)
      g->adj[i][j] = NOT_CONNECTED;
  }
  return g;
}

void graph_delete(graph_st *g) {
  for (int i = 0; i < g->v; ++i)
    free(g->adj[i]);
  free(g->adj);
  free(g);
}

void add_edge(graph_st *g, int a, int b, int w) {
  // fprintf(stderr, "adj[%d][%d] = %d\n", a, b, w);
  g->adj[a][b] = w;
}

bool connected(graph_st *g, int a, int b) {
  return g->adj[a][b] != NOT_CONNECTED;
}

int distance(graph_st *g, int a, int b) { return g->adj[a][b]; }
void floyd_warshall(graph_st *g) {
  for (int i = 0; i < g->v; ++i)
    g->adj[i][i] = 0;

  for (int i = 0; i < g->v; i++)
    for (int j = 0; j < g->v; j++)
      if (connected(g, j, i))
        for (int k = 0; k < g->v; k++) {
          if (connected(g, i, k))
            g->adj[j][k] = min(g->adj[j][k], g->adj[j][i] + g->adj[i][k]);
        }

  // mark the negative cycles
  for (int i = 0; i < g->v; ++i)
    for (int j = 0; j < g->v; ++j)
      for (int t = 0; t < g->v; ++t)
        if (connected(g, i, t) && connected(g, t, j) && g->adj[t][t] < 0)
          g->adj[i][j] = NOT_CONNECTED;
}
int main(void) {
  int v;
  scanf("%d", &v);

  graph_st *g = graph_init(v);
  graph_st *gs = graph_init(v);

  int u, w, c, t;
  while (scanf("%d %d %d %d", &u, &w, &c, &t) == 4) {
    if (!u && !w && !c && !t)
      break;

    if (t)
      add_edge(gs, u, w, c);
    else {
      add_edge(gs, u, w, c);
      add_edge(gs, w, u, c);
      add_edge(g, u, w, c);
      add_edge(g, w, u, c);
    }
  }

  floyd_warshall(g);
  floyd_warshall(gs);

  while (scanf("%d %d", &u, &w) == 2) {
    // printf("[%d %d]\n", u, w);
    if (!connected(g, u, w) || !connected(gs, u, w))
      printf("Impossibru\n");
    else
      printf("%d %d\n", distance(g, u, w), distance(gs, u, w));
  }

  graph_delete(g);
  graph_delete(gs);
}

// AC, graph, floyd warshall, negative cycle

#ifndef BFS
#define BFS
#include "debug.c"
#include "explore.c"
#include "map.c"
#include "queue.c"
#include "vector.c"

void freeCord(void *item) { free((coord *)item); }

vector_st *reconstruct(coord *s, coord *e) {
        vector_st *path = vector(1, freeCord);
        coord *cur = s;
        while (cur->i != e->i || cur->j != e->j) {
                // fprintf(stderr, "cur: [%d %d] ", cur->i, cur->j);
                coord *new = malloc(sizeof(coord));
                *new = *cur;
                vector_push_back(path, new);
                *cur = get_parent(*cur);
                // fprintf(stderr, " parent : [%d %d] ", cur->i, cur->j);
        }
        vector_push_back(path, cur);
        fprintf(stderr, "Terminei pira ???\n");
        return path;
}

vector_st *bfs(coord *s, coord *e) {
        /*
          retorna um vector com o menor caminho de s pra e, cord a cord
        */
        fprintf(stderr, "Vou alocar a fila\n");
        queue_st *q = queue(freeCord);
        if (q == NULL) {
                fprintf(stderr, "A GENTE É MT BURRO\n");
        }

        fprintf(stderr, "Vou alocar o primeiro\n");
        coord *first = malloc(sizeof(coord));
        if (first == NULL) {
                fprintf(stderr, "Faltou memória pooooorra\n");
        }
        *first = *s;
        fprintf(stderr, "Vou empurrar o primeiro\n");
        queue_push_back(q, first);

        fprintf(stderr, "Porra, vou entrar na fila aqui\n");
        int m = 0;
        while (!queue_empty(q)) {
                coord cur = *((coord *)queue_front(q));
                fprintf(stderr, "cur antes: %d %d\n", cur.i, cur.j);
                queue_pop(q);

                fprintf(stderr, "cur depois: %d %d\n", cur.i, cur.j);
                if (cur.i == e->i && cur.j == e->j) {
                        // fprintf(stderr, "\n\n\n\nACHEI PORRAAAAAAA\n\n\n");
                        break;
                }

                //  logger("aqui??", m);
                for (int i = 0; i < 4; ++i) {
                        if (!visited(simulatePos(cur, i)) && isKnown(cur, i) &&
                            !isWall(cur, i)) {
                                //  logger("vo enfielirar ", m);
                                coord *child = malloc(sizeof(coord));
                                *child = simulatePos(cur, i);
                                set_parent(*child, cur);
                                set_visited(*child);
                                queue_push_back(q, child);
                                //  logger("enfilerei", m);
                        }
                }
        }
        //  logger("saidabfs", m);
        vector_st *path = reconstruct(e, s);
        queue_destroy(q);
        return path;
}
#endif

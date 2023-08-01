#include <stdio.h>

#include "bfs.c"
#include "explore.c"
#include "map.c"
#include "vector.c"

int main(void) {
        // acha a saída e mapeia pra noix
        dfs((coord){0, 0}, 0);

        vector_st *path = bfs(&current_cord, &(coord){0, 0});

        char iMoved = 0;
        for (int i = path->size - 1; i > 0; i--) {
                int torotate =
                        needRotate(*((coord *)path->items[i]),
                                   *((coord *)path->items[i - 1]), direction);
                if (torotate == 0) {
                        if (iMoved) {
                                moveFast();
                                iMoved = 0;
                        } else {
                                iMoved = 1;
                        }
                } else {
                        if (iMoved) {
                                move();
                        }

                        if (torotate == 3) {
                                rotateLeft();
                        } else {
                                while (torotate--) {
                                        rotateRight();
                                }
                        }
                        iMoved = 1;
                }
        }
        if (iMoved == 1) {
                fprintf(stderr, "Movi o ultimo aqui pq né...\n");
                move();
        }
        fprintf(stderr, "Deveria ter chegado no goal aí hein\n");
        fprintf(stderr, "cur: %d %d\n", current_cord.i, current_cord.j);

        iMoved = 0;
        for (int i = 0; i < path->size - 1; i++) {
                int torotate =
                        needRotate(*((coord *)path->items[i]),
                                   *((coord *)path->items[i + 1]), direction);
                if (torotate == 0) {
                        if (iMoved) {
                                moveFast();
                                iMoved = 0;
                        } else {
                                iMoved = 1;
                        }
                } else {
                        if (iMoved) {
                                move();
                        }

                        if (torotate == 3) {
                                rotateLeft();
                        } else {
                                while (torotate--) {
                                        rotateRight();
                                }
                        }
                        iMoved = 1;
                }
        }
        if (iMoved == 1) {
                fprintf(stderr, "Movi o ultimo aqui pq né...\n");
                move();
        }
        fprintf(stderr, "pra gente acabou hein kkk");
}

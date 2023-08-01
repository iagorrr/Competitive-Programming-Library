#include <stdio.h>

#include "bfs.c"
#include "explore.c"
#include "map.c"
#include "vector.c"

int main(void) {
        // acha a saída e mapeia pra noix
        fprintf(stderr, "Começando !\n");
        dfs((coord){0, 0}, 0);
        fprintf(stderr, "Achei a saida 1\n");

        fprintf(stderr, "to rodando bfs\n");
        vector_st *path = bfs(&current_cord, &(coord){0, 0});
        fprintf(stderr, "terminei bfs\n");

        // fprintf(stderr, "Rodando bfs de [%d, %d] para [%d, %d]\n",
        // current_cord.i, current_cord.j, 0, 0);
        for (int i = 0; i < path->size; i++) {
                fprintf(stderr, "[%d, %d] -> ", ((coord *)path->items[i])->i,
                        ((coord *)path->items[i])->j);
        }
        fprintf(stderr, "\n");

        fprintf(stderr, "fazendo caminho da saida pro inicio : \n");
        for (int i = path->size - 1; i > 0; i--) {
                int torotate =
                        needRotate(*((coord *)path->items[i]),
                                   *((coord *)path->items[i - 1]), direction);
                if (torotate == 3)
                        rotateLeft();
                else {
                        while (torotate--) {
                                rotateRight();
                        }
                }
                move();
        }
        fprintf(stderr, "terminei caminho da saída pro inicio : \n");

        fprintf(stderr, "fazendo do início pra saída\n");
        for (int i = 0; i < path->size - 1; i++) {
                int torotate =
                        needRotate(*((coord *)path->items[i]),
                                   *((coord *)path->items[i + 1]), direction);
                if (torotate == 3)
                        rotateLeft();
                else {
                        while (torotate--) {
                                rotateRight();
                        }
                }
                move();
        }
        fprintf(stderr, "terminei do início pra saída\n");
}

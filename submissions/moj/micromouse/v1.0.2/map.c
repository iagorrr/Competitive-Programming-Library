#ifndef MAP
#define MAP
#include <stdbool.h>
#include <stdio.h>

enum states {
        NOT_VISITED = -1,
        VISITED = -2,
        UNKNOWN = -3,
};

// 4 first bits to mark if is known, and 4 last to mark as wall or not
typedef char dirs;

typedef struct coord {
        int i, j;
} coord;

typedef struct map_cell {
        // state >= 0, means the distance to EXIT
        // state < 0, the relation with state enum
        int state;

        // quatro últimos dígitos pra ver se viu, e os 4 primeiros se pode
        // passar
        dirs dir;
        bool visited;
        coord parent;  // parent na bfs
} map_cell;

// coordenada atual do ratinho (não considerando o offset)
coord current_cord = {0, 0};

/* Up, Right, Down, Left (direção que tá olhando agora)*/
int direction = 0;
coord directions_vectors[4] = {
        (coord){-1, 0},  // up
        (coord){0, 1},   // right
        (coord){1, 0},   // down
        (coord){0, -1}   // left
};

#define MAX_DIMENSION (unsigned int)30
map_cell __MAP[MAX_DIMENSION * 2][MAX_DIMENSION * 2];

coord translate(coord *c) {
        // recebe uma coordenada abstraída e retorna a real na matriz
        return (coord){c->i + MAX_DIMENSION, c->j + MAX_DIMENSION};
}
map_cell *get_map_data(coord *c) {
        // recebe a coordenada abstraída e retorna a real do mapa
        coord translated = translate(c);
        return &__MAP[translated.i][translated.j];
}

int opposite(int direction) {
        // retorna o int de acordo com a direção oposta da dada
        return (direction + 2) % 4;
}

int previous_direction() {
        if (direction == 0) {
                direction = 3;
        } else {
                direction--;
        }

        return direction;
}

int next_direction() {
        // TODO: fazer um esquema de decisão mais inteligente
        if (direction == 3) {
                direction = 0;
        } else {
                direction++;
        }
        return direction;
}

coord simulatePos(coord c, int direction) {
        coord d = c;
        //(*(long long *)(&d)) += (*(long long *)(directions_vectors +
        //direction));
        d.i = c.i + directions_vectors[direction].i;
        d.j = c.j + directions_vectors[direction].j;
        return d;
}

bool visited(coord c) {
        c = translate(&c);
        return __MAP[c.i][c.j].visited;
}

void set_visited(coord c) {
        c = translate(&c);
        __MAP[c.i][c.j].visited = 1;
}

void set_parent(coord c, coord p) {
        c = translate(&c);
        __MAP[c.i][c.j].parent = p;
}

coord get_parent(coord c) {
        c = translate(&c);
        return __MAP[c.i][c.j].parent;
}

#endif

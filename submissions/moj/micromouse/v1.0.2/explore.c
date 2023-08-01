#ifndef EXPLORE
#define EXPLORE
#include <stdbool.h>
#include <stdio.h>

#include "debug.c"
#include "map.c"

/*
    Lógicas da movimentação do ratinho :thumbs:
*/

void mark_movable(coord c, int direction, bool possible);

#define FODA 3
#define FOUND 4
#define CRASHED 1
#define WALKED 0

bool checkFoda() {
        coord t = translate(&current_cord);
        // printBits(__MAP[t.i][t.j].dir, 8);
        // printBits(__MAP[t.i][t.j].dir & 0b11110000, 8);
        bool response = (__MAP[t.i][t.j].dir & 0b11110000) == 0b11110000;

        return response;
}

bool isKnown(coord c, int direction)  // a gente conhece a parada
{
        c = translate(&c);
        return __MAP[c.i][c.j].dir & (1 << (direction + 4));
}

bool isWall(coord c, int direction) {
        coord temp = translate(&c);
        return isKnown(c, direction) &&
               ((__MAP[temp.i][temp.j].dir & (1 << direction)) == 0);
}

int moveFast() {
        // só usa  a corrida quando conhece o mapa ent n ta rolando verificação

        fprintf(stdout, "M\n");
        fflush(stdout);
        fscanf(stdin, "%*d");
        fflush(stdin);

        current_cord =
                simulatePos(simulatePos(current_cord, direction), direction);

        return WALKED;
}

int move() {
        if (isWall(current_cord, direction)) {
                return CRASHED;
        }

        fprintf(stdout, "m\n");
        fflush(stdout);

        int r;
        fscanf(stdin, "%d", &r);

        mark_movable(current_cord, direction, r != CRASHED);
        mark_movable(simulatePos(current_cord, direction), opposite(direction),
                     r != CRASHED);

        if (r != CRASHED) {  // atualiza as coordenadas
                current_cord = simulatePos(current_cord, direction);
        }

        return r;
}

void rotateLeft() {
        fprintf(stdout, "l\n");  // rotate left
        fflush(stdout);
        fscanf(stdin, "%*d");

        // FILE *f = fopen("FODA.txt", "a");
        // fprintf(f, "0\n");
        // fclose(f);

        direction = previous_direction();
}

void rotateRight() {
        fprintf(stdout, "r\n");  // rotate right
        fflush(stdout);
        fscanf(stdin, "%*d");

        // FILE *f = fopen("FODA.txt", "a");
        // fprintf(f, "0\n");
        // fclose(f);

        direction = next_direction();
}
int needRotate(coord from, coord to, int actualDirection) {
        // TODO : fazer constante utilizando l e r
        coord desiredDirection = (coord){to.i - from.i, to.j - from.j};
        int ans = 0;
        while (to = directions_vectors[(actualDirection + ans) % 4],
               to.i != desiredDirection.i || to.j != desiredDirection.j) {
                ans++;
        }

        return ans;
}

void mark_movable(coord c, int direction, bool possible) {
        // seta como visitado e se é uma parede ou não
        c = translate(&c);
        __MAP[c.i][c.j].dir |= (1 << (direction + 4));  // visto
        if (possible)
                __MAP[c.i][c.j].dir |= (1 << (direction));  // possível mover
        else
                __MAP[c.i][c.j].dir &=
                        ~(1 << (direction));  // não movível, parede
}

bool dfs(coord parent, int m) {
        while (!checkFoda()) {  // while all directions was not explored
                if (!isKnown(current_cord, direction)) {
                        coord previous = current_cord;
                        int code = move();
                        if (code == FOUND) {
                                return true;
                        }

                        if (code == WALKED) {
                                if (dfs(previous, m + 1)) {
                                        return true;
                                }
                        } else {  // if crashed
                                rotateLeft();
                        }
                } else {  // if already explored
                        rotateLeft();
                }
        }

        // rotate and move back to parent
        int rotates = needRotate(current_cord, parent, direction);
        if (rotates == 3) {
                rotateLeft();
        } else {
                while (rotates--) {
                        rotateRight();
                }
        }
        move();

        // logger("movi?", m);
        return false;
}

// bfs pra achar o melhor caminho dps de ter o mapa (sem mexer o ratinho)

#endif

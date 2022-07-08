#include <bits/stdc++.h>

using namespace std;

typedef tuple <int, int, int> tii;

int main(){ 
    int N, M;
    scanf("%i %i", &N, &M);

    // Cleaning pixels.
    bool visited[1026][1026];
    int pixels[1026][1026];
    for(int i = 0; i < 1026; i++){
        for(int j = 0; j < 1026; j++){
            pixels[i][j] = -1;
            visited[i][j] = false;
        }
    }

    // Receiving matrix.
    char temp[1025];
    for(int i = 0; i < N; i++){
        scanf("%s", temp);

        for(int j = 0; j < M; j++){
            if(temp[j] == '.'){
                pixels[i+1][j+1] = 0;
            }
        }
    }



    // -1 = black 0 = white.
    int color = 0;
    int x, y, colortemp;
    for(int i = 1; i < N+1; i++){
        for(int j = 1; j < M+1; j++){
            if(pixels[i][j] == 0){// New color found paint it.
                color++;
                queue <tii> spreading;
                spreading.push(make_tuple(i, j, color));

                while(!spreading.empty()){
                    tie(x, y, colortemp) = spreading.front();
                    spreading.pop();

                    if(pixels[x+1][y] == 0){
                        pixels[x+1][y] = colortemp;
                        spreading.push(make_tuple(x+1, y, colortemp));
                    }

                    if(pixels[x-1][y] == 0){
                        pixels[x-1][y] = colortemp;
                        spreading.push(make_tuple(x-1, y, colortemp));
                    }

                    if(pixels[x][y+1] == 0){
                        pixels[x][y+1] = colortemp;
                        spreading.push(make_tuple(x, y+1, colortemp));
                    }

                    if(pixels[x][y-1] == 0){
                        pixels[x][y-1] = colortemp;
                        spreading.push(make_tuple(x, y-1, colortemp));
                    }
                }
            }
        }
    }

    // // Just for 'debug'
    // for(int i = 1; i < N+1; i++){
    //     for(int j = 1; j < M+1; j++){
    //         printf("%2i ", pixels[i][j]);
    //     }
    //     printf("\n");
    // }
    printf("%i\n", color);
    return 0;
}

// Accepted.
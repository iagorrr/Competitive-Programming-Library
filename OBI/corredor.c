#include <stdio.h>

int main(){
    int n, i, j, melhor, aux;
    scanf("%i", &n);

    int salas[n];
    for(i = 0; i < n; i++){
        scanf("%i", &salas[i]);
    }

    melhor = 0;

    for(i = 0; i < n; i++){
        if(salas[i] > 0){
            aux = 0;
            for(j = i; j < n; j++){
                aux += salas[j];
                if(aux > melhor) melhor = aux;
            }
        }
    }

    printf("%i\n", melhor);
    return 0;
}

// Accepted.

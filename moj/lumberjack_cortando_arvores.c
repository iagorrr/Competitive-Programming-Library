// iagorrr ;)
#include <stdio.h>
#include <string.h>
const int MAXL = 1004;
const int ESQUERDA = 2;
const int DIREITA = 8;
const int MAXC = 2004;
char tree[1004][14];
char buff;
int sidelenint = 0;
int L;

void print_linha();
void print_tree();
int check_quebra();
int troca();
int check_morte();
void quebra();
int bate();
void solve(char comand[]){
    print_linha();
    print_tree();
    print_linha();

    for(int i = 0 ; i < strlen(comand); ++i){
        if(comand[i] == 'B'){ 
            if(!bate()){
                print_linha();
                print_tree();
                print_linha();
            }
            else return;
        }
        else{
            if(!troca()){// conseguiu trocar de lado.
                print_linha();
                print_tree();
                print_linha();
            }
        }
    }

}
int main(){
    // altura total da arvore.
    scanf("%i", &L);

    // Montar a arvore e o input.
    for(int i = 0; i < MAXL; ++i){
        if(i < L)
            strcpy(tree[i], "    |||    \n\0");
        else
            strcpy(tree[i], "           \n\0");
    }

    // Galhos.
    int G;
    scanf("%i", &G);
    while(G--){
        char side;
        int pos;

        scanf("%c", &buff);
        scanf("%c", &side);
        scanf("%i", &pos);
        --pos;
        if(side == 'D'){
            tree[pos][10] ='-';
            tree[pos][9] ='-';
            tree[pos][8] ='-';
        }
        else{
            tree[pos][1] ='-';
            tree[pos][2] ='-';
            tree[pos][3] ='-';
        }
            
    }

    // Lado do lenhador de fato.
    char sidelen;
    scanf("%c", &buff);
    scanf("%c", &sidelen);
    if(sidelen == 'E'){
        tree[0][ESQUERDA] = 'L';
        tree[1][ESQUERDA] = 'L';
        sidelenint = ESQUERDA;
    }
    else{
        tree[0][DIREITA] = 'L';
        tree[1][DIREITA] = 'L';
        sidelenint = DIREITA;
    }

    char C[MAXC];
    scanf("%s", C);

    solve(C);
    return 0;
}

void print_linha(){
    printf("~~~~~~~~~~~\n");
}

void print_tree(){
    for(int i = 4; i >= 0; --i){
        printf("%s", tree[i]);
    }
}

int check_quebra(){
    if(sidelenint == ESQUERDA && tree[0][4] == '>') return 1;
    if(sidelenint == DIREITA && tree[0][6] == '<') return 1;

    return 0;
}

int troca(){
    int posw = DIREITA;
    if(sidelenint == DIREITA) posw = ESQUERDA;

    if(tree[0][posw] == '-' || tree[1][posw] == '-'){
        printf("**beep**\n");
        return 1;
    }
    else{
        tree[0][sidelenint] = ' ';
        tree[1][sidelenint] = ' ';

        tree[0][posw] = 'L';
        tree[1][posw] = 'L';

        sidelenint = posw;
        return 0;
    }
}
int check_morte(){
    if(tree[2][sidelenint] == '-') return 1;
    return 0;
}

void quebra(){
    for(int i = 0; i < L; ++i)
        strcpy(tree[i], tree[i+1]);
    
    tree[1][sidelenint] = 'L';
    
    --L;
}

int bate(){
    if(check_quebra()){
        if(check_morte()){ 
            printf("**morreu**\n");
            return 1;
        }
        else if(L == 0){
            printf("**beep**\n");
            return 1;
        }
        else quebra();
    }
    else{
        if(sidelenint == ESQUERDA) tree[0][4] = '>';
        else tree[0][6] = '<';
    }
    return 0;
}

// AC.
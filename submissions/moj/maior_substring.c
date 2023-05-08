// iagorrr ;)
#include <stdio.h>
#include <stdlib.h>
// retorna a primeira posicao da primeira occorrencia de t em s.
int focc(char*s, char* t, int ps, int pt, const int ns, const int nt){
    // processamos a string inteira e nao achamos.
    if(ps == ns)
        return -1;

    // comparando duas posicoes iguais.
    if(s[ps] == t[pt]){
        pt++;
        ps++;
    }
    else{// a cadeia quebrou ali, comecar na proxima de s, se onde quebrou ja for igual a t proxima de s e t.
        pt = 0;
        if(s[ps] == t[pt])
            return focc(s, t, ps+1, pt+1, ns, nt);
        else    
            return focc(s, t, ps+1, pt, ns, nt);

        
    }

    // achamos a string target inteira.
    if(pt == nt)
        return ps - nt;

    // a string nao foi achada.
    if(ps == ns)
        return -1;

    // amentamos a posicao porem nem achamos e nem chegamos ao final, continuar olhando.
    return focc(s, t, ps, pt, ns , nt);
}

// retorna a ultima posicao da ultima ocorrencia de t em s.
int locc(char*s, char* t, int ps, int pt, const int ns, const int nt){
    // processamos s ate o final e nao achamos.
    if(ps == -1)
        return -1;

    if(s[ps] == t[pt]){// match nas posicoes verificar as proximas.
        --ps;
        --pt;
    }
    else{// o match quebrou aqui, olhar nas próxima de s e t se já forem igual, caso contrário só t.
        pt = nt-1; 
        if(s[ps] == t[pt])
            return locc(s, t, ps-1, pt-1, ns, nt);
        else
            return locc(s, t, ps-1, pt, ns, nt);
    }

    // achamos t inteira, retornar a ultima posicao.
    if(pt == -1)
        return ps + nt;
    
    // processamos t inteira e nao achamos deu bo.
    if(ps == -1)
        return -1;

    // deu match na posicao porem nao achamos t inteira e nem processamos s toda, continuar.
    return locc(s, t, ps, pt, ns , nt);
}

// simplesmente retorna o tamanho de s.
int islen(char*s, int n){
    if(*s == '\0') return n;

    return islen(s+1, n+1);
}

int main(){
    char *s = malloc(266*sizeof(char));
    fgets(s, 200, stdin);
    int ns = islen(s, 0)-1;
    if(ns == 0){
        printf("0\n");
        return 0;
    }
    
    char *t = malloc(266*sizeof(char));
    fgets(t, 200, stdin);
    int nt = islen(t, 0)-1;
    

    int f = focc(s, t, 0, 0, ns, nt);
    int l = locc(s, t, ns-1, nt-1, ns, nt);

    int ans = f == -1 && l == -1 ? 0 : l-f+1;
    printf("%d\n", ans);
    return 0;
}

// AC.

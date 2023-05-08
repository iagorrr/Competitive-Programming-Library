#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    map <int, int> chaveTempo;
    map <int, int> tempoTotal;

    int tempoAtual = 0;
    for(int i = 0; i < N; i++){
        char op;
        int value;

        cin >> op >> value;

        if(op == 'T'){
            tempoAtual += value-1;
        }
        else tempoAtual++;

        if(op == 'R'){
            chaveTempo[value] = tempoAtual;
        }

        if(op == 'E'){
            tempoTotal[value] += tempoAtual - chaveTempo[value];
            chaveTempo[value] = 0;
        }
    }
    return 0;
}

// 0/100.

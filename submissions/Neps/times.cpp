#include <bits/stdc++.h>
#define MAX 100005
using namespace std;


int main(){
    int N;
    cin >> N;

    int M;
    int X;
    map <pair<int, int>, bool> V;
    for(int i = 1; i <= N; i++){
        cin >> M;
        for(int j = 0; j < M; j++){
            cin >> X;
            V[{i, X}] = true; // i-ésima pessoa nao gosta da x-ésima pessoa.
        }
    }

    vector <int> timeA;
    vector <int> timeB;
    timeA.push_back(1);

    // Destribuir os times.
    int atual = 2;
    while(timeA.size() + timeB.size() < N){

        // cout << "Atual : " << atual << endl;
        bool aceitoemA = true;
        for(int i = 0; i < timeA.size(); i++){
            if(V[{timeA[i], atual}]){
                aceitoemA = false;
                break;
            }
        }

        if(aceitoemA)   timeA.push_back(atual);
        else   timeB.push_back(atual);

        atual++;
    }

    // Resultado.
    cout << timeA[0];
    for(int i = 1; i < timeA.size(); i++) cout << " " << timeA[i];
    cout << endl;

    cout << timeB[0];
    for(int i = 1; i < timeB.size(); i++) cout << " " << timeB[i];
    cout << endl;
    return 0;
}
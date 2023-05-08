#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    lli totalAmigos, totalMusicas, tocada;
    cin >> totalAmigos >> totalMusicas >> tocada;

    vector <pair<lli, lli>> amigos(totalAmigos);// gosta destesta.
    map <lli, vector<lli>> detestadas; // musica,[quem detesta, quem detesta2]...
    for(int i = 0; i < totalAmigos; i++){
        cin >> amigos[i].first >> amigos[i].second;
        detestadas[amigos[i].second].push_back(i);
        sort(detestadas[amigos[i].second].begin(), detestadas[amigos[i].second].end());
    }

    // Mudando até geral gostar.
    lli totalMoves = 0;
    map <int, bool> jaChecada;
    while(!detestadas[tocada].empty()){
        totalMoves++;

        // Verificar se já foi checada antes.
        if(jaChecada[tocada]){
            cout << -1 << endl;
            return 0;
        }
        jaChecada[tocada] = true;

        tocada = amigos[detestadas[tocada][0]].first;
    }
    cout << totalMoves << endl;
    return 0;
}

//30/100
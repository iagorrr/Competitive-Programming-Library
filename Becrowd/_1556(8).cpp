#include <bits/stdc++.h>
using namespace std;

map <string,bool> visitados;


// Bugado pra krlllll.
void bfs(string analisada){

    visitados[analisada] = true;
    char removido;
    for(int i = 0; analisada.size(); i++){
        removido = analisada[i];
        analisada.erase(i,1);
        if(analisada.size() > 0 and visitados.count(analisada) == false){
            bfs(analisada);
        }
        analisada.insert(i,1, removido);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string palavra;

    while(cin >> palavra){
        bfs(palavra);
        for(auto& ans : visitados){
            cout << ans.first << "\n";
        }
        visitados.clear();
    }


    return 0;
}
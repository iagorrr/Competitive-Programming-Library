//iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> grafo[100000+4];
int familias = 0;
bool check[100000+4];
int n, m;

/*
    Abordagem considerando grafos em lista de adjacência.
    Pra cada vértice, verificar todas as arestas.
    O(delta)
*/
void dfs(int x){
    check[x] = true;
    for(int i = 0; i < grafo[x].size(); ++i){
        if(!check[grafo[x][i]]) dfs(grafo[x][i]);
    }
}
void count_famalies(){
    
    for(int i = 0; i < n; ++i){
        if(!check[i]){ dfs(i); familias++;}
    }
}


int main(){
    cin >> n >> m;

    /*
        Grafo com n vértices e biderecional.
    */
    int a, b;
    for(int i = 0; i < m; ++i){
        cin >> a >> b;
        a--;
        b--;

        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }

    count_famalies(); 
    cout << familias << endl;
    return 0;
}

// 100/100


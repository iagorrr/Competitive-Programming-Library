// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct state{
    ll moves;
    ll cost;
    array<array<int, 4>, 2> cont;
};


ll bfs(const state initial, const state end){
    map< array<array<int, 4>, 2>, bool> check;
    queue<state> q;
    
    q.push(initial);
    check[initial.cont] = true;
    ll ans = LLONG_MAX;

    while(!q.empty()){
        state current = q.front(); q.pop();

        if(current.cont == end.cont){
            ans = min(ans, current.cost);
            continue;
        }

        for(int i = 0 ; i < 4; ++i){
            state moved = current;
            swap(moved.cont[0][i], moved.cont[1][i]);
            moved.cost += moved.cont[0][i] + moved.cont[1][i];

            if(!check[moved.cont]){
                ++moved.moves;
                check[moved.cont] = true;
                q.push(moved);
            }
        }

        for(int i = 0; i < 2; ++i){
            for(int j = 0; j < 3; ++j){
                state moved = current;
                swap(moved.cont[i][j], moved.cont[i][j+1]);
                moved.cost += (moved.cont[i][j] + moved.cont[i][j+1]);

                if(!check[moved.cont]){
                    ++moved.moves;
                    check[moved.cont] = true;
                    q.push(moved);
                }
            }
        }
    }

    return ans;
}

int main(){
    state initial;
    for(int i = 0; i < 2; ++i)
        for(int j = 0; j < 4; ++j)
            cin >> initial.cont[i][j];
    initial.moves = 0;
    initial.cost = 0;

    state end;
    for(int i = 0; i < 2; ++i)
        for(int j = 0; j < 4; ++j)
            cin >> end.cont[i][j];
    
    cout << bfs(initial, end) << '\n';
    return 0;   
}

// TLE, WA
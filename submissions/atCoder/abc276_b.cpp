// iagorrr ;)
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;

    vector<vector<int>> city(n+1);   

    for(int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;
        city[a].push_back(b);
        city[b].push_back(a);
    }

    for(int i = 1; i <= n; ++i){
        sort(city[i].begin(), city[i].end());
        cout << city[i].size() << ' ';
        
        for(int j = 0; j < city[i].size(); ++j){
            cout << city[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}

// AC.
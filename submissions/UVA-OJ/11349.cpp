// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool solve(const vector<vector<ll>> M, const ll N){
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            if(M[i][j] != M[N-i-1][N-j-1] || M[i][j] < 0)
                return false;
        }
    }

    return true;
}
int main(){
    int t;
    cin >> t;

    for(int i =1; i <= t; ++i){
        ll N;
        string s;
        cin >> s;
        cin >> s;
        cin >> N;

        vector<vector<ll>> M (N, vector<ll>(N));
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < N; ++j)
                cin >> M[i][j];

        cout << "Test #" << i << ": " << (solve(M, N) ? "Symmetric." : "Non-symmetric.") << '\n';
    }

    return 0;
}
// AC.

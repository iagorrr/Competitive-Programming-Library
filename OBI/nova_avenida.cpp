#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

int dy[] = {1, 0, -1, 0};
int dx[] = {0, -1, 0, 1};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    lli N, M;
    cin >> N >> M;

    vector <lli> colunas(M,0);
    lli temp;
    for(lli i = 0; i < N; i++){
        for(lli j = 0; j < M; j++){
            cin >> temp;
            colunas[j] += temp;
        }
    }

    sort(colunas.begin(), colunas.end());
    cout << colunas[0] << endl;
    return 0;
}

// 100/100

#include <bits/stdc++.h>
#define MAXN 100000
#define MAXM 100000

using namespace std;

int favorita[MAXM];
bool check[MAXM];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M, C;
    cin >> N >> M >> C; 
    
    for(int i = 0; i < N; i++){
        int A, B;
        cin >> A >> B;
        if(favorita[B] == 0) favorita[B] = A;
    }

    int totalChecks = 0;
    while (favorita[C] != 0){
        if(check[C]){
            cout << -1 << endl;
            return 0;
        }
        check[C] = true;
        C = favorita[C];
        totalChecks++;
    }

    cout << totalChecks << endl;
    return 0;
}

// 100/100
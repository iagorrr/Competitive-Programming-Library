// Iagorr ;)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef unsigned long long int ulli;
typedef long long int lli;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;

    lli  T[N];
    ulli totalTime=0;
    for(int i = 0; i < N; i++){
        cin >> T[i];
        totalTime += T[i];
    }

    int M;
    cin >> M;
    int P;
    int X;
    int dx;
    for(int i = 0; i < M; i++){
        cin >> P >> X;
        dx = T[P-1] - X;
        cout << totalTime - dx << endl; 
    }


    return 0;
}

// Accepted.

#include <bits/stdc++.h>

using namespace std;
vector <int> V(101);
int N;
string sampleS = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
void solve(){// Mudar a string exatamente na posição que precisa ser diferente.
    cout << sampleS << endl;
    for(int i = 0; i < N; i++){
        if(sampleS[V[i]] == 'a') sampleS[V[i]] = 'b';
        else sampleS[V[i]] = 'a';
        cout << sampleS << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;

    while(T--){
        cin >> N;
        for(int i = 0; i < N; i++) cin >> V[i];
        solve();
        
    }
    return 0;
}

// Accepted.
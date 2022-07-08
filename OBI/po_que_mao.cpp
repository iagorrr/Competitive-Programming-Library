#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector <int> V(3);
    for(int i = 0; i < 3; i++) cin >> V[i];
    sort(V.begin(), V.end());
    
    int ans = 0;
    for(int i = 0; i < 3; i++){
        if(N >= V[i]) ans++;
        N -= V[i];
    }

    cout << ans << endl;;
    return 0;
}

// Aceito.

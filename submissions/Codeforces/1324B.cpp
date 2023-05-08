// iagorrr
#include <bits/stdc++.h>

using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        
        vector <int> V(N);
        for(int i = 0; i < N; i++) cin >> V[i];

        // Só precisa de dois números não consecutivos iguais pra formar um palindromooooo.
        bool achou = false;
        for(int l = 0; l < N; l++){
            for(int r = l + 2; r < N; r++){
                if(V[l] == V[r]){
                    achou = true;
                    break;
                }
            }

            if(achou) break;
        }

        if(achou) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
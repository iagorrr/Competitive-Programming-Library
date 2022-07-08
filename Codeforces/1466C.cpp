// iagorrr ;)
#include <bits/stdc++.h>

using namespace std;

// Já que usa so letra minuscula substituir por qualquer um ae e é isso.
int solve(string S){
    int ans = 0;
    for(int l = 0; l < S.size(); l++){
        int r = 1;
        while(r < 3 && l+r < S.size()){
            if(S[l] == S[l+r] && S[l] != 'X'){
                ans++;
                S[l+r] = 'X';
            }
            r++;
        }
    }

    return ans;
}

int main(){
    int T;
    cin >> T;

    while(T--){
        string S;
        cin >> S;
        cout << solve(S) << endl;
    }
    return 0;
}

// Accepted.

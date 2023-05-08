// iagorrr ;)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;

    while(T--){
        int N, K;
        string S;
        
        cin >> N >> K;
        cin >> S;

        int equal = 0;
        int l = 0;
        int r = N-1;
        while(S[l] == S[r] && l < r && r > K && l < K){
            equal++;
            l++;
            r--;
        }

        if(equal >= K) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}

// Accepted.
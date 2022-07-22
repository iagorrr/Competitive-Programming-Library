// iagorrr O(N)
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll solve(string k, string w){
    map <char, int> posk;

    ll ans = 0;
    for(ll i = 0; i < k.size(); i++){
        posk[k[i]] = i;
    }

    for(ll i = 1; i < w.size(); i++){
        ans += max(posk[w[i]] - posk[w[i-1]], posk[w[i-1]] - posk[w[i]]);
    }
    return ans;
}

int main(){
    ll T;
    cin >> T;

    while(T--){
        string keyboard;
        cin >> keyboard;
        string word;
        cin >> word;
        cout << solve(keyboard, word) << endl;
    }
    return 0;
}

// AC.
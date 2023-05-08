// iagorrr ;) O(k) ?
#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
    
// vericficar quanto cada um tem que repetir.
void solve(ll k){
    string ans0 = "codeforces";
    ll x = 1;
    vector <int> r(10, 1);
    int rpos = 0;
    while(x < k){
        x /= r[rpos];
        r[rpos]++;
        x *= r[rpos];
        rpos++;
        if(rpos == 10) rpos = 0;
    }

    for(int i = 0; i < 10; ++i){
        for(int j = 0; j < r[i]; j++){
            cout << ans0[i];
        }
    }
    
    cout << endl; 

}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll k;
    cin >> k;

    solve(k);

    return 0;
}

// Accepted.

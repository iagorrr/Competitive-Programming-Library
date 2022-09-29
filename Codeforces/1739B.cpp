// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio = ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0):
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;

inline void solve(const vector<int> &a, const int n){
    vector<int> aux(n);
    aux[0] = a[0];

    for(int i  = 1; i < n; ++i){
        if(aux[i-1] >= a[i] and a[i] != 0){
            cout << -1 << '\n';
            return;
        }
        aux[i] = aux[i-1]+a[i];
    }

    for(auto x : aux) cout << x << ' ';
    cout << '\n';
}
int main(){ 
    int t;

    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> a(n);
        for(auto &x : a) cin >> x;

        solve(a, n);
    }
    return 0;
}

// Accepted.

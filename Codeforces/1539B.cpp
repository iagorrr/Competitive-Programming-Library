// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;

int main(){
    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    // to use the string as 1-index.
    string s2 {'#' + s};

    // prefix sum based in the result of each substring. )(n)
    vector<ll> psum(n+1, 0);
    for(int i = 1; i < s2.size(); ++i) psum[i] = psum[i-1] + s2[i]-'a'+1;

    // answer the queries in constant time. O(q)
    while(q--){
        ll l, r;
        cin >> l >> r;
        cout << psum[r] - psum[l-1] << '\n';
    }
    
    return 0;
}

// Accepted.

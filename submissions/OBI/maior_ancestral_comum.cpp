// iagorrr ;) lcs
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<long long>;

ll lcs(vector<long long> a, vector<long long> b){
    ll m = a.size();
    ll n = b.size();
    ll lcsdp[m+1][n+1];

    for(ll i = 0; i <= m; ++i){
        for(ll j = 0; j <= n; ++j){
            if(i == 0 || j == 0) lcsdp[i][j] = 0;
            else if (a[i-1] == b[j-1]) lcsdp[i][j] = lcsdp[i-1][j-1] + 1;
            else lcsdp[i][j] = max(lcsdp[i-1][j], lcsdp[i][j-1]);
        }
    }

    return lcsdp[m][n]; 
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll m, n;

    cin >> m >> n;

    vll a(m);
    for(ll i = 0; i < m; ++i) cin >> a[i];
    vll b(n);
    for(ll i = 0; i < n; ++i) cin >> b[i];

    // the lcs is the greater ancestral.
    ll lcsa = lcs(a, b);
    cout << m - lcsa << " " << n - lcsa << endl;
    return 0;
}

// ac.
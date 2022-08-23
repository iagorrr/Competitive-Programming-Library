// iagorrr NlongN 
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<long long>;

ll lis_char(string s){
    // inicializtion.
    ll n = s.size();
    ll INF = LLONG_MAX;
    vll d(n+1, INF);
    d[0] = -INF;

    for(ll i = 0; i < n; ++i){
        ll j = upper_bound(d.begin(), d.end(), s[i]) - d.begin();

        if(d[j-1] <= s[i] && s[i] <= d[j]) d[j] = s[i];
    }

    ll ans = 0;
    for(ll i = 0; i <= n; ++i)
        if(d[i] < INF) ans = i;

    return ans;
}

int main(){
    string s;
    cin >> s;
    cout << lis_char(s) << endl;

    return 0;
}

// AC.


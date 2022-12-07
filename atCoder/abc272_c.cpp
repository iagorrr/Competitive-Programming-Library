// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;

int main(){ 
    fastio
    ll n;
    cin >> n;

    vector<ll> even;
    vector<ll> odd;
    while(n--){
        ll x;
        cin >> x;

        if(x&1) odd.push_back(x);
        else even.push_back(x);
    }

    if(even.size() <= 1 and odd.size() <= 1){
        cout << -1 << '\n';
    }
    else{
        sort(odd.begin(), odd.end(), greater<ll>());
        sort(even.begin(), even.end(), greater<ll>());
        if(even.size() <= 1)
            cout << odd[0] + odd[1] << '\n';
        else if (odd.size() <= 1)
            cout << even[0] + even[1] << '\n';
        else
            cout << max(odd[0]+odd[1], even[0]+even[1]) << '\n';
        
    }
    return 0;
}

// AC.

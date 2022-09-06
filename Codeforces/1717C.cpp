// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string solve(vector<ll> a, vector<ll> b, ll n){
    bool check = true;
    for(ll i = 0; i < n; ++i){
        if(a[i] != b[i] and b[i] - b[(i+1) % n] > 1){
            check = false;
            break;            
        }

        if(a[i] > b[i]){
            check = false;
            break;
        }
    }


    return check ? "YES" : "NO";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector <ll> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        
        vector<ll> b(n);
        for(int i = 0;  i < n; ++i) cin >> b[i];

        cout << solve(a, b, n) << endl;
    }

    return 0;
}

// AC

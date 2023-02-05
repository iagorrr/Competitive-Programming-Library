// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
#define minpq  priority_queue<ll, vll, greater<ll>()>
//•¨•.¸¸♪main•¨•.¸¸♪(　-ω-)ノ　(　・ω・)
int32_t main(void){ fastio;
    ll t; cin >> t;

    while(t--){
        ll n; cin >> n;

        vll a(n); for(auto &x : a ) cin >> x;

        ll sum = 0; for(auto x: a) sum += x;

        bool lessplus = false;
        bool lessless = false;
        bool plusplus = false;

        for(int i =0; i < n-1; ++i){
            if(a[i] == -1 and a[i+1] == -1) lessless=true;
            if(a[i] == 1 and a[i+1] == -1) lessplus = true;
            if(a[i] == -1 and a[i+1] == 1) lessplus = true;
            if(a[i] == 1 and a[i+1] == 1) plusplus =true;
        }
        if (lessless){
            sum += 4;
        }
        else if (lessplus){
            sum += 0;
        }
        else if (plusplus){ sum -= 4;}

        cout << sum << '\n';
    }
}

// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
#define minpq  priority_queue<ll, vll, greater<ll>()>
//•¨•.¸¸♪main•¨•.¸¸♪(　-ω-)ノ　(　・ω・)

ll fac(ll x){
    ll ans =1;

    for(int i = 1; i <= x; ++ i){
        ans *= i;
    }
    return ans;
}
int32_t main(void){ fastio;
    string s; cin >> s;

    string t;
    for(auto c : s){
        if(c!= '/'){
            t.push_back(c);
        }
    }
    set<string> a;
    ll ans = 0;
    sort(t.begin(), t.end());
    do {
        if(not a.count(t)) ans++;

        a.insert(t);
    }while(next_permutation(t.begin(), t.end()));
    cout << ans << '\n';
}

// AC.

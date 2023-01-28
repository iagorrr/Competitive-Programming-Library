// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
//•¨•.¸¸♪main•¨•.¸¸♪(　-ω-)ノ　(　・ω・)
int main(){ 
    fastio
    ll n;
    cin >> n;

    map<ll, ll> points;
    for(int i = 1; i <= n; ++i){
        ll a;
        cin >> a;
        points[i] = a;
    }

    set<ll> visited;
    ll moves = 0;
    ll cur=1;
   
    while(true){
       ++moves;
       cur = points[cur];
       if(cur == 2){
           cout << moves << '\n';
           return 0;
       }
       if(moves > n+6) break;
    }
    cout << -1 << '\n';

    return 0;
}

// AC.

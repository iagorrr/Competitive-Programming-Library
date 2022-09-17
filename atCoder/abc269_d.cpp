// iagorrr ;)
#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;

map<pll, bool> check;
map<pll, bool> exist;
vector<pll> pairs;

ll  ans = 0;

void flood(pll current){
    // visited.
    check[current] = true;

    // mark as chekc every neighbor.
    ll dx[] = {0, 1, 1, 0, -1, -1};
    ll dy[] = {1, 1, 0, -1, -1, 0};
    for(ll i = 0; i < 6; ++i){
        pll temp = current;
        temp.first += dx[i];
        temp.second += dy[i];

        if(exist[temp] and !check[temp]) flood(temp);
    }
}
int main(){
    ll n;
    cin >> n;

    for(ll i = 0; i < n; ++i){
        pll xy;
        cin >> xy.first >> xy.second;
        exist[xy] = true;
        pairs.push_back(xy);
    }

    for(ll i = 0; i < n; ++i){
        // already connect to another one.
        if(check[pairs[i]]) continue;

        // not connect is a new group mar every adjacent.
        flood(pairs[i]);

        ans++;
    }
    
    cout << ans << '\n';
    return 0;
}

// Accepted.

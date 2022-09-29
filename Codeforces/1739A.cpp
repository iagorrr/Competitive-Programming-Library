// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;

pair <int ,int> solve(int n, int m){
    if(n == 1 ||   m == 1){
        return {n, m};
    }
    
    if(n == 2 and m == 2){
        return {1, 1};
    }

    if(n == 3 and m == 3){
        return {2, 2};
    }

    if(n == 2 and m == 3){
        return {1, 2};
    }
    if(n == 3 and m == 2){
        return {2, 1};
    }
    return {n, m};
}
int main(){ 
    fastio

    int t;
    cin >> t;

    while(t--){
        int n, m;
        cin >> n >> m;

        auto ans = solve(n, m);
        cout << ans.first << ' ' << ans.second << '\n';
    }
    return 0;
}

// Accepted.

// iagorr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
const int maxn = 1000;

inline ll solve(const int x){
    ll ans = 1;

    for(int i = 2; i <= x; ++i) ans = ans + (i-1)*4;
    
    return ans;
}

int main(){
    fastio;
    ll n;
    cin >> n;

    
    cout << solve(n) << '\n';
    return 0;
}

// Accepted.
// iagorr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
const int maxn = 1000;

ll dp[maxn];
ll solve(int x){

    // already calculed.
    if(dp[x] != -1) return dp[x];

    dp[x] = solve(x-1) + (x-1) * 4;
    return dp[x];
}
int main(){
    fastio;
    ll n;
    cin >> n;

    memset(dp, -1, sizeof(dp));
    dp[1] = 1;
    cout << solve(n) << '\n';
    return 0;
}
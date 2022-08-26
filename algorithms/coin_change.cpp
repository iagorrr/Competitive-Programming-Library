/*  
    Coin change problem, find the mininum of coins necessary to pay a given value.
    O(NM)
    source : https://github.com/edsomjr/TEP/blob/master/Paradigmas/slides/coin_change/coin_change.pdf
*/
#include <bits/stdc++.h>
#define MAX_N 1010000
using namespace std;
using ll = long long;

/*
    dp[m] the mininum number of coins necessary to pay m.

    to calculate m, we find the minimum if for each m-coin we can take.

    dp[m] min{ dp[m-c[0]], ... dp[m-c[n]]} + 1

    the '+1' comes from the coin we took...

    in this case we assume that is possible to sum the valus to get M.
*/
vector <ll> dp(MAX_N, -1);
ll coin_change(ll m, const vector<ll>& coins)
{
    if (m == 0)
        return 0;

    if (dp[m] != -1)
        return dp[m];

    ll res = LLONG_MAX;

    for (auto c : coins)
        if (c <= m)
            res = min(res, coin_change(m - c, coins) + 1);

    dp[m] = res;
    return res; 
}

int main()
{
    ll N, M;
    cin >> N >> M;

    vector<ll> cs(N);

    for (ll i = 0; i < N; ++i)
        cin >> cs[i];

    cout << (coin_change(M, cs) != -1 ? "S" : "N") << '\n';

    return 0;
}
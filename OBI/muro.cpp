// iagorrr ;)
/*
    Pelo enunciado sabemos que existem para :
        n-2 : 4 jeitos de finalizar.
        n-3 : 2 jeitos de finalizar.
        n-1 : 1 jeito de finalizar.

        se n == 0, somente 1 jeito, zero tijolos.

        portanto pela combinatória tem-se que para  N será as soma de:
            dp[n-2] * 4, pois para todas as dp[n-2] formas de preencher um muro com n-2 de largura,
            tem-se mais 4 possibilidades.

            dp[n-3] * 2, pois para todas os jeitos de preencher um muro com dp[n-3] de laregura,
            tem-se mais 2 possilidades,

            e dp[n-1], analogamente.

    */
#include <bits/stdc++.h>
using namespace std;
using ll =  long long;
const ll MOD = 1e9+7;
const int maxn = 1e4+4;

ll dp[maxn];

ll solve(ll n){
    // impossível.
    if(n < 0) return 0;

    // já calculamos esse valor.
    if(dp[n] != 0) return dp[n];
    
    dp[n] = (solve(n-1) + solve(n-2)*4 + solve(n-3)*2)%MOD;
    return dp[n];
}
int main(){
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    int n = 0;

    cin >> n;

    ll ans = solve(n);

    cout << ans << '\n';


    return 0;
}

// 100/100 aceito.
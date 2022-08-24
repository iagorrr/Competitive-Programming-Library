/*
   The backpack problem : given the maximum weight you can carry, and n items with w_i weight, and v_i value,
   maximize the value, without overflow the maximum weight.

   O(N*S)
   - because there is n*s states, and for each one the cost is O(1) to calculate.
*/
#include <bits/stdc++.h>
#define MAX_N 10000
#define MAX_M 10000
using namespace std;
using ll = long long;
using vll = vector<long long>;

/*
   decrease the second parameter of the dp, to verify if is possible to add the element...
*/

ll dp[MAX_N][MAX_M];
bool check[MAX_N][MAX_M];

pair<ll, vector<int>> knapsack(int M, const vector<pair<ll,ll>>& cs)
{
    int N = (int) cs.size() - 1;  // Os elementos começam em 1

    // Casos-base
    for (int i = 0; i <= N; ++i)
        dp[i][0] = 0;

    for (int m = 0; m <= M; ++m)
        dp[0][m] = 0;

    // Transições
    for (int i = 1; i <= N; ++i)
    {
        for (int m = 1; m <= M; ++m)
        {
            dp[i][m] = dp[i - 1][m];
            check[i][m] = false;

            auto [w, v] = cs[i];

            if (w <= m and dp[i - 1][m - w] + v > dp[i][m])
            {
                dp[i][m] = dp[i - 1][m - w] + v;
                check[i][m] = true;
            }
        }
    }

    // Recuperação dos elementos
    int m = M;
    vector<int> is;

    for (int i = N; i >= 1; --i)
    {
        if (check[i][m])
        {
            is.push_back(i);
            m -= cs[i].first;
        }
    }

    reverse(is.begin(), is.end());

    return { dp[N][M], is };
}

int main()
{   
    srand(time(NULL));
    
    ll m, n;
    cout << "total elements : ";
    cin >> n;
    cout << "max weight : ";
    cin >> m;
    vector<pair<ll, ll>> cs(n );
    for(ll i = 0; i < n; ++i){
        cs[i].first = rand()%10;
        cs[i].second = rand()%10;
        cout << "[" << cs[i].first << "," << cs[i].second  <<"] ";
    }
    cout << endl;
    auto [ans, is] = knapsack(m, cs);

    cout << "max value: " << ans << '\n';

    cout << "elements: ";
    for (auto i : is)
        cout << i << ' ';
    cout << '\n';

    return 0;
}
// iagorr ;)
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100+4;
const int MAXM = 100+4;

bool check[MAXN][MAXM];
bool dp[MAXN][MAXM];
bool solve(int x, int y, int k){
    // ground cases.
    if(x == 1 and y == 1){
        if(k == 0) dp[1][1] = true;
        else dp[1][1] = false;

        return dp[1][1];
    }

    // already calculed this poistion.
    if(check[x][y]) return dp[x][y];

    /*
        Is only possible to get at (x, y) spendint k, if was possible to get at:
            (x-1, y) spending k-y
                    or
            (x, y-1) spending k-x
    */
    bool left = false;
    if(x-1 > 0) left = solve(x-1, y, k-y);

    bool up = false;
    if(y-1 > 0) up = solve(x, y-1, k-x);
    dp[x][y] = (up || left);

    /*
        Mark as check so this position wont be calculed again.
    */
    check[x][y] = true;
    return dp[x][y];
}
int main(){
    int t;
    cin >> t;

    while(t--){
        int n, m, k;
        cin >> n >> m >> k;

        // as there is many queries rest it.
        memset(check, false, sizeof(check));
        memset(dp, false, sizeof(dp));

        cout << (solve(n, m, k) ? "YES" : "NO") << '\n';
    }
}

// Accepted.

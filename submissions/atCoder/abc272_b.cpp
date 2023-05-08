// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;

int main(){ 
    fastio
    int n, m;
    cin >> n >> m;

    vector<vector<bool>> check(n+1, vector<bool>(n+1));
    int cnt = 0;
    for(int i = 0; i < m; ++i){
        int k;
        cin >> k;
        vector<int> a(k);
        for(int j = 0; j < k; ++j)
            cin >> a[j];

        sort(a.begin(), a.end());
        for(int j = 0; j < k; ++j){
            for(int j2 = 0; j2 < k; ++j2){
                if(!check[a[j]][a[j2]]){
                    check[a[j]][a[j2]] = true;
                    cnt++;
                }
            }
        }
    }

    cout << (cnt == n*n ? "Yes" : "No") << '\n';
    return 0;
}

// AC.

// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
//•¨•.¸¸♪main•¨•.¸¸♪(　-ω-)ノ　(　・ω・)
int main(){ 
    fastio;
    ll n, m;
    cin >> n >> m;

    vector<ll> a(n,0);
    ll ans = 0;
    for(int i = 0; i < n; ++i){
        string s;
        cin >> s;

        reverse(s.begin(), s.end());
        for(int j = 0; j < s.size(); ++j){
            if(s[j] == 'o') a[i] += (1<<j);
        }
        // cout << "a " << i << ' ' << a[i] << '\n';
    }

    for(int i = 0; i < n; ++i){
        for(int j = i+1; j < n; ++j){
            // cout << i+1 << ' ' << j+1 << ' '<< a[i] << ' ' << a[j]<< '\n';
            if((a[i]|a[j]) == (1<<m)-1){ 

                ans++;
            }
        }
    }

    cout << ans << '\n';
    return 0;
}

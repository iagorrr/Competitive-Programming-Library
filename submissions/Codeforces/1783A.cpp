// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
#define minpq  priority_queue<ll, vll, greater<ll>()>
//•¨•.¸¸♪main•¨•.¸¸♪(　-ω-)ノ　(　・ω・)
int main(){ 
    fastio;
	
    ll t; cin >> t;

    while(t--)
    {
        ll n; cin >> n;

        vector<ll> a(n); for(auto &x : a) cin >> x;
        sort(a.begin(), a.end(), greater<>());

        ll e = 0;
        for(int i = 1; i < n; ++i)
        {
            if(a[i] == a[0]) e++;
        }

        if(e > 0)
        {
            if(n==e+1)
            {
                cout <<"NO\n";
                continue;
            }
            else
            {
                swap(a[0],a[n-1]);
            }
        }
        
        cout << "YES\n";
        for(auto x : a) cout << x << ' '; cout << '\n';

    } 

    return 0;

}
// AC.

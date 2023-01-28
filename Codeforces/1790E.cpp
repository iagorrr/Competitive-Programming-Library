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
            ll x; cin >> x;
            ll x2 = x/2; 
            if(x2+x2*3 == x*2 and (x2^(x2*3)) == x)
            {
                cout << x2 << ' ' << x2*3 << '\n';
            }
            else 
            {
                cout << -1 << '\n';
            }
        }
    }

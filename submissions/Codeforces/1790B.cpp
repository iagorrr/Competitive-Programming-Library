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
    //fastio;
    ll t; cin >> t;
 
    while(t--)
    {
        ll n, s, r; cin >> n >> s >> r;
 
        vector<int> ans;
        int biggest = s-r;
        ans.push_back(biggest);
 
        for(int i =0; i < n-1; ++i) ans.push_back(1);
        
        int sum = biggest + n-1;
        while(sum != s)
        {
            for(int i = 1; i < n; ++i)
            {
                if(ans[i] < biggest)
                {
                    ans[i]++;
                    sum++;
                }
                if(sum == s) break;
            }
        }  
 
        for(auto x : ans) cout << x << ' '; cout << '\n';
    }
}
// AC.

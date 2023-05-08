// iagorrr ;)
// Implementation
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
#define minpq  priority_queue<ll, vll, greater<ll>()>
//•¨•.¸¸♪main•¨•.¸¸♪(　-ω-)ノ　(　・ω・)

int solve(vector<vector<int>> wall){
    unordered_set<int> viewed;
    set<int> current;
    for(auto i : wall)
    {
        for(auto j : i)
        {
            if(j > 0) current.insert(j);
            else if(current.count(-j)) current.erase(-j);
        }
        if(current.size()) viewed.insert(*current.rbegin());
        
    }

    return viewed.size();
}
int main(){ 
    //fastio;
    int t;
    cin >> t;

    while(t--){
        ll q;
        cin >> q;

        vector<vector<int>> wall(1e7+6);
        for(int i = 1; i <= q; ++i)
        {
            int l, r;
            cin >> l >> r;
            wall[l].push_back(i);
            wall[r+1].push_back(-i);
        }

        cout << solve(wall) << '\n';
            
        
    }
    return 0;
}

// AC.
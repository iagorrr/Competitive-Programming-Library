// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;

int dif(char a, char b){
    int x = a-'a';
    int y = b-'a';
    return max(x-y, y-x);
}
void solve(const string &s){
    bool rising = s[0] <= s[(int)s.size()-1] ? true : false;

    vector<pair<char, int>> order;  
    int i = 1; 
    for(auto c : s){
        order.push_back({c, i});
        ++i;
    }

    sort(order.begin(), order.end());
    vector<int> ans;
    int cost = 0;
    int total_jump = 0;

    
    
    i = 0;
    while(order[i].second != 1){
        ++i;
    }

    if(rising){
        ++i;
        ans.push_back(1);
        total_jump++;
        while(order[i].second != (int)s.size()){
            ans.push_back(order[i].second);
            cost += dif(order[i].first, order[i-1].first);
            total_jump++;
            ++i;
        }
        ans.push_back((int)s.size());
        total_jump++;
        cost += dif(order[i].first, order[i-1].first);
    }
    else {
        --i;
        ans.push_back(1);
        total_jump++;
        while(order[i].second != (int)s.size()){
            ans.push_back(order[i].second);
            cost += dif(order[i].first, order[i+1].first);
            total_jump++;
            --i;
        }
        ans.push_back((int)s.size());
        total_jump++;
        cost += dif(order[i].first, order[i+1].first);
    }
    
    cout << cost << ' ' << total_jump << '\n';
    for(auto x : ans) cout << x << ' ';
    cout << '\n';
    
}
int main(){
    // ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    
    while(t--){
        string s;
        cin >> s;
        solve(s);
    }


    return 0;
}

// AC.
// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(string s, ll p){
    priority_queue<pair<char, int>, vector<pair<char,int>>, greater<pair<char,int>>> pq;// min heap

    // to get it in order.
    for(int i = 0; i < s.size(); ++i)
        pq.push({s[i], i});

    
    ll sum = 0;
    set<int> valid;

    while(!(pq.empty()) and sum + (pq.top().first - 'a'+1) <= p){
        sum += pq.top().first-'a'+1;
        valid.insert(pq.top().second);
        pq.pop();
    }
    
    for(auto c : valid)
        cout << s[c];
    cout << '\n';    
}

int main(){
    int t;
    cin >> t;

    while(t--){
        string s;
        ll p;
        cin >> s >> p;

        solve(s, p);
    }

    return 0;
}

// Accepted.

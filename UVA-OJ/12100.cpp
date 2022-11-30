// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;

int solve(deque<pair<int, int>> a, priority_queue<int> pq, int m){
    int ans = 0;


    while(!a.empty()){
        auto c = a.front(); a.pop_front();

        // is the larger one in the list.
        if(c.first == pq.top()){
            ans++;
            pq.pop();
            
            // printed the one i wanted.
            if(c.second == m)
                return ans;
        }
        else{// just put it back bro.
            a.push_back(c);
        }
    }
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n, m;
        cin >> n >> m;

        deque<pair<int, int>> a(n);
        priority_queue<int> pq;

        for(int i = 0; i < n; ++i){
            cin >> a[i].first;
            a[i].second = i;
            pq.push(a[i].first);
        }

        cout << solve(a, pq, m) << '\n';
    }
}
// AC.

// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;

vector <int> solve(int n){
    vector<int> ans;
    
    int x = n/2 + 1;
    int d = 1;
    for(int i = 1; i <= n; ++i){
        if(i&1) ans.push_back(x++);
        else ans.push_back(d++);
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        auto ans = solve(n);
        for(auto x : ans) cout << x << ' ';
        cout << '\n';
    }

    return 0;
}

// Accepted.
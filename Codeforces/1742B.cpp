// iagorr ;)
#include <bits/stdc++.h>
using namespace std;

string solve(vector<int> a, int n){
    map<int, bool> check;

    for(auto x : a){
        if(check[x]) return "NO";

        check[x] = true;
    }

    return "YES";
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> a(n);
        for(auto &x : a) cin >> x;

        cout << solve(a, n) << '\n';
    }
    return 0;
}

// Accepted.

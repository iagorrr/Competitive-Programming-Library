// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;

/*
    Sorting in non-ascending order will can always increase the a[i] number if it is not in the 
    'check' already, beacause if a[k] == a[i] you can increase a[k], as you had already increased a[i].
*/

int solve(vector<int> a, const int n){
    int ans = 0;

    sort(a.begin(), a.end(), greater<int>());
    map <int, bool> check;
    for(int i = 0; i < n; ++i){
        if(!check[a[i]+1]){
            check[a[i]+1] = true;
            ans++;
        }
        else if(!check[a[i]]){
            check[a[i]] = true;
            ans++;
        }
    }

    return ans;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
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
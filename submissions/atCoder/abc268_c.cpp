// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;

int solve(const vector<int> a, int n){
    // save how many moviments each dish can do.
    map<int,int> satis;

    
    for(int i = 0; i < n; ++i){
        int A;
        // to i.
        if(a[i] <= i) A = i - a[i];
        else A = i + 1 +n-1 - a[i];
        satis[A]++; 

        // to i-1.
        if(a[i] <= i-1) A = i-1 - a[i];
        else A = i-1 + 1 +n-1 - a[i];
        satis[A]++;

        // to i + 1.
        if(a[i] <= i+1) A = i+1 - a[i];
        else A = i+1 + 1 +n-1 - a[i];
        satis[A]++;
    }

    int ans = -1;
    for(auto [num, qtd] : satis){
        ans = max(ans, qtd);
    }

    return ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for(auto &x: a) cin >> x;

    cout << solve(a, n) << '\n';

    return 0;
}

// AC.
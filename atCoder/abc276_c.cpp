// iagorrr ;)
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;

    vector<int> p(n);
    for(auto &x : p) cin >> x;

    prev_permutation(p.begin(), p.end());
    for(auto x : p) cout << x << ' ';
    cout <<'\n';    

    return 0;
}
// Accepted.
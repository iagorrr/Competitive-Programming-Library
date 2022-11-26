// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;

string solve(string s){
    string ans;

    ans = s;
    reverse(s.begin(), s.end());
    ans += s;
    return ans;
}
int main(){ 
    fastio
    ll n;
    cin >> n;

    while(n--){
        string s;
        cin >> s;

        cout << solve(s) << '\n';
    }
    return 0;
}

// AC.

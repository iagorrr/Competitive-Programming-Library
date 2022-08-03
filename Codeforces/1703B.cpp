#include <bits/stdc++.h>
using namespace std;
using ll = long long;


ll solve(string s, ll N){
    map<char, bool> c;
    ll ans = 0;
    for(ll i = 0; i < N; ++i){
        if(!c[s[i]]) ans+=2;
        else ans++;
        c[s[i]] = true;
    }

    return ans;
}
int main(){
    ll N;
    cin >> N;

    while(N--){
        ll S;
        cin >> S;

        string s;
        cin >> s;

        cout << solve(s, S) << endl;
    }

    return 0;
}
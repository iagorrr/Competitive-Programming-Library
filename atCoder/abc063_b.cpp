// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;

int main(){ 
    fastio

    string s;
    cin >> s;

    set<char> i;
    for(auto c : s)
        i.insert(c);

    cout << (i.size() != s.size() ? "no" : "yes") << '\n';
    return 0;
}

// AC.

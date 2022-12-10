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

    bool ans = true;
    if(s.size() != 8) ans = false;
    else if(!(s[0] >= 'A' and s[0] <= 'Z'))  ans = false;
    else if(!(s.back() >= 'A' and s.back() <= 'Z'))  ans = false;
    
    for(int i = 1; i < s.size()-1; ++i)
        if(!(s[i] >= '0' and s[i] <= '9')) ans = false;

    if(ans and !(stoi(s.substr(1, 6)) >= 100000 and stoi(s.substr(1, 6)) <= 999999)) ans = false;
    
    cout << (ans ? "Yes" : "No") << '\n';
    return 0;
}

// AC.

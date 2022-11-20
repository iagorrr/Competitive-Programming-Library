// iagorrr ;)
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ll a, b;

    cin >> a >> b;
    
    ll x;
    ll ac =0;
    while(cin >> x){
        ac += x;

        string ans;
        if(!(x%a)) ans += "foo";

        if(!(x%b)) ans += "bar";

        if(!ans.empty()) cout << ans << '\n';
    }
    return 0;
}

// AC.
